/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:56:37 by largenzi          #+#    #+#             */
/*   Updated: 2024/11/09 18:52:59 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*initialize major part of pmtaray's fileds. Remember that each element of 
 the pmtarray represents the "variable-set" of a specific philosopher*/
static void	generalpmtarray_init(t_thread_pmt *pmt, t_input input,
			t_fork *forks)
{
	int		i;
	long	start_simulation;

	start_simulation = get_time();
	i = 0;
	while (i < (input.n_of_phil + 1))
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
		pmt[i].n_of_meals = input.n_of_meals;
		pmt[i].all_meals_eaten = 0;
		i++;
	}
}

/*initialize controlvar of pmtarray.Remember that each element of 
 the pmtarray represents the "variable-set" of a specific philosopher */
static void	controlvar_init(t_thread_pmt *pmtarray, t_input input)
{
	int				*someonediedvar;
	int				*finishprintvar;
	int				*philo_who_finished_to_eat;
	int				i;

	someonediedvar = (int *)malloc(sizeof(int));
	finishprintvar = (int *)malloc(sizeof(int));
	philo_who_finished_to_eat = (int *)malloc(sizeof(int));
	*someonediedvar = 0;
	*finishprintvar = 0;
	*philo_who_finished_to_eat = 0;
	i = 0;
	while (i < (input.n_of_phil + 1))
	{
		pmtarray[i].someonediedptr = someonediedvar;
		pmtarray[i].finishprintptr = finishprintvar;
		pmtarray[i].philo_who_finished_to_eat = philo_who_finished_to_eat;
		i++;
	}
}

/*Initializzation function. This function calls all the previous.
 This separation has been done becouse of semplicity, clarity and
 Norm*/
static void	pmtarray_init(t_thread_pmt *pmtarray, t_fork *forksarray,
		t_input input)
{
	generalpmtarray_init(pmtarray, input, forksarray);
	controlvar_init(pmtarray, input);
	mutex_init_partone(pmtarray, input);
	mutex_init_parttwo(pmtarray, input);
}

/*Create pmtarray (dinamically allocating memory) and initialize it.
You malloc one more element for monitor*/
t_thread_pmt	*pmtarray_generate(t_input input, t_fork *forksarray)
{
	t_thread_pmt	*pmtarray;

	pmtarray = (t_thread_pmt *)malloc((input.n_of_phil + 1)
			* sizeof(t_thread_pmt));
	pmtarray_init(pmtarray, forksarray, input);
	return (pmtarray);
}
