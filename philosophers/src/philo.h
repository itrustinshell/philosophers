/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:49:44 by largenzi          #+#    #+#             */
/*   Updated: 2024/11/04 23:55:52 by ubuntu           ###   ########.fr       */
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

# define TAKE_FIRST_FORK "has taken 1 fork"
# define TAKE_SECOND_FORK "has taken 2 fork"
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

# define BAD_INPUT 0
# define VALID_INPUT 1
# define UNSUCCESSFUL_VALIDATION 0
# define SUCCESSFUL_VALIDATION 1
# define CLOSE_PROGRAM -1
# define LOCKED 1
# define UNLOCKED 0
# define EVEN 0
# define YES 1
# define NO 0
# define FORK_HAS_TAKEN 1
# define FORK_HAS_RELEASED 0
# define NO_MEALS_HAVE_BEEN_SPECIFIED 0
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

typedef struct s_fork
{
	int				id;
	int				status;
	pthread_mutex_t	forklock;
}	t_fork;

typedef struct s_thread_param
{
	t_fork			*forks;
	pthread_mutex_t *mutextime;
	pthread_mutex_t *mutexttd;

	pthread_mutex_t	*mutexdeath;
	pthread_mutex_t	*mutexwrite;
	pthread_mutex_t	*mutexmeals;
	pthread_mutex_t	*mutexfinishprint;
	int				*someonediedptr;
	int				*finishprintptr;
	int				number_of_philo;
	int				forkleft;
	int				forkright;
	int				id;
	int				n_of_meals;
	int				all_meals_eaten;
	long			start_simulation;
	long			last_time_execution;
	long			time_to_eat;
	long			time_to_sleep;
	long			time_to_die;
	long			time_of_death;
	enum e_state	state;
}	t_thread_pmt;

//validation
int				input_validation(int argc, char **argv);
void			validation_and_init(int argc, char **argv, t_input *input);

//forks
t_fork			*forks_generate(t_input input);

//pmt
t_thread_pmt	*pmtarray_generate(t_input input, t_fork *foks_array);

//philosophers
pthread_t		*philosophers_generate(t_input input,
					t_fork *forks_array, t_thread_pmt *pmt_array);

//create_malloc
void			threads_join(pthread_t *philosophers,
					pthread_t monitor, t_input input);

//actions
void			*routine_with_n_of_meals(void *param);
void			*routine_without_n_of_meals(void *param);
void			*monitor_routine(void *param);

//actions_utils
long			milliseconds(struct timeval current_time);
void			my_sleep_ms(long time);
int				print_if_die(t_thread_pmt	*pmt, int i, long time);
long			get_time(void);
void			msg(t_thread_pmt *param, char *message);

int			take_forkleft_first(t_thread_pmt *pmt);
int			take_forkright_first(t_thread_pmt *pmt);

//actions_utils_3
void			sleeping(t_thread_pmt *param);
void			thinking(t_thread_pmt *param);
void			eating(t_thread_pmt *param);
int				eat_sleep_think(t_thread_pmt	*pmt, int both_forks);

//init
void			input_init(t_input *input, char **argv);
void			philosophers_init(pthread_t *philosophers, t_input input,
					void*(*f)(void *), t_thread_pmt *thread_pmt);
//init_utils
int				ft_atoi(char *str);
void			last_print(t_thread_pmt	*pmtarray, t_input *input);
void			free_everything(t_fork *forks_array,
					t_thread_pmt *pmtarray, pthread_t *philosophers);
void			mutexdestroy(t_thread_pmt *pmtarray);


#endif
