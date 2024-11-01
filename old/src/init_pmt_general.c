/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pmt_general.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:50:33 by largenzi          #+#    #+#             */
/*   Updated: 2024/07/27 22:40:40 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_pmt_info(t_thread_pmt *pmt, t_input input)
{
	int		i;

	i = -1;
	while (++i <= input.n_of_phil)
	{
		pmt[i].id = i + 1;
		pmt[i].state = alive_s;
		pmt[i].number_of_philo = input.n_of_phil;
		pmt[i].n_of_meals = input.n_of_meals;
		pmt[i].all_meals_eaten = 0;
	}
}

/*
this function set fork-left and fork-right for each philo.
The functions receives the malloced array of forks.
This means that every philo can see the same array of forks.
Then the functions set fork-right and fork-left for each philo.
*/
static void	init_pmt_forks(t_thread_pmt *pmt, t_input input)
{
	int				i;
	pthread_mutex_t	*forks_array_malloced;

	forks_array_malloced = (pthread_mutex_t *)malloc(input.n_of_phil
			* sizeof(pthread_mutex_t));
	i = -1;
	while (++i < input.n_of_phil)
		pthread_mutex_init(&forks_array_malloced[i], NULL);
	i = -1;
	while (++i <= input.n_of_phil)
	{
		pmt[i].forks = forks_array_malloced;
		pmt[i].forkleft = i;
		pmt[i].forkright = ((i + 1) % input.n_of_phil);
	}
}

/*
this functions set al stuff regarding time.
start_simulation and last_time_execution at the begining are equals.
Then in the code, while the philo keep on eating, the lat_time_execution updates!
*/
static void	init_pmt_mutex_write(t_thread_pmt *pmt, t_input input)
{
	int				i;
	pthread_mutex_t	*write_malloced;

	write_malloced = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(write_malloced, NULL);
	i = -1;
	while (++i <= input.n_of_phil)
		pmt[i].write = write_malloced;
}

static void	init_pmt_time(t_thread_pmt *pmt, t_input input)
{
	int		i;
	long	start_simulation;

	start_simulation = get_time();
	i = -1;
	while (++i <= input.n_of_phil)
	{
		pmt[i].start_simulation = start_simulation;
		pmt[i].last_time_execution = start_simulation;
		pmt[i].time_to_die = input.time_to_die;
		pmt[i].time_to_eat = input.time_to_eat;
		pmt[i].time_to_sleep = input.time_to_sleep;
	}
}

void	pmt_array_init_general(t_thread_pmt *pmt, t_input input)
{
	init_pmt_info(pmt, input);
	init_pmt_forks(pmt, input);
	init_pmt_mutex_write(pmt, input);
	init_pmt_time(pmt, input);
}
