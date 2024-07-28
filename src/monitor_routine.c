/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:47:41 by largenzi          #+#    #+#             */
/*   Updated: 2024/07/27 22:42:43 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor_routine(void *param)
{
	t_thread_pmt	*pmt;
	int				i;
	long			time_range;
	long			time_to_die;
	int				n_of_phil;

	pmt = (t_thread_pmt *)param;
	n_of_phil = pmt[pmt->number_of_philo].number_of_philo;
	time_to_die = pmt[n_of_phil].time_to_die;
	while (1)
	{
		i = -1;
		while (++i < n_of_phil)
		{
			pthread_mutex_lock(pmt[n_of_phil].time_check);
			time_range = get_time() - pmt[i].last_time_execution;
			pthread_mutex_unlock(pmt[n_of_phil].time_check);
			if (time_range > time_to_die)
			{
				msg(&pmt[i], DIED, RED);
				pthread_mutex_lock(pmt[n_of_phil].death_check);
				*pmt[n_of_phil].someone_is_dead = 1;
				pthread_mutex_unlock(pmt[n_of_phil].death_check);
				return (NULL);
			}
			usleep(1000);
		}
	}
	return (NULL);
}
