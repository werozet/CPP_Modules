/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 14:47:29 by wzielins          #+#    #+#             */
/*   Updated: 2026/03/03 17:19:25 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T> //this is a tamplate function
void swap(T& a, T& b)
{
	T temp = a;//temporary variable to hold the value of a
	a = b;
	b = temp;
}

template <typename T>
const T& min(T& a, T& b)
{
	return (a < b) ? a : b;
}

template <typename T>
const T& max(T& a, T& b)
{
	return (a > b) ? a : b;
}