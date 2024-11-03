/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:55:42 by largenzi          #+#    #+#             */
/*   Updated: 2024/11/03 10:25:56 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

void	msg(t_thread_pmt *param, char *message)
{
	long	time;

	pthread_mutex_lock(param->mutexdeath);
	if (*(param)->someonediedptr == YES)
	{
		pthread_mutex_unlock(param->mutexdeath);
		return ;
	}
	pthread_mutex_unlock(param->mutexdeath);
	time = get_time() - param->start_simulation;
	pthread_mutex_lock(param->mutexwrite);
	printf("%ld %d %s\n", time, param->id, message);
	pthread_mutex_unlock(param->mutexwrite);
}
