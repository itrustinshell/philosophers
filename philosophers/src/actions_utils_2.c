/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:11:55 by largenzi          #+#    #+#             */
/*   Updated: 2024/11/02 11:34:06 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_forkleft_first(t_thread_pmt *pmt)
{
	if (pthread_mutex_lock(&pmt->forks[pmt->forkleft]) == LOCKED)
	{
		msg(pmt, TAKE_FORK, CYAN);
		if (pmt->number_of_philo == 1) // se c´é un solo filosofo
		{
			pthread_mutex_unlock(&pmt->forks[pmt->forkleft]);
			*(pmt)->someone_is_dead = 1;
			return (-1);
		}
		if (pthread_mutex_lock(&pmt->forks[pmt->forkright]) == LOCKED)
		{
			msg(pmt, TAKE_FORK, CYAN);
			return (0);
		}
		else
		{
			pthread_mutex_unlock(&pmt->forks[pmt->forkleft]);
			return (UNLOCKED);
		}
	}
	return (UNLOCKED);
}

int	take_forkright_first(t_thread_pmt *pmt)
{
	int	forkleft;
	int	forkright;

	usleep(1);
	forkright = pthread_mutex_lock(&pmt->forks[pmt->forkright]);
	if (forkright == 0)
	{
		msg(pmt, TAKE_FORK, CYAN);
		forkleft = pthread_mutex_lock(&pmt->forks[pmt->forkleft]);
		if (forkleft == 0)
		{
			msg(pmt, TAKE_FORK, CYAN);
			return (0);
		}
		else
		{
			pthread_mutex_unlock(&pmt->forks[pmt->forkright]);
			return (-1);
		}
	}
	return (-1);
}
