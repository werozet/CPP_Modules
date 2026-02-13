/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 14:56:46 by wzielins          #+#    #+#             */
/*   Updated: 2026/02/13 18:26:09 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib> //for srand and rand
#include <stdexcept>

template <typename T>
class Array
{
	private:
		T* _array;
		unsigned int _size;

	public:
		Array() : _array(NULL), _size(0) {}
		Array(unsigned int n) : _array(new T[n]()), _size(n) {}
		Array(const Array& other) : _array(NULL), _size(0)
		{
			*this = other;
		}

		Array& operator=(const Array& other)
		{
			if (this != &other)
			{
				delete[] _array;
				_size = other.size();
				_array = new T[_size];
				for (unsigned int i = 0; i < _size; ++i)
				{
					_array[i] = other._array[i];
				}
			}
			return *this;
		}
		
		~Array()
		{
			delete[] _array;
		}

		T& operator[](unsigned int index)
		{
			if(index >= _size)
			{
				throw std::out_of_range("Index out of bounds");
			}
			return _array[index];
		}

		const T& operator[](unsigned int index) const
		{
			if(index >= _size)
			{
				throw std::out_of_range("Index out of bounds");
			}
			return _array[index];
		}

		unsigned int size() const
		{
			return _size;
		}
};