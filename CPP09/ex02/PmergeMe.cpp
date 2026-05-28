/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:22:00 by wzielins          #+#    #+#             */
/*   Updated: 2026/03/04 15:22:14 by wzielins         ###   ########.fr       */
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

    order.push_back(0);
    if (n == 1)
        return order;

    std::vector<size_t> jac;
    jac.push_back(1);
    jac.push_back(3);

    while (jac.back() + 2 * jac[jac.size() - 2] < n)
        jac.push_back(jac.back() + 2 * jac[jac.size() - 2]);

    size_t processed = 1;
    for (size_t i = 0; i < jac.size(); ++i)
    {
        size_t end = jac[i];
        if (end > n)
            end = n;

        for (size_t idx = end; idx > processed; --idx)
            order.push_back(idx - 1);

        processed = end;
    }

    if (processed < n)
    {
        for (size_t idx = n; idx > processed; --idx)
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