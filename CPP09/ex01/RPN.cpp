/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:19:46 by wzielins          #+#    #+#             */
/*   Updated: 2026/03/04 15:19:59 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other)
{
    (void)other;
}

RPN& RPN::operator=(const RPN& other) 
{
    if (this != &other)
	{
    }
    return *this;
}

RPN::~RPN() {}

int RPN::processExpression(const std::string& expression) const
{
    std::stack<int> stack;
    for (size_t i = 0; i < expression.size(); ++i)
	{
        char token = expression[i];
        if (std::isspace(token)) 
		{
            continue;
        } 
		else if (std::isdigit(token)) 
		{
            stack.push(token - '0'); // convert digital for number
        } 
		else if (isOperator(token)) 
		{
            if (stack.size() < 2) 
			{
                throw std::runtime_error("Error");
            }
            int b = stack.top(); stack.pop(); //top-download value for top, pop-delete value for top
            int a = stack.top(); stack.pop();
            int result = executeOperation(token, a, b);
            stack.push(result);
        } else
		{
            throw std::runtime_error("Error");
        }
    }
    if (stack.size() != 1)
	{
        throw std::runtime_error("Error");
    }
    return stack.top();
}

bool RPN::isOperator(char c) 
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::executeOperation(char op, int a, int b) 
{
    switch (op) 
	{
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) 
			{
                throw std::runtime_error("Error");
            }
            return a / b;
        default:
            throw std::runtime_error("Error");
    }
}