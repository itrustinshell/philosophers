/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:57:24 by largenzi          #+#    #+#             */
/*   Updated: 2024/11/03 10:25:28 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_if_die(t_thread_pmt	*pmt, int i, long time)
{
	if (time > pmt[i].time_to_die)
	{
		*pmt[i].finishprintptr = 1;
		pthread_mutex_lock(pmt->mutexdeath);
		*pmt[i].someonediedptr = 1;
		pthread_mutex_unlock(pmt->mutexdeath);
		printf("%s%ld %d %s%s\n", RED,
			get_time() - pmt[i].start_simulation,
			pmt[i].id, DIED, RESET);
		return (0);
	}
	return (1);
}

void	last_print(t_thread_pmt	*pmt_array, t_input *input)
{
	input->no_more_to_print = 0;
	if (*pmt_array[0].finishprintptr == 1)
		input->no_more_to_print = 1;
	input->someone_is_dead = 0;
	pthread_mutex_lock(pmt_array->mutexdeath);
	if (*pmt_array[0].someonediedptr == 1)
	{
		pthread_mutex_unlock(pmt_array->mutexdeath);
		input->someone_is_dead = 1;
	}
	pthread_mutex_unlock(pmt_array->mutexdeath);
}
