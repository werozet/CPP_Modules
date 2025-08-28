/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:54:27 by wzielins          #+#    #+#             */
/*   Updated: 2025/08/28 18:54:36 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain has been created!" << std::endl;
}

Brain::Brain(const Brain& sourceObj)
{
    for (int i = 0; i < 100; ++i)
        ideas[i] = sourceObj.ideas[i];
    std::cout << "Brain has been copied!" << std::endl;
}

Brain& Brain::operator=(const Brain& sourceObj)
{
    if (this != &sourceObj)
    {
        for (int i = 0; i < 100; ++i) //deep copy
            ideas[i] = sourceObj.ideas[i];
    }
    std::cout << "Brain has been assigned!" << std::endl;
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain has been destroyed!" << std::endl;
}