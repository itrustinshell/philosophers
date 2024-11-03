/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:56:37 by largenzi          #+#    #+#             */
/*   Updated: 2024/11/03 10:37:47 by largenzi         ###   ########.fr       */
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
		i++;
	}
}

/*initialize controlvar of pmtarray.Remember that each element of 
 the pmtarray represents the "variable-set" of a specific philosopher */
static void	controlvar_init(t_thread_pmt *pmtarray, t_input input)

{
	int				*someonediedvar;
	int				*finishprintvar;
	int				i;

	someonediedvar = (int *)malloc(sizeof(int));
	finishprintvar = (int *)malloc(sizeof(int));
	
	*someonediedvar = 0;
	*finishprintvar = 0;

	i = 0;
	while (i < input.n_of_phil)
	{
		pmtarray[i].someonediedptr = someonediedvar;
		pmtarray[i].finishprintptr = finishprintvar;
		i++;
	}
}

/*Initialize mutex-fileds of pmtarray. Remember that each element of 
 the pmtarray represents the "variable-set" of a specific philosopher*/
static void mutex_init(t_thread_pmt *pmtarray, t_input input)
{
	int				i;
	pthread_mutex_t	*mutexdeath;
	pthread_mutex_t	*mutexwrite;
	pthread_mutex_t	*mutexfinishprint;

	mutexdeath = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	mutexwrite = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	mutexfinishprint = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(mutexdeath, NULL);
	pthread_mutex_init(mutexwrite, NULL);
	pthread_mutex_init(mutexfinishprint, NULL);
	i = 0;
	while (i < input.n_of_phil)
	{
		pmtarray[i].mutexdeath = mutexdeath;
		pmtarray[i].mutexwrite = mutexwrite;
		pmtarray[i].mutexfinishprint = mutexfinishprint;
		i++;
	}
}

/*Initializzation function. This function calls all the previous.
 This separation has been done becouse of semplicity, clarity and
 Norm*/
static void	pmtarray_init(t_thread_pmt *pmtarray, t_fork *forks,
		t_input input)
{
	generalpmtarray_init(pmtarray, input, forks);
	controlvar_init(pmtarray, input);
	mutex_init(pmtarray, input);
}

/*Create pmtarray (dinamically allocating memory) and initialize it.*/
t_thread_pmt	*pmtarray_generate(t_input input, t_fork *forks_array)
{
	t_thread_pmt	*pmtarray;
	
	pmtarray = (t_thread_pmt *)malloc(input.n_of_phil * sizeof(t_thread_pmt));
	pmtarray_init(pmtarray, forks_array, input);
	return (pmtarray);
}
