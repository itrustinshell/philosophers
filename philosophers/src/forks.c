#include "philo.h"

static pthread_mutex_t	*create_forksarray(int n_of_phil)
{
	pthread_mutex_t	*forks;

	forks = (pthread_mutex_t *)malloc(n_of_phil * sizeof(pthread_mutex_t));
	if (!forks)
		return (0);
	return (forks);
}

static void	initialize_forksarray(pthread_mutex_t *forks, int n_of_phil)
{
	int	i;

	i = 0;
	while (i < n_of_phil)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

pthread_mutex_t  *forks_generation(t_input input)
{
	pthread_mutex_t *forks_array;

	forks_array = create_forksarray(input.n_of_phil);
	initialize_forksarray(forks_array, input.n_of_phil);

	return (forks_array);
}

