/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:14:44 by wzielins          #+#    #+#             */
/*   Updated: 2026/02/10 15:26:36 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "Unknown.hpp"
#include <iostream>

int main() {
    Base* randomObj = Base::generate();
    std::cout << "Identify by pointer: ";
    Base::identify(randomObj);
    std::cout << "Identify by reference: ";
    Base::identify(*randomObj);
    delete randomObj;

	Base* unknownObj = new Unknown();
    std::cout << "Identify by pointer: ";
    Base::identify(unknownObj);
    std::cout << "Identify by reference: ";
    Base::identify(*unknownObj);
    delete unknownObj;

	Base* emptyObj = NULL;
    std::cout << "Identify by pointer: ";
    Base::identify(emptyObj);
	if (emptyObj)
	{
		std::cout << "Identify by reference: ";
    	Base::identify(*emptyObj);
	}
	else
	{
		std::cout << "Identify by reference: Cannot dereference NULL" << std::endl;
	}
    return 0;
}