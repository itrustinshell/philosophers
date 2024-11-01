#include "philo.h"

void	chose_routine(t_input input, pthread_t *philosophers,
			 t_thread_pmt *thread_pmt)
{
	int	i;

	i = 0;
	if (input.n_of_meals <= 0)
	{
		while (i < input.n_of_phil)
		{
			pthread_create(&philosophers[i], NULL,
					routine_without_n_of_meals, (void *)&thread_pmt[i]);
			i++;
		}
	}
	else
	{
		while ( i < input.n_of_phil)
		{
			pthread_create(&philosophers[i], NULL,
					routine_with_n_of_meals, (void *)&thread_pmt[i]);
			i++;
		}
	}
}


pthread_t	*create_philosophers(t_input input, pthread_mutex_t *forks_array,
				t_thread_pmt *pmt_array)
{
	pthread_t	*philosophers;

	philosophers = (pthread_t *)malloc(input.n_of_phil
			* sizeof(pthread_t));
	if (!philosophers)
	{
		free(forks_array);
		free(pmt_array);
		exit (1);
	}
	return (philosophers);
}
