/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:13:42 by ubuntu            #+#    #+#             */
/*   Updated: 2024/11/09 18:13:49 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutexdestroy(t_thread_pmt *pmtarray)
{
	int	i;

	i = 0;
	while (i < (pmtarray[0].number_of_philo))
	{
		pthread_mutex_destroy(&pmtarray[0].forks[i].forklock);
		i++;
	}
	pthread_mutex_destroy(pmtarray->mutexdeath);
	pthread_mutex_destroy(pmtarray->mutexwrite);
	pthread_mutex_destroy(pmtarray->mutexfinishprint);
	pthread_mutex_destroy(pmtarray->mutextime);
	pthread_mutex_destroy(pmtarray->mutexttd);
	pthread_mutex_destroy(pmtarray->mutexmeal);
}
