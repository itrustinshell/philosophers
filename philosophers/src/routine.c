/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:47:41 by largenzi          #+#    #+#             */
/*   Updated: 2024/11/03 10:21:29 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine_with_n_of_meals(void *param)
{
	t_thread_pmt	*pmt;
	int				n_of_meals;

	pmt = (t_thread_pmt *)param;
	n_of_meals = 0;
	while (n_of_meals < pmt->n_of_meals)
	{
		if (pmt->id % 2 == EVEN)
			take_forkright_first(pmt);
		else
			take_forkleft_first(pmt);
		eating(pmt);
		pthread_mutex_lock(pmt->mutexdeath);
		if (*(pmt)->someonediedptr == YES)
		{
			pthread_mutex_unlock(pmt->mutexdeath);
			break ;
		}
		pthread_mutex_unlock(pmt->mutexdeath);
		sleeping(pmt);
		thinking(pmt);
		n_of_meals++;
	}
	//if (n_of_meals >= pmt->n_of_meals)
	//	pmt->all_meals_eaten = YES;
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
		eating(pmt);
		pthread_mutex_lock(pmt->mutexdeath);
		if (*(pmt)->someonediedptr == YES)
		{
			pthread_mutex_unlock(pmt->mutexdeath);
			break ;
		}
		pthread_mutex_unlock(pmt->mutexdeath);
		sleeping(pmt);
		thinking(pmt);
	}
	return (NULL);
}
