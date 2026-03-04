/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 14:54:18 by wzielins          #+#    #+#             */
/*   Updated: 2026/03/03 18:32:20 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

// Simple functions for basic tests
void printInt(int i)
{
    std::cout << i << " ";
}

void printChar(char c)
{
    std::cout << c << " ";
}

// Template function - takes argument by const reference
template <typename T>
void printElement(const T& element)
{
    std::cout << element << " ";
}

// Template function - takes argument by non-const reference and modifies it
template <typename T>
void incrementElement(T& element)
{
    element++;
}

// Function that takes const reference (read-only)
void printConstString(const std::string& str)
{
    std::cout << str << " ";
}

// Function that takes non-const reference (can modify)
void toUpperFirstChar(std::string& str)
{
    if (!str.empty() && str[0] >= 'a' && str[0] <= 'z')
        str[0] = str[0] - 32;
}

int main()
{
    std::cout << "=== Test 1: Basic functions with int and char ===" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};

    std::cout << "Integer array: ";
    iter(intArray, 5, printInt);
    std::cout << std::endl;

    std::cout << "Character array: ";
    iter(charArray, 5, printChar);
    std::cout << std::endl;

    std::cout << "\n=== Test 2: Template function with const reference ===" << std::endl;
    std::cout << "Integer array with template: ";
    iter(intArray, 5, printElement<int>);
    std::cout << std::endl;

    std::cout << "Character array with template: ";
    iter(charArray, 5, printElement<char>);
    std::cout << std::endl;

    double doubleArray[] = {1.1, 2.2, 3.3, 4.4};
    std::cout << "Double array with template: ";
    iter(doubleArray, 4, printElement<double>);
    std::cout << std::endl;

    std::cout << "\n=== Test 3: Template function with non-const reference (modify) ===" << std::endl;
    int modArray[] = {10, 20, 30, 40, 50};
    std::cout << "Before increment: ";
    iter(modArray, 5, printElement<int>);
    std::cout << std::endl;

    iter(modArray, 5, incrementElement<int>);
    std::cout << "After increment:  ";
    iter(modArray, 5, printElement<int>);
    std::cout << std::endl;

    std::cout << "\n=== Test 4: String array with const and non-const ===" << std::endl;
    std::string stringArray[] = {"hello", "world", "from", "iter"};
    
    std::cout << "Original strings: ";
    iter(stringArray, 4, printConstString);
    std::cout << std::endl;

    iter(stringArray, 4, toUpperFirstChar);
    std::cout << "After uppercase:  ";
    iter(stringArray, 4, printConstString);
    std::cout << std::endl;

    return 0;
}