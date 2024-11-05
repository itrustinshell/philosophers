/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:57:26 by largenzi          #+#    #+#             */
/*   Updated: 2024/11/04 23:50:01 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleeping(t_thread_pmt *param)
{
	msg(param, SLEEP);
	usleep(param->time_to_sleep * 1000);
}

void	thinking(t_thread_pmt *param)
{
	msg(param, THINK);
}

void	eating(t_thread_pmt *param)
{
	pthread_mutex_lock(param->mutextime);
	param->last_time_execution = get_time();
	pthread_mutex_unlock(param->mutextime);
	msg(param, EAT);
	usleep(param->time_to_eat * 1000);
}
