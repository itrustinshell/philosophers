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
	free(pmtarray->someonediedptr);
	free(pmtarray->finishprintptr);
	free(pmtarray);
	free(forks_array);
	free(philosophers);
}
