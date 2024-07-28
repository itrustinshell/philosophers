/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:11:55 by largenzi          #+#    #+#             */
/*   Updated: 2024/07/27 23:07:54 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_forkleft_first(t_thread_pmt *pmt)
{
	pthread_mutex_lock(&pmt->forks[pmt->forkleft]);
	msg(pmt, TAKE_FORK, CYAN);
	if (pmt->number_of_philo == 1)
	{
		pthread_mutex_unlock(&pmt->forks[pmt->forkleft]);
		return (0);
	}
	pthread_mutex_lock(&pmt->forks[pmt->forkright]);
	msg(pmt, TAKE_FORK, CYAN);
	return (1);
}

int	take_forkright_first(t_thread_pmt *pmt)
{
	usleep(1);
	pthread_mutex_lock(&pmt->forks[pmt->forkright]);
	msg(pmt, TAKE_FORK, CYAN);
	pthread_mutex_lock(&pmt->forks[pmt->forkleft]);
	msg(pmt, TAKE_FORK, CYAN);
	return (1);
}
