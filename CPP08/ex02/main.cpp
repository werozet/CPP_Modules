/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:59:51 by wzielins          #+#    #+#             */
/*   Updated: 2026/02/17 12:59:52 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

// int main()
// {
// MutantStack<int> mstack;
// mstack.push(5);
// mstack.push(17);
// std::cout << mstack.top() << std::endl;
// mstack.pop();
// std::cout << mstack.size() << std::endl;
// mstack.push(3);
// mstack.push(5);
// mstack.push(737);
// //[...]
// mstack.push(0);
// MutantStack<int>::iterator it = mstack.begin();
// MutantStack<int>::iterator ite = mstack.end();
// ++it;
// --it;
// while (it != ite)
// {
// std::cout << *it << std::endl;
// ++it;
// }
// std::stack<int> s(mstack);
// return 0;
// }

int main()
{
    // Test MutantStack
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top element: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Stack size after pop: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    std::cout << "MutantStack elements:" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack); // Copy MutantStack to std::stack
    std::cout << "Copied stack size: " << s.size() << std::endl;
    // Comparison with std::list
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    lst.pop_back();
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    std::cout << "List elements:" << std::endl;
    for (std::list<int>::iterator lit = lst.begin(); lit != lst.end(); ++lit)
    {
        std::cout << *lit << std::endl;
    }
    // Test empty stack
    MutantStack<int> emptyStack;
    std::cout << "Empty stack size: " << emptyStack.size() << std::endl;
    if (emptyStack.begin() == emptyStack.end())
    {
        std::cout << "Empty stack iterators are equal (begin == end)." << std::endl;
    }
    // Test large stack
    MutantStack<int> largeStack;
    for (int i = 0; i < 1000; ++i)
    {
        largeStack.push(i);
    }
    std::cout << "Large stack size: " << largeStack.size() << std::endl;
    std::cout << "First 10 elements of large stack:" << std::endl;
    MutantStack<int>::iterator largeIt = largeStack.begin();
    for (int i = 0; i < 10 && largeIt != largeStack.end(); ++i, ++largeIt)
    {
        std::cout << *largeIt << std::endl;
    }
    return 0;
}