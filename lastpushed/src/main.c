/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:42:09 by largenzi          #+#    #+#             */
/*   Updated: 2024/07/20 18:43:23 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philosophers_join(pthread_t *philosophers,
			pthread_t monitor, t_input input)
{
	int	i;

	i = 0;
	while (i < input.n_of_phil)
	{
		pthread_join(philosophers[i], NULL);
		i++;
	}
	pthread_join(monitor, NULL);
}

void	free_everything(pthread_mutex_t *forks_array,
		t_thread_pmt *pmt_array, pthread_t *philosophers)
{
	free(pmt_array->write);
	free(pmt_array->someone_is_dead);
	free(pmt_array->no_more_to_print);
	free(pmt_array->death_check);
	free(pmt_array);
	free(forks_array);
	free(philosophers);
}

int	print_if_die(t_thread_pmt	*pmt, int i, long time)
{
	if (time > pmt[i].time_to_die)
	{
		*pmt[i].no_more_to_print = 1;
		*pmt[i].someone_is_dead = 1;
		printf("%s%ld %d %s%s\n", RED,
			get_time() - pmt[i].start_simulation,
			pmt[i].id, DIED, RESET);
		return (0);
	}
	return (1);
}

void	last_print(t_thread_pmt	*pmt_array, t_input *input)
{
	input->no_more_to_print = 0;
	if (*pmt_array[0].no_more_to_print == 1)
		input->no_more_to_print = 1;
	input->someone_is_dead = 0;
	if (*pmt_array[0].someone_is_dead == 1)
		input->someone_is_dead = 1;
}

int	main(int argc, char **argv)
{
	t_input			input;
	pthread_mutex_t	*forks_array;
	pthread_t		*philosophers;
	pthread_t		monitor;
	t_thread_pmt	*pmt_array;

	input_validation(argc, argv);
	input_init(&input, argv);
	forks_array = create_forks_array(input.n_of_phil);
	forks_array_init(forks_array, input.n_of_phil);
	pmt_array = create_pmt_array(input.n_of_phil, forks_array);
	pmt_array_init(pmt_array, forks_array, input);
	philosophers = create_philosophers(input, forks_array, pmt_array);
	pthread_create(&monitor, NULL, monitor_routine, (void *)&pmt_array[0]);
	what_routine(input, philosophers, pmt_array);
	philosophers_join(philosophers, monitor, input);
	last_print(pmt_array, &input);
	free_everything(forks_array, pmt_array, philosophers);
	if (argc == 6 && (input.someone_is_dead != 1
			|| input.no_more_to_print != 1))
		printf("All philosophers have eaten the expected meals!\n");
	return (0);
}
