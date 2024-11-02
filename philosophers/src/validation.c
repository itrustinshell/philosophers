/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:52:10 by largenzi          #+#    #+#             */
/*   Updated: 2024/11/02 17:58:40 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_input_message(char **argv)
{
	if (ft_atoi(argv[1]) > 200)
	{
		printf("Max 200 Philosophers allowed.\n");
		exit(1);
	}
	if (ft_atoi(argv[2]) < 60 || ft_atoi(argv[3]) < 60 || ft_atoi(argv[4]) < 60)
	{
		printf("t_to_die, t_to_eat, t_to_sleep not greater than 60.\n");
		exit(1);
	}
}

void	check_numbers(int argc, char **argv)
{
	int		i;
	int		j;
	char	*msg_invalid_number;

	msg_invalid_number = "You should insert only valid number.";
	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][0] == '0' && argv[i][1] != '\0')
			{
				printf("%s\n", msg_invalid_number);
				exit(1);
			}
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf("%s\n", msg_invalid_number);
				exit(1);
			}
			j++;
		}
	}
	error_input_message(argv);
}

void	input_validation(int argc, char **argv)
{
	if (argc < 5)
	{
		printf("Too few arguments.\n");
		exit(1);
	}
	if (argc > 6)
	{
		printf("Too much arguments.\n");
		exit(1);
	}
	check_numbers(argc, argv);
}
