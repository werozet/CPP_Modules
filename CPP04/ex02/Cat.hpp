/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:56:47 by wzielins          #+#    #+#             */
/*   Updated: 2025/08/28 18:56:55 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
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