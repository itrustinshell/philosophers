/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_and_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 22:45:52 by largenzi          #+#    #+#             */
/*   Updated: 2024/07/27 22:45:59 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philosophers_join(pthread_t *philosophers,
	pthread_t monitor, t_input input)
{
	int	i;

	i = -1;
	while (++i < input.n_of_phil)
		pthread_join(philosophers[i], NULL);
	pthread_join(monitor, NULL);
}

void	free_everything(t_input input, t_thread_pmt *pmt_array,
	pthread_t *philo_array)
{
	free(pmt_array[input.n_of_phil].death_check);
	free(pmt_array[input.n_of_phil].someone_is_dead);
	free(pmt_array[input.n_of_phil].write);
	free(pmt_array[input.n_of_phil].time_check);
	free(pmt_array[input.n_of_phil].all_finish_eating);
	free(pmt_array[input.n_of_phil].meals_check);
	free(pmt_array[input.n_of_phil].all_meals_eaten);
	free(pmt_array[input.n_of_phil].finish_for_meals);
	free(pmt_array[input.n_of_phil].forks);
	free(pmt_array);
	free(philo_array);
}
