/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:17:31 by wzielins          #+#    #+#             */
/*   Updated: 2026/03/04 15:17:46 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <map>
#include <sstream>

std::string trim(const std::string& str);
bool isValidDate(const std::string& date);
bool isValidValue(const std::string& value, std::string& errorMessage);
std::map<std::string, double> loadExchangeRates(const std::string& filename);
double getExchangeRate(const std::map<std::string, double>& exchangeRates, const std::string& date);

#endif