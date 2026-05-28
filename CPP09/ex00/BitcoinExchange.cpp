/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:16:50 by wzielins          #+#    #+#             */
/*   Updated: 2026/03/04 15:17:03 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::string trim(const std::string& str) 
{
    size_t start = str.find_first_not_of(" \t\n\r"); // /r same like /n but when create file in windows
    size_t end = str.find_last_not_of(" \t\n\r");
    if (start == std::string::npos)
        return "";
    else
        return str.substr(start, end - start + 1);
}

bool isValidDate(const std::string& date) 
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') 
        return false;
    int year = std::atoi(date.substr(0, 4).c_str()); //c_str because I need const char*, not std::string
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    if (year < 2009 || year > 2025) 
        return false;
    if (month < 1 || month > 12) 
        return false;
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        daysInMonth[1] = 29;
    if (day < 1 || day > daysInMonth[month - 1]) 
        return false;
    return true;
}

bool isValidValue(const std::string& value, std::string& errorMessage) 
{
    if (value.empty())
    {
		errorMessage = "Error: bad input => " + value;
        return false;
	}
	bool hasDot = false;
	size_t i = 0;
	if (value[0] == '-')
    {
        i = 1;
    }
	for (; i < value.size(); ++i) 
    {
        if (value[i] == '.') 
        {
            if (hasDot)
			{
				errorMessage = "Error: bad input => " + value;
				return false;
			}
            hasDot = true;
        } 
        else if (!std::isdigit(value[i]))
		{
			errorMessage = "Error: bad input => " + value;
            return false;
		}
    }
	if (value[value.size() - 1] == '.') //check the last position isnt dot
	{
		errorMessage = "Error: bad input => " + value;
        return false;
	}
	double num = std::atof(value.c_str());
	if (num < 0)
	{
		errorMessage = "Error: not a positive number.";
        return false;
	}
	if (num > 1000) 
    {
        errorMessage = "Error: too large a number.";
        return false;
    }
	return true;
}

std::map<std::string, double> loadExchangeRates(const std::string& filename) 
{
    std::map<std::string, double> exchangeRates;
    std::ifstream file(filename.c_str()); //load file to map
    if (!file.is_open()) 
    {
        std::cerr << "Error: could not open database file." << std::endl;
        return exchangeRates;
    }
    std::string line;
    while (std::getline(file, line)) 
    {
        std::istringstream ss(line); //input only like cin, we get stream with line is string 
        std::string date;
        double rate;

        if (std::getline(ss, date, ',') && ss >> rate) //<- divide line for date and rate, ss>>rate change string for double
        {
            exchangeRates[date] = rate; //key=date, value=rate
        }
    }
    return exchangeRates;
}

double getExchangeRate(const std::map<std::string, double>& exchangeRates, const std::string& date)  //look for date in map
{
    std::map<std::string, double>::const_iterator it = exchangeRates.lower_bound(date);
    if (it == exchangeRates.end() || it->first != date) //it->first != date -is not equal our date
    {
        if (it == exchangeRates.begin()) 
        {
            return 0.0;
        }
        --it;
    }
    return it->second; //return value for date
}