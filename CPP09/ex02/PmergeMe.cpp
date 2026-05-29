/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:22:00 by wzielins          #+#    #+#             */
/*   Updated: 2026/05/29 17:27:02 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) { (void)other; }
PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    (void)other;
    return *this;
}
PmergeMe::~PmergeMe() {}

void PmergeMe::sortVector(std::vector<int>& vec)
{
    if (vec.size() < 2)
        return;
    fordJohnsonSortVector(vec);
}

void PmergeMe::sortDeque(std::deque<int>& deq)
{
    if (deq.size() < 2)
        return;
    fordJohnsonSortDeque(deq);
}

void PmergeMe::fordJohnsonSortVector(std::vector<int>& vec)
{
    size_t n = vec.size();
    if (n < 2)
        return;

    std::vector<int> mainChain;
    std::vector<int> pending;
    mainChain.reserve((n + 1) / 2);
    pending.reserve((n + 1) / 2);

    size_t i = 0;
    for (; i + 1 < n; i += 2)
    {
        int a = vec[i];
        int b = vec[i + 1];
        if (a < b)
        {
            mainChain.push_back(b);
            pending.push_back(a);
        }
        else
        {
            mainChain.push_back(a);
            pending.push_back(b);
        }
    }
    if (i < n)
        pending.push_back(vec[i]);

    fordJohnsonSortVector(mainChain);

    std::vector<size_t> order = jacobsthalIndices(pending.size());
    for (size_t k = 0; k < order.size(); ++k)
        binaryInsertVector(mainChain, pending[order[k]]);

    vec = mainChain;
}

void PmergeMe::fordJohnsonSortDeque(std::deque<int>& deq)
{
    size_t n = deq.size();
    if (n < 2)
        return;

    std::deque<int> mainChain;
    std::deque<int> pending;

    size_t i = 0;
    for (; i + 1 < n; i += 2)
    {
        int a = deq[i];
        int b = deq[i + 1];
        if (a < b)
        {
            mainChain.push_back(b);
            pending.push_back(a);
        }
        else
        {
            mainChain.push_back(a);
            pending.push_back(b);
        }
    }
    if (i < n)
        pending.push_back(deq[i]);

    fordJohnsonSortDeque(mainChain);

    std::vector<size_t> order = jacobsthalIndices(pending.size());
    for (size_t k = 0; k < order.size(); ++k)
        binaryInsertDeque(mainChain, pending[order[k]]);

    deq = mainChain;
}

std::vector<size_t> PmergeMe::jacobsthalIndices(size_t n) const
{
    std::vector<size_t> order;
    if (n == 0)
        return order;

    // Generate Jacobsthal numbers: J(0)=0, J(1)=1, J(2)=3, J(3)=5, J(4)=11...
    // Formula: J(n) = J(n-1) + 2*J(n-2)
    std::vector<size_t> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);

    while (true)
    {
        size_t next = jacobsthal.back() + 2 * jacobsthal[jacobsthal.size() - 2];
        if (next > n)
            break;
        jacobsthal.push_back(next);
    }

    // Insert pending[0] first (smallest element from first pair)
    order.push_back(0);
    if (n == 1)
        return order;

    // For each Jacobsthal interval, insert elements in descending order
    // This ensures optimal number of comparisons with binary search
    size_t prev = 1;
    for (size_t i = 2; i < jacobsthal.size(); ++i)
    {
        size_t current = jacobsthal[i];
        if (current > n)
            current = n;

        // Insert elements from (prev+1) to current in descending order
        for (size_t idx = current; idx > prev; --idx)
        {
            if (idx - 1 < n)
                order.push_back(idx - 1);
        }
        prev = current;
    }

    // Insert any remaining elements not covered by Jacobsthal intervals
    for (size_t idx = n; idx > prev; --idx)
    {
        order.push_back(idx - 1);
    }

    return order;
}

void PmergeMe::binaryInsertVector(std::vector<int>& vec, int value)
{
    size_t left = 0;
    size_t right = vec.size();

    while (left < right)
    {
        size_t mid = left + (right - left) / 2;
        if (value < vec[mid])
            right = mid;
        else
            left = mid + 1;
    }
    vec.insert(vec.begin() + left, value);
}

void PmergeMe::binaryInsertDeque(std::deque<int>& deq, int value)
{
    size_t left = 0;
    size_t right = deq.size();

    while (left < right)
    {
        size_t mid = left + (right - left) / 2;
        if (value < deq[mid])
            right = mid;
        else
            left = mid + 1;
    }
    deq.insert(deq.begin() + left, value);
}