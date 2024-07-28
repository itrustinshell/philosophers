/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_routine.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:47:41 by largenzi          #+#    #+#             */
/*   Updated: 2024/07/28 09:56:07 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eating(t_thread_pmt	*pmt)
{
	msg(pmt, EAT, GREEN);
	pthread_mutex_lock(pmt->time_check);
	pmt->last_time_execution = get_time();
	pthread_mutex_unlock(pmt->time_check);
	usleep(pmt->time_to_eat * 1000);
	pthread_mutex_unlock(&(pmt->forks)[pmt->forkleft]);
	pthread_mutex_unlock(&(pmt->forks)[pmt->forkright]);
}

static void	*routine_with_n_of_meals(void *param)
{
	t_thread_pmt	*pmt;
	int				both_forks_taken;
	int				n_of_meals;

	pmt = (t_thread_pmt *)param;
	n_of_meals = 0;
	while (pmt->state == alive_s && n_of_meals < pmt->n_of_meals)
	{
		if (pmt->id % 2 == 0)
			both_forks_taken = take_forkright_first(pmt);
		else
			both_forks_taken = take_forkleft_first(pmt);
		if (both_forks_taken)
		{
			eating(pmt);
			pthread_mutex_lock(pmt->all_finish_eating);
			if (*(pmt)->finish_for_meals == 1)
			{
				pthread_mutex_unlock(pmt->all_finish_eating);
				return (NULL);
			}
			pthread_mutex_unlock(pmt->all_finish_eating);
			if (++n_of_meals == pmt->n_of_meals)
				break ;
			pthread_mutex_lock(pmt->death_check);
			if (*(pmt)->someone_is_dead == 1)
			{
				pthread_mutex_unlock(pmt->death_check);
				return (NULL);
			}
			pthread_mutex_unlock(pmt->death_check);
		}
		else
			return (NULL);
		msg(pmt, SLEEP, BLUE);
		usleep(pmt->time_to_sleep * 1000);
		msg(param, THINK, YELLOW);
	}
	if (n_of_meals == pmt->n_of_meals)
	{
		pthread_mutex_lock(pmt->meals_check);
		*(pmt)->all_meals_eaten += 1;
		if (*(pmt)->all_meals_eaten == pmt->number_of_philo - 1)
		{
			pthread_mutex_unlock(pmt->meals_check);
			msg(pmt, ALL_EAT, WHITE);
			pthread_mutex_lock(pmt->all_finish_eating);
			*(pmt)->finish_for_meals = 1;
			pthread_mutex_unlock(pmt->all_finish_eating);
			return (NULL);
		}
		pthread_mutex_unlock(pmt->meals_check);
	}
	return (NULL);
}

static void	*routine_without_n_of_meals(void *param)
{
	t_thread_pmt	*pmt;
	int				both_forks;

	pmt = (t_thread_pmt *)param;
	while (1)
	{
		if (pmt->id % 2 == 0)
			both_forks = take_forkright_first(pmt);
		else
			both_forks = take_forkleft_first(pmt);
		if (both_forks)
		{
			eating(pmt);
			pthread_mutex_lock(pmt->death_check);
			if (*(pmt)->someone_is_dead == 1)
			{
				pthread_mutex_unlock(pmt->death_check);
				return (NULL);
			}
			pthread_mutex_unlock(pmt->death_check);
		}
		else
			return (NULL);
		msg(pmt, SLEEP, BLUE);
		usleep(pmt->time_to_sleep * 1000);
		msg(param, THINK, YELLOW);
	}
	return (NULL);
}

/*
	This function determines what routine has to be execute, depending on the
	user'sinput. If the user specifies the number of meals, 
	the corresponding routin
	will be chosen, otherwise the other routine (which doesn't expect to manage
	the number of meals) will be execute
*/
void	start_philosopher_routine(pthread_t *philosophers,
			t_input input, t_thread_pmt *thread_pmt)
{
	int	i;

	i = -1;
	while (++i < input.n_of_phil)
	{
		if (input.n_of_meals <= 0)
			pthread_create(&philosophers[i], NULL,
				routine_without_n_of_meals, (void *)&thread_pmt[i]);
		else
			pthread_create(&philosophers[i], NULL,
				routine_with_n_of_meals, (void *)&thread_pmt[i]);
	}
}
