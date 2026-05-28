/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:23:12 by wzielins          #+#    #+#             */
/*   Updated: 2026/03/04 15:23:14 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <climits>
#include <cstdlib>
#include <cctype>

static bool parsePositiveInt(const std::string& token, int& out)
{
    if (token.empty())
        return false;

    for (size_t i = 0; i < token.size(); ++i)
    {
        if (!std::isdigit(token[i]))
            return false;
    }

    long value = std::strtol(token.c_str(), NULL, 10);
    if (value <= 0 || value > INT_MAX)
        return false;

    out = static_cast<int>(value);
    return true;
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::vector<int> numbers;

    for (int i = 1; i < argc; ++i)
    {
        std::istringstream iss(argv[i]);
        std::string token;

        while (iss >> token)
        {
            int num;
            if (!parsePositiveInt(token, num))
            {
                std::cerr << "Error" << std::endl;
                return 1;
            }
            numbers.push_back(num);
        }
    }

    if (numbers.empty())
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::cout << "Before:";
    for (size_t i = 0; i < numbers.size(); ++i)
        std::cout << " " << numbers[i];
    std::cout << std::endl;

    PmergeMe pm;

    clock_t startVec = clock();
    std::vector<int> vec(numbers);
    pm.sortVector(vec);
    clock_t endVec = clock();

    clock_t startDeq = clock();
    std::deque<int> deq(numbers.begin(), numbers.end());
    pm.sortDeque(deq);
    clock_t endDeq = clock();

    std::cout << "After:";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << " " << vec[i];
    std::cout << std::endl;

    double timeVec = 1000000.0 * (endVec - startVec) / CLOCKS_PER_SEC;
    double timeDeq = 1000000.0 * (endDeq - startDeq) / CLOCKS_PER_SEC;

    std::cout << "Time to process a range of " << numbers.size()
              << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << numbers.size()
              << " elements with std::deque  : " << timeDeq << " us" << std::endl;

    return 0;
}