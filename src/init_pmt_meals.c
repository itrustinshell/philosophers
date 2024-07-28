/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pmt_meals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:56:16 by largenzi          #+#    #+#             */
/*   Updated: 2024/07/27 13:59:30 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_pmt_mutex_all_finish_eating(t_thread_pmt *pmt, t_input input)
{
	int				i;
	pthread_mutex_t	*all_finish_eating_malloced;

	all_finish_eating_malloced = (pthread_mutex_t *)malloc
		(sizeof(pthread_mutex_t));
	pthread_mutex_init(all_finish_eating_malloced, NULL);
	i = -1;
	while (++i <= input.n_of_phil)
		pmt[i].all_finish_eating = all_finish_eating_malloced;
}

static void	init_pmt_mutex_meals_check(t_thread_pmt *pmt, t_input input)
{
	int				i;
	pthread_mutex_t	*meals_check_malloced;

	meals_check_malloced = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(meals_check_malloced, NULL);
	i = -1;
	while (++i <= input.n_of_phil)
		pmt[i].meals_check = meals_check_malloced;
}

static void	init_pmt_all_meals_eaten(t_thread_pmt *pmt, t_input input)
{
	int		i;
	int		*all_meals_eaten_malloced;

	all_meals_eaten_malloced = (int *)malloc(sizeof(int));
	*all_meals_eaten_malloced = 0;
	i = -1;
	while (++i <= input.n_of_phil)
		pmt[i].all_meals_eaten = all_meals_eaten_malloced;
}

static void	init_pmt_finish_for_meals(t_thread_pmt *pmt, t_input input)
{
	int		i;
	int		*finish_for_meals_malloced;

	finish_for_meals_malloced = (int *)malloc(sizeof(int));
	*finish_for_meals_malloced = 0;
	i = -1;
	while (++i <= input.n_of_phil)
		pmt[i].finish_for_meals = finish_for_meals_malloced;
}

void	pmt_array_init_meals_management(t_thread_pmt *pmt, t_input input)
{
	init_pmt_mutex_meals_check(pmt, input);
	init_pmt_mutex_all_finish_eating(pmt, input);
	init_pmt_all_meals_eaten(pmt, input);
	init_pmt_finish_for_meals(pmt, input);
}
