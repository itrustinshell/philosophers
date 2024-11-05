/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:42:09 by largenzi          #+#    #+#             */
/*   Updated: 2024/11/04 23:55:55 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_input			input;
	t_fork			*forksarray;
	pthread_t		*philosophers;
	pthread_t		monitor;
	t_thread_pmt	*pmtarray;

	if(input_validation(argc, argv) == UNSUCCESSFUL_VALIDATION)
		return (CLOSE_PROGRAM);
	input_init(&input, argv);
	forksarray = forks_generate(input);

	pmtarray = pmtarray_generate(input, forksarray);
	philosophers = philosophers_generate(input, forksarray, pmtarray);
	pthread_create(&monitor, NULL, monitor_routine, (void *)&pmtarray[0]);
	threads_join(philosophers, monitor, input);
	mutexdestroy(pmtarray);	
	//last_print(pmt_array, &input);
	free_everything(forksarray, pmtarray, philosophers);
	/*if (argc == 6 && (input.someone_is_dead != 1
			|| input.no_more_to_print != 1))
		printf("All philosophers have eaten the expected meals!\n");
		*/

	return (0);
}

//TODO: resolve race conditions...nomore
