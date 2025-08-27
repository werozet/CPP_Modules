/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:31:27 by wzielins          #+#    #+#             */
/*   Updated: 2025/08/27 14:31:38 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(const std::string& filename, const std::string& s1, const std:: string& s2)
	: _filename(filename), _s1(s1), _s2(s2) {}

Replace::~Replace() {}

bool Replace::processFile() const
{
	std::ifstream inputFile(_filename.c_str()); //do otwierania pliku w trybie odczytu
	//c_str do konwersji std:string na const char*
	if(!inputFile.is_open())
	{
		std::cerr << "Error: Could not open file " << _filename << std::endl;
		return false;
	}
	std::ofstream outputFile((_filename + ".replace").c_str()); //do tworzenia jesli nie ma i otwierania pliku w trybie zapisu
	if (!outputFile.is_open())
	{
		std::cerr << "Error: Could not create output file " << _filename << ".replace" << std::endl;
		return false;
	}
	std::string line;
	while (std::getline(inputFile, line))
	{
		size_t pos = 0;
		while ((pos = line.find(_s1, pos)) != std::string::npos)
		//size_t find(const std::string& str, size_t pos = 0) const; ta funckcja zwraca npos jeśli
		//nie znaleziono szukanego słowa, npos to takie jakby -1.
		{
			line.erase(pos, _s1.length()); //usuwa słowo o określonej długości
			line.insert(pos, _s2);
			pos += _s2.length();
		}
		outputFile << line << std::endl;
	}
	inputFile.close();
	outputFile.close();
	return true;
}