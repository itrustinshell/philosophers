/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_malloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:31:47 by largenzi          #+#    #+#             */
/*   Updated: 2024/07/28 10:05:11 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
this function create a malloced array of forks.
each element of the array is a mutex.
*/
pthread_mutex_t	*create_forks_array(int n_of_phil)
{
	pthread_mutex_t	*forks;

	forks = (pthread_mutex_t *)malloc(n_of_phil * sizeof(pthread_mutex_t));
	if (!forks)
		return (0);
	return (forks);
}

/*
this function create a malloced array of parameter.
Each element of the array is a parameter of type struc t_thread_pmt.
These are the parameters of philosphers (see philo.h for the struct)
It means that evry philosphers has its owns set of properties.
Actually you will see in the struct some properties that are pointer.
These pointer point to others common area. 
So that each philosophers, when update one of these properties, they change for others too.
*/
void	create_pmt_array(int n_of_phil, t_thread_pmt	**pmt_array)
{
	*pmt_array = (t_thread_pmt *)malloc((n_of_phil + 1) * sizeof(t_thread_pmt));
	if (!*pmt_array)
		exit(1);
}

/*
this function create the malloced array of phisophers.
Each element of the array is a thread.
*/
void	create_philo_array(t_input input,
				t_thread_pmt *pmt_array, pthread_t **philo_array)
{
	*philo_array = (pthread_t *)malloc((input.n_of_phil)
			* sizeof(pthread_t));
	if (!*philo_array)
	{
		free(pmt_array);
		exit (1);
	}
}
