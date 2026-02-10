/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:38:01 by wzielins          #+#    #+#             */
/*   Updated: 2026/02/10 14:42:40 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main() 
{
    Data originalData;
	originalData.value = 42;
	originalData.name = "Example";
    //Data originalData = {42, "Example"};
    Data* originalPtr = &originalData;
    std::cout << "Original Data:" << "Value: " << originalPtr->value 
			<< ", Name:" << originalPtr->name;
    uintptr_t raw = Serializer::serialize(originalPtr);
    std::cout << ", Serialized value (uintptr_t): " << raw << std::endl;
    Data* deserializedPtr = Serializer::deserialize(raw);
    std::cout << "Deserialized Data:" << "Value: " << deserializedPtr->value 
			<< ", Name: " << deserializedPtr->name << std::endl;
    std::cout << "Pointer comparison: ";
    if (originalPtr == deserializedPtr)
	{
        std::cout << "Pointers match!" << std::endl;
    } 
	else 
	{
        std::cout << "Pointers do not match!" << std::endl;
    }
	deserializedPtr->value = 77;
    deserializedPtr->name = "Change Example";
    std::cout << "Change Deserialized Data:" 
              << " Value: " << deserializedPtr->value 
              << ", Name: " << deserializedPtr->name << std::endl;

    return 0;
}