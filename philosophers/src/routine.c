/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:47:41 by largenzi          #+#    #+#             */
/*   Updated: 2024/11/09 19:03:12 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	chose_firstfork(t_thread_pmt *pmt)
{
	if (pmt->id % 2 == EVEN)
		take_forkright_first(pmt);
	else
		take_forkleft_first(pmt);
}

static int	philo_checkmeal(int n_of_meals, t_thread_pmt *pmt)
{
	if (n_of_meals == pmt->n_of_meals)
	{
		pthread_mutex_lock(pmt->mutexmeal);
		*(pmt)->philo_who_finished_to_eat += 1;
		pthread_mutex_unlock(pmt->mutexmeal);
		return (0);
	}
	return (1);
}

void	*routine_with_n_of_meals(void *param)
{
	t_thread_pmt	*pmt;
	int				n_of_meals;

	pmt = (t_thread_pmt *)param;
	n_of_meals = 0;
	while (n_of_meals < pmt->n_of_meals)
	{
		chose_firstfork(pmt);
		n_of_meals++;
		if (philo_checkmeal(n_of_meals, pmt) == 0)
			return (NULL);
		pthread_mutex_lock(pmt->mutexdeath);
		if (*(pmt)->someonediedptr == YES)
		{
			pthread_mutex_unlock(pmt->mutexdeath);
			return (NULL);
		}
		pthread_mutex_unlock(pmt->mutexdeath);
		sleeping(pmt);
		thinking(pmt);
	}
	return (NULL);
}

void	*routine_without_n_of_meals(void *param)
{
	t_thread_pmt	*pmt;

	pmt = (t_thread_pmt *)param;
	while (1)
	{
		if (pmt->id % 2 == EVEN)
			take_forkright_first(pmt);
		else
			take_forkleft_first(pmt);
		pthread_mutex_lock(pmt->mutexdeath);
		if (*(pmt)->someonediedptr == YES)
		{
			pthread_mutex_unlock(pmt->mutexdeath);
			return (NULL);
		}
		pthread_mutex_unlock(pmt->mutexdeath);
		sleeping(pmt);
		thinking(pmt);
	}
	return (NULL);
}
