/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:49:04 by wzielins          #+#    #+#             */
/*   Updated: 2025/10/15 14:09:51 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* j = new Dog();
const Animal* i = new Cat();
delete j;//should not create a leak, virtual destructor
delete i;
std::cout <<"MY TEST!!!"<<std::endl;
const int   numberOfAnimals = 4;
Animal *animals[numberOfAnimals];
for (int i = 0; i < numberOfAnimals / 2; ++i)
    animals[i] = new Dog();
for (int i = numberOfAnimals / 2; i < numberOfAnimals; ++ i)
    animals[i] = new Cat();
for (int i = 0; i < numberOfAnimals; i ++)
    delete animals[i];
std::cout <<"TEST DEEP COPY!!!"<<std::endl;
Dog dog1;
Dog dog2 = dog1;
Dog dog3;
dog3 = dog1;
Cat cat1;
Cat cat2 = cat1;
Cat cat3;
cat3 = cat1;
return 0;
}