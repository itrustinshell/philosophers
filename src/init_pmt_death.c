/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pmt_death.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:47:45 by largenzi          #+#    #+#             */
/*   Updated: 2024/07/28 10:05:09 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*mutex to create a critical region for someon_is_dead*/
static void	init_pmt_mutex_check_death(t_thread_pmt *pmt, t_input input)
{
	int				i;
	pthread_mutex_t	*death_check_malloced;

	death_check_malloced = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(death_check_malloced, NULL);
	i = -1;
	while (++i <= input.n_of_phil)
		pmt[i].death_check = death_check_malloced;
}

/*if on philosphers died, so someoe died*/
static void	init_pmt_someone_is_dead(t_thread_pmt *pmt, t_input input)
{
	int		i;
	int		*is_dead_malloced;

	is_dead_malloced = (int *)malloc(sizeof(int));
	*is_dead_malloced = 0;
	i = -1;
	while (++i <= input.n_of_phil)
	{
		pthread_mutex_lock(pmt[i].death_check);
		pmt[i].someone_is_dead = is_dead_malloced;
		pthread_mutex_unlock(pmt[i].death_check);
	}
}

/*mutex to create a critical region for last_time_execution*/
static void	init_pmt_mutex_time_check(t_thread_pmt *pmt, t_input input)
{
	int					i;
	pthread_mutex_t		*time_check_malloced;

	time_check_malloced = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(time_check_malloced, NULL);
	i = -1;
	while (++i <= input.n_of_phil)
		pmt[i].time_check = time_check_malloced;
}

/*this function groups together the previous static funtìction in this file*/
void	pmt_array_init_death_management(t_thread_pmt *pmt, t_input input)
{
	init_pmt_mutex_check_death(pmt, input);
	init_pmt_someone_is_dead(pmt, input);
	init_pmt_mutex_time_check(pmt, input);
}
