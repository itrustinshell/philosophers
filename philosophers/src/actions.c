/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:57:26 by largenzi          #+#    #+#             */
/*   Updated: 2024/11/02 17:49:43 by largenzi         ###   ########.fr       */
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
	param->last_time_execution = get_time();
	msg(param, EAT);
	usleep(param->time_to_eat * 1000);
	pthread_mutex_unlock(&(param->forks)[param->forkleft].forklock);
	param->forks[param->forkleft].status = FORK_HAS_RELEASED;
	pthread_mutex_unlock(&(param->forks)[param->forkright].forklock);
	param->forks[param->forkright].status = FORK_HAS_RELEASED;
}
