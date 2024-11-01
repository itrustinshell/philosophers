/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:49:44 by largenzi          #+#    #+#             */
/*   Updated: 2024/07/28 08:37:21 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdarg.h>
# include <errno.h>

# define TAKE_FORK "has taken a fork"
# define THINK "is thinking"
# define SLEEP "is sleeping"
# define EAT "is eating"
# define DIED "died"
# define ALL_EAT "all have eaten"

# define WHITE "\033[1;37m"
# define BLUE    "\033[1;34m"
# define PURPLE  "\033[1;35m"
# define GRAY    "\033[1;30m"
# define GREEN   "\033[1;32m"
# define CYAN    "\033[1;36m"
# define YELLOW  "\033[1;33m"
# define RED     "\033[1;31m"
# define RESET   "\033[0m"

enum e_state
{
	alive_s,
	dead_s,
};

typedef struct s_input
{
	int	n_of_phil;
	int	time_to_die;
	int	time_to_eat;	
	int	time_to_sleep;
	int	n_of_meals;
}	t_input;

typedef struct s_thread_param
{
	int					id;
	int					number_of_philo;
	enum e_state		state;
	pthread_mutex_t		*meals_check;
	int					n_of_meals;
	int					*all_meals_eaten;
	int					*finish_for_meals;
	pthread_mutex_t		*all_finish_eating;
	pthread_mutex_t		*time_check;
	pthread_mutex_t		*death_check;	
	int					*someone_is_dead;
	pthread_mutex_t		*write;
	pthread_mutex_t		*forks;
	int					forkleft;
	int					forkright;
	long				start_simulation;
	long				last_time_execution;
	long				time_to_eat;
	long				time_to_sleep;
	long				time_to_die;
}	t_thread_pmt;

//validation
void			check_numbers(int argc, char **argv);
void			input_validation_and_init(int argc, char **argv,
					t_input *input);

//create_malloc
void			create_philo_array(t_input input,
					t_thread_pmt *pmt_array, pthread_t **philo_array);
void			create_pmt_array(int n_of_phil, t_thread_pmt **pmt_array);
pthread_mutex_t	*create_forks_array(int n_of_phil);

//actions

void			*monitor_routine(void *param);
void			what_routine(t_input input, pthread_t *philosophers,
					t_thread_pmt *pmt_array);

int				take_forkleft_first(t_thread_pmt *pmt);
int				take_forkright_first(t_thread_pmt *pmt);

//init
void			start_philosopher_routine(pthread_t *philo_array,
					t_input input, t_thread_pmt *pmt_array);
void			pmt_array_init(t_thread_pmt *pmt, t_input input);
void			pmt_array_init_general(t_thread_pmt *pmt, t_input input);
void			pmt_array_init_death_management(t_thread_pmt *pmt,
					t_input input);
void			pmt_array_init_meals_management(t_thread_pmt *pmt,
					t_input input);
//init_utils
int				ft_atoi(char *str);
int				check_if_died(t_thread_pmt *pmt);
//void			ft_timer(t_thread_pmt *pmt, long time_limit);
long			get_time(void);
void			msg(t_thread_pmt *param, char *message, char *color);

// free_and_join
void			philosophers_join(pthread_t *philosophers,
					pthread_t monitor, t_input input);
void			free_everything(t_input input, t_thread_pmt *pmt_array,
					pthread_t *philo_array);

#endif
