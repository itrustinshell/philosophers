/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:51:54 by largenzi          #+#    #+#             */
/*   Updated: 2024/11/09 18:38:15 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	monitor_checkmeal(t_thread_pmt *pmt, int *index, int n_of_phil)
{
	int	i;

	i = *index;
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
		return (0);
	}
	pthread_mutex_unlock(pmt[n_of_phil].mutexmeal);
	return (1);
}

static int	monitor_checkttd(t_thread_pmt *pmt,
	int *index, int n_of_phil, long time)
{
	int	i;

	i = *index;
	pthread_mutex_lock(pmt[n_of_phil].mutexttd);
	if (time > pmt[i].time_to_die)
	{
		pthread_mutex_unlock(pmt[n_of_phil].mutexttd);
		pthread_mutex_lock(pmt[n_of_phil].mutexdeath);
		*pmt[i].someonediedptr = 1;
		pthread_mutex_unlock(pmt[n_of_phil].mutexdeath);
		printf("%s%ld %d %s%s\n", RED, time, pmt[i].id, DIED, RESET);
		return (0);
	}
	pthread_mutex_unlock(pmt[n_of_phil].mutexttd);
	return (1);
}

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
			if (monitor_checkmeal(pmt, &i, n_of_phil) == 0)
				return (NULL);
			pthread_mutex_lock(pmt[n_of_phil].mutextime);
			time = get_time() - pmt[i].last_time_execution;
			pthread_mutex_unlock(pmt[n_of_phil].mutextime);
			if (monitor_checkttd(pmt, &i, n_of_phil, time) == 0)
				return (NULL);
			i++;
		}
	}
	return (NULL);
}
