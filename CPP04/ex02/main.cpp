/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 19:00:43 by wzielins          #+#    #+#             */
/*   Updated: 2025/10/15 14:15:27 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
const AAnimal* j = new Dog();
const AAnimal* i = new Cat();
delete j;//should not create a leak
delete i;
std::cout <<"MY TEST!!!"<<std::endl;
const int   numberOfAnimals = 4;
AAnimal *animals[numberOfAnimals];
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
