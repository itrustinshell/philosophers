/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:51:54 by largenzi          #+#    #+#             */
/*   Updated: 2024/11/03 20:16:40 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/*
int	check_monitor(int another_philosopher_finish_to_eat, t_thread_pmt	*pmt)
{
	int		i;
	long	time;

	(void)another_philosopher_finish_to_eat;
	while (1)
	{
		i = 0;
		while (i < pmt[0].number_of_philo)
		{
			time = get_time() - pmt[i].last_time_execution;
			if (!print_if_die(pmt, i, time))
				return (0);
			i++;
		}
	}
	return (1);
}

void	*monitor_routine(void *param)
{
	t_thread_pmt	*pmt;
	int				another_philosopher_finish_to_eat;

	another_philosopher_finish_to_eat = 0;
	pmt = (t_thread_pmt *)param;
	if (!check_monitor(another_philosopher_finish_to_eat, pmt))
		return (NULL);
	return (NULL);
}

*/

int	check_monitor(int another_philosopher_finish_to_eat, t_thread_pmt *pmt)
{
	int		i;
	long	time;

	(void)another_philosopher_finish_to_eat;
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
			if (time > pmt[i].time_to_die)
			{
				pthread_mutex_lock(pmt->mutexdeath);
				*pmt[i].someonediedptr = 1;
				pthread_mutex_unlock(pmt->mutexdeath);
				return(0);
			}
			i++;
		}
	}
	return (1);
}

void	*monitor_routine(void *param)
{
	t_thread_pmt	*pmt;
	int				another_philosopher_finish_to_eat;

	another_philosopher_finish_to_eat = 0;
	pmt = (t_thread_pmt *)param;
	if (!check_monitor(another_philosopher_finish_to_eat, pmt))
		return (NULL);
	return (NULL);
}

