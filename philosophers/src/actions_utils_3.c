/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:57:26 by largenzi          #+#    #+#             */
/*   Updated: 2024/11/02 13:09:27 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//my_sleep_ms(param->time_to_sleep);
void	sleeping(t_thread_pmt *param)
{
	msg(param, SLEEP, BLUE);
	usleep(param->time_to_sleep * 1000);
}

void	thinking(t_thread_pmt *param)
{
	msg(param, THINK, YELLOW);
}

void	eating(t_thread_pmt *param)
{
//	long	time_since_last_eat;

	param->last_time_execution = get_time();
	msg(param, EAT, GREEN);
	usleep(param->time_to_eat * 1000);
	pthread_mutex_unlock(&(param->forks)[param->forkleft].forklock);
	pthread_mutex_unlock(&(param->forks)[param->forkright].forklock);
}

int	eat_sleep_think(t_thread_pmt	*pmt, int both_forks)
{
	if (both_forks == 0)
	{
		eating(pmt);
		if (*(pmt)->someone_is_dead == 1)
			return (0);
		sleeping(pmt);
		thinking(pmt);
	}
	else
		return (0);
	return (1);
}
