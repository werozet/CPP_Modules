/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:51:26 by wzielins          #+#    #+#             */
/*   Updated: 2025/08/28 18:51:45 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{
    protected:
        std::string type;

    public:
        AAnimal();
        AAnimal(const AAnimal& sourceObj);
        AAnimal& operator=(const AAnimal& sourceObj);
        virtual ~AAnimal();

        std::string getType() const;
        virtual void makeSound() const = 0;;
};

#endif