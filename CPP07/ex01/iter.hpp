/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 14:53:44 by wzielins          #+#    #+#             */
/*   Updated: 2026/03/03 18:47:13 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "iostream"

template <typename T, typename F>
void iter(T* array, size_t length, F function)
{
	for (size_t i = 0; i < length; ++i)
	{
		function(array[i]);
	}
}