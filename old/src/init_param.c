/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:39:39 by largenzi          #+#    #+#             */
/*   Updated: 2024/07/28 10:05:10 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* this function inizialize  the array of parameters.*/
void	pmt_array_init(t_thread_pmt *pmt, t_input input)
{
	pmt_array_init_general(pmt, input);
	pmt_array_init_death_management(pmt, input);
	pmt_array_init_meals_management(pmt, input);
}
