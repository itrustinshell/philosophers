/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:56:37 by largenzi          #+#    #+#             */
/*   Updated: 2024/11/02 22:18:39 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_thread_pmt	*create_pmtarray(int n_of_phil, t_fork *forks_array)
{
	t_thread_pmt	*thread_pmt;

	thread_pmt = (t_thread_pmt *)malloc(n_of_phil * sizeof(t_thread_pmt));
	if (thread_pmt == NULL)
	{
		free(forks_array);
		exit(1);
	}
	return (thread_pmt);
}

static void	pmt_array_init(t_thread_pmt *pmt, t_fork *forks,
		t_input input)
{
	pthread_mutex_t	*death_check;
	pthread_mutex_t	*write;
	pthread_mutex_t	*no_more;
	int				*is_dead;
	int				*no_more_to_print;

	death_check = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(death_check, NULL);
	write = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(write, NULL);
	no_more = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(no_more, NULL);
	is_dead = (int *)malloc(sizeof(int));
	*is_dead = 0;
	no_more_to_print = (int *)malloc(sizeof(int));
	*no_more_to_print = 0;
	initialize_pmt_one(pmt, input, forks, no_more_to_print);
	initialize_pmt_two(pmt, input, is_dead, write);
	initialize_pmt_three(pmt, input, death_check);
	initialize_no_more(pmt, input, no_more);
}

t_thread_pmt	*pmt_generation(t_input input, t_fork *forks_array)
{
	t_thread_pmt	*pmt_array;

	pmt_array = create_pmtarray(input.n_of_phil, forks_array);
	pmt_array_init(pmt_array, forks_array, input);
	return (pmt_array);
}
