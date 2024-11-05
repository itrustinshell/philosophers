/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:51:54 by largenzi          #+#    #+#             */
/*   Updated: 2024/11/05 00:01:36 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/*
int	check_monitor(int another_philosopher_finish_to_eat, t_thread_pmt	*pmt)
{
	int		i;
	long	time;

	i = 0;
	while (1)
	{
		if (another_philosopher_finish_to_eat == pmt[0].number_of_philo)
			break ;
		i = 0;
		while (i < pmt[0].number_of_philo)
		{
			if (another_philosopher_finish_to_eat == pmt[0].number_of_philo)
				break ;
			if (pmt[i].all_meals_eaten == 1)
			{
				i++;
				another_philosopher_finish_to_eat++;
				continue ;
			}
			time = get_time() - pmt[i].last_time_execution;
			if (!print_if_die(pmt, i, time))
				return (0);
			i++;
		}
	}
	return 1;
}
*/
void	*monitor_routine(void *param)
{
	t_thread_pmt	*pmt;
//	int				another_philosopher_finish_to_eat;
	long			time;
	int				i;

	int		n_of_phil;
//	another_philosopher_finish_to_eat = 0;
	pmt = (t_thread_pmt *)param;
	
	n_of_phil = pmt[0].number_of_philo;
	i = 0;
	while (1)
	{
		/*
		if (another_philosopher_finish_to_eat == pmt[0].number_of_philo)
			break ;
		*/
		i = 0;
		while (i < n_of_phil)
		{
		/*	if (another_philosopher_finish_to_eat == pmt[0].number_of_philo)
				break ;
			if (pmt[i].all_meals_eaten == 1)
			{
				i++;
				another_philosopher_finish_to_eat++;
				continue ;
			}
		*/
			if (pthread_mutex_lock(pmt[0].mutextime) != 0)
			{	printf("mutex not active\n");
			}
			time = get_time() - pmt[i].last_time_execution;
			pthread_mutex_unlock(pmt[0].mutextime);
			pthread_mutex_lock(pmt->mutexttd);
			if (time > pmt[i].time_to_die)
			{
				pthread_mutex_unlock(pmt->mutexttd);

			//	pthread_mutex_lock(pmt[i].mutexfinishprint);
			//	*pmt[i].finishprintptr = 1;
			//	pthread_mutex_unlock(pmt[i].mutexfinishprint);
				if (pthread_mutex_lock(pmt[i].mutexdeath)!=0)
				{
					printf("hei mutex not locked!\n");
				}
				printf("someone will die soon!\n");
				*pmt[i].someonediedptr = 1;
				printf("someone died\n");
				pthread_mutex_unlock(pmt[i].mutexdeath);
			/*	printf("%s%ld %d %s%s\n", RED,
				get_time() - pmt[i].start_simulation,
				pmt[i].id, DIED, RESET);
			*/
				return NULL;
			}
			pthread_mutex_unlock(pmt->mutexttd);
			i++;
		}
	}
	return (NULL);
}

