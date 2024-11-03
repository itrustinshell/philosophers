/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:55:42 by largenzi          #+#    #+#             */
/*   Updated: 2024/07/20 15:45:47 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	milliseconds(struct timeval current_time)
{
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

long	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

void	my_sleep_ms(long time)
{
	long	msstart;

	msstart = get_time();
	while (get_time() - msstart < time)
		usleep(500);
}

void	msg(t_thread_pmt *param, char *message, char *color)
{
	long	time;

	pthread_mutex_lock(param->write);
	time = get_time() - param->start_simulation;
	if (*(param)->someone_is_dead == 1)
	{
		pthread_mutex_unlock(param->write);
		return ;
	}
	time = get_time() - param->start_simulation;
	printf("%s%ld %d %s%s\n", color, time, param->id, message, RESET);
	pthread_mutex_unlock(param->write);
}
