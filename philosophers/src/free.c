/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:50:25 by largenzi          #+#    #+#             */
/*   Updated: 2024/11/03 12:38:10 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_everything(t_fork *forks_array,
		t_thread_pmt *pmtarray, pthread_t *philosophers)
{
	free(pmtarray->mutexdeath);
	free(pmtarray->mutexwrite);
	free(pmtarray->mutexfinishprint);
	free(pmtarray->mutextime);
	free(pmtarray->mutexttd);

	free(pmtarray->someonediedptr);
	free(pmtarray->finishprintptr);
	free(pmtarray);
	free(forks_array);
	free(philosophers);
}



void	mutexdestroy(t_thread_pmt *pmtarray)
{
	int i = 0;
	while(i < (pmtarray[0].number_of_philo))
	{
		pthread_mutex_destroy(&pmtarray[0].forks[i].forklock);
		i++;
	}
	pthread_mutex_destroy(pmtarray->mutexdeath);
	pthread_mutex_destroy(pmtarray->mutexwrite);
	pthread_mutex_destroy(pmtarray->mutexfinishprint);
	pthread_mutex_destroy(pmtarray->mutextime);
	pthread_mutex_destroy(pmtarray->mutexttd);
}
