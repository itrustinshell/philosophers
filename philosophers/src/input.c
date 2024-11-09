/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:04:10 by largenzi          #+#    #+#             */
/*   Updated: 2024/11/09 15:40:42 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_n_respectinglimits(char **argv)
{
	int	n_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;

	n_of_philo = ft_atoi(argv[1]);
	time_to_die = ft_atoi(argv[2]);
	time_to_eat = ft_atoi(argv[3]);
	time_to_sleep = ft_atoi(argv[4]);
	if (n_of_philo > 200)
	{
		printf("Max 200 Philosophers allowed.\n");
		return (BAD_INPUT);
	}
	if (time_to_die < 60 || time_to_eat < 60 || time_to_sleep < 60)
	{
		printf("t_to_die, t_to_eat, t_to_sleep should be greater than 60.\n");
		return (BAD_INPUT);
	}
	return (VALID_INPUT);
}

/*Remember to skip the argv[0] becouse it is the name of the program.*/
static int	is_n_realnumber(int argc, char **argv)
{
	int		i;
	int		j;
	char	*msg_invalid_number;

	msg_invalid_number = "You did not insert a valid number.";
	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][0] == '0' && argv[i][1] != '\0')
			{
				printf("%s\n", msg_invalid_number);
				return (BAD_INPUT);
			}
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf("%s\n", msg_invalid_number);
				return (BAD_INPUT);
			}
		}
	}
	return (VALID_INPUT);
}

/*You can insert 4 or 5 inputs. That means 5 or 6 arguments 
 are allowed.*/
int	input_validation(int argc, char **argv)
{
	if (argc < 5)
	{
		printf("Too few arguments.\n");
		return (UNSUCCESSFUL_VALIDATION);
	}
	else if (argc > 6)
	{
		printf("Too much arguments.\n");
		return (UNSUCCESSFUL_VALIDATION);
	}
	if (is_n_realnumber(argc, argv) == NO)
		return (UNSUCCESSFUL_VALIDATION);
	if (is_n_respectinglimits(argv) == NO)
		return (UNSUCCESSFUL_VALIDATION);
	return (SUCCESSFUL_VALIDATION);
}

void	input_init(t_input *input, char **argv)
{
	input->n_of_phil = ft_atoi(argv[1]);
	input->time_to_die = ft_atoi(argv[2]);
	input->time_to_eat = ft_atoi(argv[3]);
	input->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		input->n_of_meals = ft_atoi(argv[5]);
	else
		input->n_of_meals = NO_MEALS_HAVE_BEEN_SPECIFIED;
}
