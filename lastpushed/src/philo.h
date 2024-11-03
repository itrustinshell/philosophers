/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:49:44 by largenzi          #+#    #+#             */
/*   Updated: 2024/07/20 17:39:35 by largenzi         ###   ########.fr       */
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
	i_ate_all_meals,
	alive,
	dead,
};

typedef struct s_input
{
	int	n_of_phil;
	int	time_to_die;
	int	time_to_eat;	
	int	time_to_sleep;
	int	n_of_meals;
	int	no_more_to_print;
	int	someone_is_dead;
}	t_input;

typedef struct s_thread_param
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	*death_check;
	pthread_mutex_t	*write;
	int				number_of_philo;
	int				forkleft;
	int				forkright;
	int				id;
	int				n_of_meals;
	int				*someone_is_dead;
	int				all_meals_eaten;
	int				*no_more_to_print;
	long			start_simulation;
	long			last_time_execution;
	long			time_to_eat;
	long			time_to_sleep;
	long			time_to_die;
	long			time_of_death;
	enum e_state	state;
}	t_thread_pmt;

//validation
void			check_numbers(int argc, char **argv);
void			input_validation(int argc, char **argv);
void			validation_and_init(int argc, char **argv, t_input *input);

//create_malloc
pthread_t		*create_philosophers(t_input input,
					pthread_mutex_t *forks_array,
					t_thread_pmt *pmt_array);
t_thread_pmt	*create_pmt_array(int n_of_phil, pthread_mutex_t *forks_array);
pthread_mutex_t	*create_forks_array(int n_of_phil);

//actions
void			*routine_with_n_of_meals(void *param);
void			*routine_without_n_of_meals(void *param);
void			*monitor_routine(void *param);
void			what_routine(t_input input, pthread_t *philosophers,
					t_thread_pmt *pmt_array);

//actions_utils
long			milliseconds(struct timeval current_time);
void			my_sleep_ms(long time);
int				print_if_die(t_thread_pmt	*pmt, int i, long time);
long			get_time(void);
void			msg(t_thread_pmt *param, char *message, char *color);

//actions_utils_2
int				take_forkleft_first(t_thread_pmt *pmt);
int				take_forkright_first(t_thread_pmt *pmt);

//actions_utils_3
void			sleeping(t_thread_pmt *param);
void			thinking(t_thread_pmt *param);
void			eating(t_thread_pmt *param);
int				eat_sleep_think(t_thread_pmt	*pmt, int both_forks);

//init
t_thread_pmt	*create_pmt_array(int n_of_phil, pthread_mutex_t *forks_array);
void			pmt_array_init(t_thread_pmt *thread_pmt, pthread_mutex_t *forks,
					t_input input);
pthread_mutex_t	*create_forks_array(int n_of_phil);
void			forks_array_init(pthread_mutex_t *forks, int n_of_phil);
void			input_init(t_input *input, char **argv);
void			philosophers_init(pthread_t *philosophers, t_input input,
					void*(*f)(void *), t_thread_pmt *thread_pmt);
//init_utils
int				ft_atoi(char *str);
void			initialize_pmt_one(t_thread_pmt *pmt, t_input input,
					pthread_mutex_t *forks, int *no_more_to_print);
void			initialize_pmt_two(t_thread_pmt *pmt, t_input input,
					int *is_dead, pthread_mutex_t *write);
void			initialize_pmt_three(t_thread_pmt *pmt,
					t_input input, pthread_mutex_t *death_check);
#endif
