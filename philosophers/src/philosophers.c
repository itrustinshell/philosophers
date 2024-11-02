/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:55:32 by largenzi          #+#    #+#             */
/*   Updated: 2024/11/02 17:56:21 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	chose_routine(t_input input, pthread_t *philosophers,
			t_thread_pmt *thread_pmt)
{
	int	i;

	i = 0;
	if (input.n_of_meals <= 0)
	{
		while (i < input.n_of_phil)
		{
			pthread_create(&philosophers[i], NULL,
				routine_without_n_of_meals, (void *)&thread_pmt[i]);
			i++;
		}
	}
	else
	{
		while (i < input.n_of_phil)
		{
			pthread_create(&philosophers[i], NULL,
				routine_with_n_of_meals, (void *)&thread_pmt[i]);
			i++;
		}
	}
}

pthread_t	*create_philosophers(t_input input, t_fork *forks_array,
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

pthread_t	*philosophers_generation(t_input input, t_fork *forks_array,
				t_thread_pmt *pmt_array)
{
	pthread_t	*philosophers;

	philosophers = create_philosophers(input, forks_array, pmt_array);
	chose_routine(input, philosophers, pmt_array);
	return (philosophers);
}
