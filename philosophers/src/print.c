/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:57:24 by largenzi          #+#    #+#             */
/*   Updated: 2024/11/03 23:42:08 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	print_if_die(t_thread_pmt	*pmt, int i, long time)
{
	int a;
	int b;

	if (time > pmt[i].time_to_die)
	{
		a = pthread_mutex_lock(pmt[i].mutexfinishprint);
		*pmt[i].finishprintptr = 1;
		if (a == 0)
			pthread_mutex_unlock(pmt[i].mutexfinishprint);
		b = pthread_mutex_lock(pmt->mutexdeath);
		*pmt[i].someonediedptr = 1;
		if (b == 0)
			pthread_mutex_unlock(pmt->mutexdeath);
		printf("%s%ld %d %s%s\n", RED,
			get_time() - pmt[i].start_simulation,
			pmt[i].id, DIED, RESET);
		return (0);
	}
	return (1);
}

/*
void	last_print(t_thread_pmt	*pmtarray, t_input *input)
{
	input->no_more_to_print = 0;
	
	pthread_mutex_lock(pmtarray->mutexfinishprint);
	if (*pmtarray[0].finishprintptr == 1)
	{
		input->no_more_to_print = 1;
		pthread_mutex_unlock(pmtarray->mutexfinishprint);
	}
	pthread_mutex_unlock(pmtarray->mutexfinishprint);
	input->someone_is_dead = 0;
	pthread_mutex_lock(pmtarray->mutexdeath);
	if (*pmtarray[0].someonediedptr == 1)
	{
		pthread_mutex_unlock(pmtarray->mutexdeath);
		input->someone_is_dead = 1;
	}
	pthread_mutex_unlock(pmtarray->mutexdeath);
}
*/