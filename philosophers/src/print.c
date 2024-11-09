/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:57:24 by largenzi          #+#    #+#             */
/*   Updated: 2024/11/09 19:04:17 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_if_die(t_thread_pmt *pmt, int i, long time)
{
	pthread_mutex_lock(pmt->mutexttd);
	if (time > pmt[i].time_to_die)
	{
		pthread_mutex_unlock(pmt->mutexttd);
		pthread_mutex_lock(pmt[i].mutexfinishprint);
		*pmt[i].finishprintptr = 1;
		pthread_mutex_unlock(pmt[i].mutexfinishprint);
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
