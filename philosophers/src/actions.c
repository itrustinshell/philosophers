/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:47:41 by largenzi          #+#    #+#             */
/*   Updated: 2024/11/02 12:02:58 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine_with_n_of_meals(void *param)
{
	t_thread_pmt	*pmt;
	int				both_forks;
	int				n_of_meals;

	pmt = (t_thread_pmt *)param;
	n_of_meals = 0;
	while (*(pmt)->someone_is_dead == 0 && (n_of_meals < pmt->n_of_meals))
	{
		if (pmt->id % 2 == 0)
			both_forks = take_forkright_first(pmt);
		else
			both_forks = take_forkleft_first(pmt);
		if (eat_sleep_think(pmt, both_forks) == 0)
			return (NULL);
		n_of_meals++;
	}
	if (n_of_meals >= pmt->n_of_meals)
		pmt->all_meals_eaten = 1;
	return (NULL);
}

void	*routine_without_n_of_meals(void *param)
{
	t_thread_pmt	*pmt;
//	int				both_forks;

	pmt = (t_thread_pmt *)param;
	while (1)
	{
		if (pmt->id % 2 == EVEN)
			take_forkright_first(pmt);
		else
			take_forkleft_first(pmt);
	//in tkae fork action there are mutex...so at the end the part of the following code will be executed only when all witing time for m mutex are resolved and both forks are taken.
		eating(pmt);
		if (*(pmt)->someone_is_dead == YES)
			break;
		sleeping(pmt);
		thinking(pmt);
	}
	return (NULL);
}

int	check_monitor(int another_philosopher_finish_to_eat, t_thread_pmt	*pmt)
{
	int		i;
	long	time;

	i = 0;
	while (1)
	{
		if (another_philosopher_finish_to_eat == pmt[0].number_of_philo)
			break ;
		i = 0;
		while (i < pmt[0].number_of_philo)
		{
			if (another_philosopher_finish_to_eat == pmt[0].number_of_philo)
				break ;
			if (pmt[i].all_meals_eaten == 1)
			{
				i++;
				another_philosopher_finish_to_eat++;
				continue ;
			}
			time = get_time() - pmt[i].last_time_execution;
			if (!print_if_die(pmt, i, time))
				return (0);
			i++;
		}
	}
	return (1);
}

//CIAO



void	*monitor_routine(void *param)
{
	t_thread_pmt	*pmt;
	int				another_philosopher_finish_to_eat;

	another_philosopher_finish_to_eat = 0;
	pmt = (t_thread_pmt *)param;
	if (!check_monitor(another_philosopher_finish_to_eat, pmt))
		return (NULL);
	return (NULL);
}

