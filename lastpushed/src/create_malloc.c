/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_malloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:31:47 by largenzi          #+#    #+#             */
/*   Updated: 2024/07/06 18:41:21 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	*create_forks_array(int n_of_phil)
{
	pthread_mutex_t	*forks;

	forks = (pthread_mutex_t *)malloc(n_of_phil * sizeof(pthread_mutex_t));
	if (!forks)
		return (0);
	return (forks);
}

t_thread_pmt	*create_pmt_array(int n_of_phil, pthread_mutex_t *forks_array)
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

pthread_t	*create_philosophers(t_input input, pthread_mutex_t *forks_array,
				t_thread_pmt *pmt_array)
{
	pthread_t	*philosophers;

	philosophers = (pthread_t *)malloc(input.n_of_phil
			* sizeof(pthread_t));
	if (!philosophers)
	{
		free(forks_array);
		free(pmt_array);
		exit (1);
	}
	return (philosophers);
}
