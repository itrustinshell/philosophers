/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_takefork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:11:55 by largenzi          #+#    #+#             */
/*   Updated: 2024/11/09 15:35:38 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_forkleft_first(t_thread_pmt *pmt)
{
	usleep(121);
	pthread_mutex_lock(&pmt->forks[pmt->forkleft].forklock);
	if (pmt->number_of_philo == 1)
	{
		pthread_mutex_unlock(&pmt->forks[pmt->forkleft].forklock);
		pthread_mutex_lock(pmt->mutexdeath);
		*(pmt)->someonediedptr = YES;
		pthread_mutex_unlock(pmt->mutexdeath);
		return (-1);
	}
	msg(pmt, TAKE_FIRST_FORK);
	pthread_mutex_lock(&pmt->forks[pmt->forkright].forklock);
	msg(pmt, TAKE_SECOND_FORK);
	eating(pmt);
	pthread_mutex_unlock(&pmt->forks[pmt->forkright].forklock);
	pthread_mutex_unlock(&pmt->forks[pmt->forkleft].forklock);
	return (1);
}

int	take_forkright_first(t_thread_pmt *pmt)
{
	pthread_mutex_lock(&pmt->forks[pmt->forkright].forklock);
/*	if (pmt->number_of_philo == 1)
	{
		printf("weeeeee\n");
		pthread_mutex_unlock(&pmt->forks[pmt->forkright].forklock);
		pthread_mutex_lock(pmt->mutexdeath);
		*(pmt)->someonediedptr = YES;
		pthread_mutex_unlock(pmt->mutexdeath);
		return (-1);
	}*/
	msg(pmt, TAKE_FIRST_FORK);
	pthread_mutex_lock(&pmt->forks[pmt->forkleft].forklock);
	msg(pmt, TAKE_SECOND_FORK);
	eating(pmt);
	pthread_mutex_unlock(&pmt->forks[pmt->forkleft].forklock);
	pthread_mutex_unlock(&pmt->forks[pmt->forkright].forklock);
	return (1);
}
