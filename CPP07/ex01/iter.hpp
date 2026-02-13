/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 14:53:44 by wzielins          #+#    #+#             */
/*   Updated: 2026/02/13 18:29:21 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "iostream"

template <typename T, typename F>
void iter(T* array, size_t lenght, F function)
{
	for (size_t i = 0; i < lenght; ++i)
	{
		function(array[i]);
	}
}