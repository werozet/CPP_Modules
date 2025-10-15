/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:44:15 by wzielins          #+#    #+#             */
/*   Updated: 2025/10/15 14:04:05 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
        Brain* brain;
    public:
        Cat();
        Cat(const Cat& sourceObj);
        Cat& operator=(const Cat& sourceObj);
        virtual ~Cat();

        void makeSound() const;
};

#endif