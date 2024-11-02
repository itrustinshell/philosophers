#include "philo.h"
/*
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
*/

static t_fork	*create_forksarray(int n_of_phil)
{
	t_fork	*forks;

	forks = (t_fork *)malloc(n_of_phil * sizeof(t_fork));
	if (!forks)
		return (0);
	return (forks);
}

static void	initialize_forksarray(t_fork *forks, int n_of_phil)
{
	int	i;

	i = 0;
	while (i < n_of_phil)
	{
		pthread_mutex_init(&forks[i].forklock, NULL); //aaase errore togli &
		forks[i].id = i + 1;
		forks[i].status = UNLOCKED;
		i++;
	}
}

t_fork  *forks_generation(t_input input)
{
	t_fork *forks_array;

	forks_array = create_forksarray(input.n_of_phil);
	initialize_forksarray(forks_array, input.n_of_phil);

	return (forks_array);
}
