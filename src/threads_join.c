/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:58:14 by largenzi          #+#    #+#             */
/*   Updated: 2024/11/02 17:58:17 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	threads_join(pthread_t *philosophers,
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
