/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:50:25 by largenzi          #+#    #+#             */
/*   Updated: 2024/11/03 10:21:54 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_everything(t_fork *forks_array,
		t_thread_pmt *pmt_array, pthread_t *philosophers)
{
	free(pmt_array->mutexwrite);
	free(pmt_array->someonediedptr);
	free(pmt_array->finishprintptr);
	free(pmt_array->mutexdeath);
	free(pmt_array);
	free(forks_array);
	free(philosophers);
}
