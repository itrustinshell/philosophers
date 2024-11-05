/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:55:42 by largenzi          #+#    #+#             */
/*   Updated: 2024/11/03 18:31:28 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

void msg(t_thread_pmt *param, char *message)
{
    long time;
    int lock_write, lock_death;

    lock_write = pthread_mutex_lock(param->mutexwrite);
    if (lock_write != 0) {
        printf("heiiiiiiiii il lock non ha funzionato\n");
        return; 
    }

    lock_death = pthread_mutex_lock(param->mutexdeath);
    if (lock_death != 0) {
        pthread_mutex_unlock(param->mutexwrite);
        // Gestisci l'errore (log, exit, ecc.)
        return; 
    }

    if (*(param)->someonediedptr == YES)
    {
        pthread_mutex_unlock(param->mutexdeath);
        pthread_mutex_unlock(param->mutexwrite);
   
        return;
	}

    time = get_time() - param->start_simulation;
    printf("%ld %d %s\n", time, param->id, message);

    pthread_mutex_unlock(param->mutexdeath);
    pthread_mutex_unlock(param->mutexwrite);
}


