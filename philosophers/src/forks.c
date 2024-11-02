/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:49:51 by largenzi          #+#    #+#             */
/*   Updated: 2024/11/02 17:50:12 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_fork	*create_forksarray(int n_of_phil)
{
	t_fork	*forks;

	forks = (t_fork *)malloc(n_of_phil * sizeof(t_fork));
	if (!forks)
		return (0);
	return (forks);
}

static void	initialize_forksarray(t_fork *forks, int n_of_phil)
{
	int	i;

	i = 0;
	while (i < n_of_phil)
	{
		pthread_mutex_init(&forks[i].forklock, NULL);
		forks[i].id = i + 1;
		forks[i].status = UNLOCKED;
		i++;
	}
}

t_fork	*forks_generation(t_input input)
{
	t_fork	*forks_array;

	forks_array = create_forksarray(input.n_of_phil);
	initialize_forksarray(forks_array, input.n_of_phil);
	return (forks_array);
}
