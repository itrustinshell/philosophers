/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_takefork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:11:55 by largenzi          #+#    #+#             */
/*   Updated: 2024/11/03 22:28:32 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int take_forkleft_first(t_thread_pmt *pmt)
{
    pthread_mutex_lock(&pmt->forks[pmt->forkleft].forklock);
    msg(pmt, TAKE_FIRST_FORK);

    if (pmt->number_of_philo == 1)
    {
        // Handle single philosopher case
        pthread_mutex_unlock(&pmt->forks[pmt->forkleft].forklock);
        pthread_mutex_lock(pmt->mutexdeath);
        *(pmt)->someonediedptr = YES;
        pthread_mutex_unlock(pmt->mutexdeath);
        return -1; // Cannot eat
    }

    // Lock the right fork for eating
    pthread_mutex_lock(&pmt->forks[pmt->forkright].forklock);
    msg(pmt, TAKE_SECOND_FORK);
    
    eating(pmt); // Philosopher eats

    // Unlock both forks after eating
    pthread_mutex_unlock(&pmt->forks[pmt->forkright].forklock);
    pthread_mutex_unlock(&pmt->forks[pmt->forkleft].forklock);

    return 1; // Successfully eaten
}

int take_forkright_first(t_thread_pmt *pmt)
{
    pthread_mutex_lock(&pmt->forks[pmt->forkright].forklock);
    msg(pmt, TAKE_FIRST_FORK);

    if (pmt->number_of_philo == 1)
    {
        // Handle single philosopher case
        pthread_mutex_unlock(&pmt->forks[pmt->forkright].forklock);
        pthread_mutex_lock(pmt->mutexdeath);
        *(pmt)->someonediedptr = YES;
        pthread_mutex_unlock(pmt->mutexdeath);
        return -1; // Cannot eat
    }

    // Lock the left fork for eating
    pthread_mutex_lock(&pmt->forks[pmt->forkleft].forklock);
    msg(pmt, TAKE_SECOND_FORK);
    
    eating(pmt); // Philosopher eats

    // Unlock both forks after eating
    pthread_mutex_unlock(&pmt->forks[pmt->forkleft].forklock);
    pthread_mutex_unlock(&pmt->forks[pmt->forkright].forklock);

    return 1; // Successfully eaten
}



