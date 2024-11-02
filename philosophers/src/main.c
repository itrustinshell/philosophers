/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:42:09 by largenzi          #+#    #+#             */
/*   Updated: 2024/11/02 22:22:05 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_input			input;
	t_fork			*forks_array;
	pthread_t		*philosophers;
	pthread_t		monitor;
	t_thread_pmt	*pmt_array;

	input_validation(argc, argv);
	input_init(&input, argv);
	forks_array = forks_generation(input);
	pmt_array = pmt_generation(input, forks_array);
	philosophers = philosophers_generation(input, forks_array, pmt_array);
	pthread_create(&monitor, NULL, monitor_routine, (void *)&pmt_array[0]);
	threads_join(philosophers, monitor, input);
	last_print(pmt_array, &input);
	free_everything(forks_array, pmt_array, philosophers);
	if (argc == 6 && (input.someone_is_dead != 1
			|| input.no_more_to_print != 1))
		printf("All philosophers have eaten the expected meals!\n");
	return (0);
}

//TODO: resolve race conditions...nomore