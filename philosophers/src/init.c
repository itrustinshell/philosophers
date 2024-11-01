/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:39:39 by largenzi          #+#    #+#             */
/*   Updated: 2024/11/01 22:00:53 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void	validation_and_init(int argc, char **argv, t_input *input)
{
	input_validation(argc, argv);
	input_init(input, argv);
}
