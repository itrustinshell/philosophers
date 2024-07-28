/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:55:42 by largenzi          #+#    #+#             */
/*   Updated: 2024/07/28 09:57:20 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

void	msg(t_thread_pmt *pmt, char *message, char *color)
{
	long	time;

	pthread_mutex_lock(pmt->write);
	pthread_mutex_lock(pmt->all_finish_eating);
	if (*(pmt)->finish_for_meals == 1)
	{
		pthread_mutex_unlock(pmt->all_finish_eating);
		pthread_mutex_unlock(pmt->write);
		return ;
	}
	pthread_mutex_unlock(pmt->all_finish_eating);
	pthread_mutex_lock(pmt->death_check);
	if (*(pmt)->someone_is_dead == 1)
	{
		pthread_mutex_unlock(pmt->death_check);
		pthread_mutex_unlock(pmt->write);
		return ;
	}
	pthread_mutex_unlock(pmt->death_check);
	time = get_time() - pmt->start_simulation;
	pthread_mutex_lock(pmt->meals_check);
	if (*(pmt)->all_meals_eaten == pmt->number_of_philo - 1)
	{
		printf ("%s\n", ALL_EAT);
		pthread_mutex_unlock(pmt->meals_check);
		pthread_mutex_unlock(pmt->write);
		return ;
	}
	pthread_mutex_unlock(pmt->meals_check);
	printf("%s%ld %d %s%s\n", color, time, pmt->id, message, RESET);
	pthread_mutex_unlock(pmt->write);
}

int	ft_atoi(char *str)
{
	int	result;
	int	i;

	i = 0;
	result = 0;
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}
