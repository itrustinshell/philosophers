/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_takefork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:11:55 by largenzi          #+#    #+#             */
/*   Updated: 2024/11/02 21:42:36 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forkleft_first(t_thread_pmt *pmt)
{
	pthread_mutex_lock(&pmt->forks[pmt->forkleft].forklock);
	pmt->forks[pmt->forkleft].status = LOCKED;
	msg(pmt, TAKE_FORK);
	if (pmt->number_of_philo == 1)
	{
		pthread_mutex_unlock(&pmt->forks[pmt->forkleft].forklock);
		pmt->forks[pmt->forkleft].status = UNLOCKED;
		pthread_mutex_lock(pmt->death_check);
		*(pmt)->someone_is_dead = YES;
		pthread_mutex_unlock(pmt->death_check);
		return ;
	}
	pthread_mutex_lock(&pmt->forks[pmt->forkright].forklock);
	pmt->forks[pmt->forkright].status = LOCKED;
	msg(pmt, TAKE_FORK);
}

void	take_forkright_first(t_thread_pmt *pmt)
{
	if (pmt->forks[pmt->forkright].status == UNLOCKED)
	{
		pthread_mutex_lock(&pmt->forks[pmt->forkright].forklock);
		pmt->forks[pmt->forkright].status = LOCKED;
		msg(pmt, TAKE_FORK);
		if (pmt->number_of_philo > 1)
		{
			if (pmt->forks[pmt->forkleft].status == UNLOCKED)
			{
				pthread_mutex_lock(&pmt->forks[pmt->forkleft].forklock);
				pmt->forks[pmt->forkleft].status = LOCKED;
				msg(pmt, TAKE_FORK);
			}
			else
			{
				pthread_mutex_unlock(&pmt->forks[pmt->forkright].forklock);
				pmt->forks[pmt->forkright].status = UNLOCKED;
			}
		}
		else
		{
			pmt->forks[pmt->forkright].status = UNLOCKED;
			pthread_mutex_lock(pmt->death_check);
			*(pmt)->someone_is_dead = YES;
			pthread_mutex_unlock(pmt->death_check);
		}
	}
}
