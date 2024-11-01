/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:42:09 by largenzi          #+#    #+#             */
/*   Updated: 2024/07/27 22:50:18 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_input			input;
	pthread_t		*philo_array;
	pthread_t		monitor;
	t_thread_pmt	*pmt_array;

	input_validation_and_init(argc, argv, &input);
	create_pmt_array(input.n_of_phil, &pmt_array);
	pmt_array_init(pmt_array, input);
	create_philo_array(input, pmt_array, &philo_array);
	pthread_create(&monitor, NULL, monitor_routine, (void *)pmt_array);
	start_philosopher_routine(philo_array, input, pmt_array);
	philosophers_join(philo_array, monitor, input);
	free_everything(input, pmt_array, philo_array);
	return (0);
}
