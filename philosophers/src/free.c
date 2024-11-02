/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:50:25 by largenzi          #+#    #+#             */
/*   Updated: 2024/11/02 17:56:27 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_everything(t_fork *forks_array,
		t_thread_pmt *pmt_array, pthread_t *philosophers)
{
	free(pmt_array->write);
	free(pmt_array->someone_is_dead);
	free(pmt_array->no_more_to_print);
	free(pmt_array->death_check);
	free(pmt_array);
	free(forks_array);
	free(philosophers);
}
