/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:50:25 by largenzi          #+#    #+#             */
/*   Updated: 2024/11/09 15:40:16 by ubuntu           ###   ########.fr       */
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
	free(pmtarray->mutexmeal);
	free(pmtarray->someonediedptr);
	free(pmtarray->finishprintptr);
	free(pmtarray->philo_who_finished_to_eat);
	free(pmtarray);
	free(forks_array);
	free(philosophers);
}
