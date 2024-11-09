/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:51:54 by largenzi          #+#    #+#             */
/*   Updated: 2024/11/09 13:41:11 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor_routine(void *param)
{
	t_thread_pmt	*pmt;
	long			time;
	int				i;
	int				n_of_phil;

	pmt = (t_thread_pmt *)param;
	n_of_phil = pmt[0].number_of_philo;
	i = 0;
	while (1)
	{
		i = 0;
		while (i < n_of_phil)
		{
			pthread_mutex_lock(pmt[n_of_phil].mutexmeal);
			if (*pmt[n_of_phil].philo_who_finished_to_eat == n_of_phil - 1)
			{
				pthread_mutex_unlock(pmt[n_of_phil].mutexmeal);
				if (n_of_phil != 1)
					printf("All meals eaten\n");
				else
					printf("%s%ld %d %s%s\n", RED,
						get_time() - pmt[i].start_simulation,
						pmt[i].id, DIED, RESET);
				return (NULL);
			}
			pthread_mutex_unlock(pmt[n_of_phil].mutexmeal);
			pthread_mutex_lock(pmt[n_of_phil].mutextime);
			time = get_time() - pmt[i].last_time_execution;
			pthread_mutex_unlock(pmt[n_of_phil].mutextime);
			pthread_mutex_lock(pmt[n_of_phil].mutexttd);
			if (time > pmt[i].time_to_die)
			{
				pthread_mutex_unlock(pmt[n_of_phil].mutexttd);
				pthread_mutex_lock(pmt[n_of_phil].mutexdeath);
				*pmt[i].someonediedptr = 1;
				pthread_mutex_unlock(pmt[n_of_phil].mutexdeath);
				printf("%s%ld %d %s%s\n", RED, time, pmt[i].id, DIED, RESET);
				return (NULL);
			}
			pthread_mutex_unlock(pmt[n_of_phil].mutexttd);
			i++;
		}
	}
	return (NULL);
}
