/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:39:39 by largenzi          #+#    #+#             */
/*   Updated: 2024/07/20 16:47:29 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	forks_array_init(pthread_mutex_t *forks, int n_of_phil)
{
	int	i;

	i = 0;
	while (i < n_of_phil)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	pmt_array_init(t_thread_pmt *pmt, pthread_mutex_t *forks,
		t_input input)
{
	pthread_mutex_t	*death_check;
	pthread_mutex_t	*write;
	int				*is_dead;
	int				*no_more_to_print;

	death_check = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(death_check, NULL);
	write = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(write, NULL);
	is_dead = (int *)malloc(sizeof(int));
	*is_dead = 0;
	no_more_to_print = (int *)malloc(sizeof(int));
	*no_more_to_print = 0;
	initialize_pmt_one(pmt, input, forks, no_more_to_print);
	initialize_pmt_two(pmt, input, is_dead, write);
	initialize_pmt_three(pmt, input, death_check);
}

void	philosophers_init(pthread_t *philosophers, t_input input,
		void*(*f)(void *), t_thread_pmt *thread_pmt)
{
	int	i;

	i = 0;
	while (i < input.n_of_phil)
	{
		if (input.n_of_meals <= 0)
			pthread_create(&philosophers[i], NULL,
				routine_without_n_of_meals, (void *)&thread_pmt[i]);
		else
			pthread_create(&philosophers[i], NULL,
				routine_with_n_of_meals, (void *)&thread_pmt[i]);
		i++;
	}
}

void	validation_and_init(int argc, char **argv, t_input *input)
{
	input_validation(argc, argv);
	input_init(input, argv);
}
