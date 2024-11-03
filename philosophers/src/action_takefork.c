/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_takefork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:11:55 by largenzi          #+#    #+#             */
/*   Updated: 2024/11/03 22:28:32 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_forkleft_first(t_thread_pmt *pmt)
{
	pthread_mutex_lock(&pmt->forks[pmt->forkleft].forklock);
	//pmt->forks[pmt->forkleft].status = LOCKED;
	msg(pmt, TAKE_FIRST_FORK);
	if (pmt->number_of_philo == 1)
	{
		pthread_mutex_unlock(&pmt->forks[pmt->forkleft].forklock);
		//pmt->forks[pmt->forkleft].status = UNLOCKED;
		pthread_mutex_lock(pmt->mutexdeath);
		*(pmt)->someonediedptr = YES;
		pthread_mutex_unlock(pmt->mutexdeath);
		return (-1);
	}
//	pthread_mutex_lock(&pmt->forks[pmt->forkright].forklock);
//	pmt->forks[pmt->forkright].status = LOCKED;
	//msg(pmt, TAKE_SECOND_FORK);
	eating(pmt);
	//pmt->forks[pmt->forkleft].status = FORK_HAS_RELEASED;
//	pmt->forks[pmt->forkright].status = FORK_HAS_RELEASED;
	//pthread_mutex_unlock(&(pmt->forks)[pmt->forkright].forklock);
	pthread_mutex_unlock(&(pmt->forks)[pmt->forkleft].forklock);
	return (1);
}

int	take_forkright_first(t_thread_pmt *pmt)
{
	(void)pmt;
	//usleep(1);
	//pthread_mutex_lock(&pmt->forks[pmt->forkright].forklock);
	//pmt->forks[pmt->forkright].status = LOCKED;
	/*msg(pmt, TAKE_FIRST_FORK);
	if (pmt->number_of_philo == 1)
	{
		pthread_mutex_unlock(&pmt->forks[pmt->forkright].forklock);
		pmt->forks[pmt->forkright].status = UNLOCKED;
		pthread_mutex_lock(pmt->mutexdeath);
		*(pmt)->someonediedptr = YES;
		pthread_mutex_unlock(pmt->mutexdeath);
		return (-1);
	}
	pthread_mutex_lock(&pmt->forks[pmt->forkleft].forklock);
	pmt->forks[pmt->forkleft].status = LOCKED;
	msg(pmt, TAKE_SECOND_FORK);
	eating(pmt);
	pmt->forks[pmt->forkleft].status = FORK_HAS_RELEASED;
	pmt->forks[pmt->forkright].status = FORK_HAS_RELEASED;
	pthread_mutex_unlock(&(pmt->forks)[pmt->forkleft].forklock);
	pthread_mutex_unlock(&(pmt->forks)[pmt->forkright].forklock);
*/
	return (1);
}


/*
void	take_forkleft_first(t_thread_pmt *pmt)
{
	if (pmt->forks[pmt->forkleft].status == UNLOCKED)
	{
		pthread_mutex_lock(&pmt->forks[pmt->forkleft].forklock);
		pmt->forks[pmt->forkleft].status = LOCKED;
		msg(pmt, TAKE_FIRST_FORK);
		if (pmt->number_of_philo > 1)
		{
			if (pmt->forks[pmt->forkright].status == UNLOCKED)
			{
				pthread_mutex_lock(&pmt->forks[pmt->forkright].forklock);
				pmt->forks[pmt->forkright].status = LOCKED;
				msg(pmt, TAKE_SECOND_FORK);
			}
			else
			{
				pmt->forks[pmt->forkleft].status = UNLOCKED;
				pthread_mutex_unlock(&pmt->forks[pmt->forkleft].forklock);
			}
		}
		else
		{
			pmt->forks[pmt->forkleft].status = UNLOCKED;
			pthread_mutex_unlock(&pmt->forks[pmt->forkleft].forklock);
			pthread_mutex_lock(pmt->mutexdeath);
			*(pmt)->someonediedptr = YES;
			pthread_mutex_unlock(pmt->mutexdeath);
		}
	}
	
}

void	take_forkright_first(t_thread_pmt *pmt)
{
	if (pmt->forks[pmt->forkright].status == UNLOCKED)
	{
		pthread_mutex_lock(&pmt->forks[pmt->forkright].forklock);
		pmt->forks[pmt->forkright].status = LOCKED;
		msg(pmt, TAKE_FIRST_FORK);
		if (pmt->number_of_philo > 1)
		{
			if (pmt->forks[pmt->forkleft].status == UNLOCKED)
			{
				pthread_mutex_lock(&pmt->forks[pmt->forkleft].forklock);
				pmt->forks[pmt->forkleft].status = LOCKED;
				msg(pmt, TAKE_SECOND_FORK);
				eating(pmt);
				return;
				//		thinking(pmt);
		//		sleeping(pmt);

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
			pthread_mutex_unlock(&pmt->forks[pmt->forkright].forklock);
			pthread_mutex_lock(pmt->mutexdeath);
			*(pmt)->someonediedptr = YES;
			pthread_mutex_unlock(pmt->mutexdeath);
		}
	}
}

*/
