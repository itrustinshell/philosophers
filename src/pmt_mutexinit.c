/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmt_mutexinit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:45:27 by ubuntu            #+#    #+#             */
/*   Updated: 2024/11/09 18:51:17 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Initialize mutex-fileds of pmtarray. Remember that each element of 
 the pmtarray represents the "variable-set" of a specific philosopher*/
void	mutex_init_partone(t_thread_pmt *pmtarray, t_input input)
{
	int				i;
	pthread_mutex_t	*mutexdeath;
	pthread_mutex_t	*mutexwrite;
	pthread_mutex_t	*mutexfinishprint;
	pthread_mutex_t	*mutexmeal;

	mutexdeath = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	mutexwrite = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	mutexfinishprint = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	mutexmeal = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(mutexdeath, NULL);
	pthread_mutex_init(mutexwrite, NULL);
	pthread_mutex_init(mutexfinishprint, NULL);
	pthread_mutex_init(mutexmeal, NULL);
	i = 0;
	while (i < (input.n_of_phil + 1))
	{
		pmtarray[i].mutexdeath = mutexdeath;
		pmtarray[i].mutexwrite = mutexwrite;
		pmtarray[i].mutexfinishprint = mutexfinishprint;
		pmtarray[i].mutexmeal = mutexmeal;
		i++;
	}
}

void	mutex_init_parttwo(t_thread_pmt *pmtarray, t_input input)
{
	int				i;
	pthread_mutex_t	*mutextime;
	pthread_mutex_t	*mutexttd;

	mutextime = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	mutexttd = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(mutextime, NULL);
	pthread_mutex_init(mutexttd, NULL);
	i = 0;
	while (i < (input.n_of_phil + 1))
	{
		pmtarray[i].mutextime = mutextime;
		pmtarray[i].mutexttd = mutexttd;
		i++;
	}
}
