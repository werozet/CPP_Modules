/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:22:42 by wzielins          #+#    #+#             */
/*   Updated: 2026/03/05 16:08:31 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <cstddef>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <ctime>

class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void sortVector(std::vector<int>& vec);
    void sortDeque(std::deque<int>& deq);

private:
    void fordJohnsonSortVector(std::vector<int>& vec);
    void fordJohnsonSortDeque(std::deque<int>& deq);

    std::vector<size_t> jacobsthalIndices(size_t n) const;

    void binaryInsertVector(std::vector<int>& vec, int value);
    void binaryInsertDeque(std::deque<int>& deq, int value);
};

#endif