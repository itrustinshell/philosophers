/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:55:42 by largenzi          #+#    #+#             */
/*   Updated: 2024/11/03 18:31:28 by largenzi         ###   ########.fr       */
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
	int a;
	int b;

	a = pthread_mutex_lock(param->mutexwrite);
	b = pthread_mutex_lock(param->mutexdeath);
	if (*(param)->someonediedptr == YES)
	{
		if (a == 0)
			a = pthread_mutex_unlock(param->mutexwrite);
		if (b == 0)
			b = pthread_mutex_unlock(param->mutexdeath);
		return ;
	}
	if (b == 0)
		b = pthread_mutex_unlock(param->mutexdeath);
	time = get_time() - param->start_simulation;
	printf("%ld %d %s\n", time, param->id, message);
	if (a == 0)
		a = pthread_mutex_unlock(param->mutexwrite);
}
