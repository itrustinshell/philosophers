/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:04:10 by largenzi          #+#    #+#             */
/*   Updated: 2024/11/02 12:45:27 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
//	int	tmp;
//	int	div;
	int	result;
	int	i;

	i = 0;
	result = 0;
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

void	input_init(t_input *input, char **argv)
{
	input->n_of_phil = ft_atoi(argv[1]);
	input->time_to_die = ft_atoi(argv[2]);
	input->time_to_eat = ft_atoi(argv[3]);
	input->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		input->n_of_meals = ft_atoi(argv[5]);
	else
		input->n_of_meals = 0;
}

void	initialize_pmt_one(t_thread_pmt *pmt, t_input input,
			t_fork *forks, int *no_more_to_print)
{
	int		i;
	long	start_simulation;

	start_simulation = get_time();
	i = 0;
	while (i < input.n_of_phil)
	{
		pmt[i].id = i + 1;
		pmt[i].forks = forks;
		pmt[i].start_simulation = start_simulation;
		pmt[i].last_time_execution = start_simulation;
		pmt[i].number_of_philo = input.n_of_phil;
		pmt[i].time_to_die = input.time_to_die;
		pmt[i].time_to_eat = input.time_to_eat;
		pmt[i].time_to_sleep = input.time_to_sleep;
		pmt[i].forkleft = i;
		pmt[i].forkright = ((i + 1) % input.n_of_phil);
		pmt[i].state = alive;
		pmt[i].n_of_meals = input.n_of_meals;
		pmt[i].all_meals_eaten = 0;
		pmt[i].no_more_to_print = no_more_to_print;
		i++;
	}
}

void	initialize_pmt_two(t_thread_pmt *pmt, t_input input, int *is_dead,
			pthread_mutex_t *write)
{
	int		i;
	
	i = 0;
	while (i < input.n_of_phil)
	{
		pmt[i].write = write;
		pmt[i].someone_is_dead = is_dead;
		i++;
	}
}

void	initialize_pmt_three(t_thread_pmt *pmt,
			t_input input, pthread_mutex_t *death_check)
{
	int		i;

	i = 0;
	while (i < input.n_of_phil)
	{
		pmt[i].death_check = death_check;
		i++;
	}
}
