/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:32:37 by wzielins          #+#    #+#             */
/*   Updated: 2025/08/27 14:32:39 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int main(int argc, char **argv)
{
	if(argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	struct stat fileStat;
	if (stat(filename.c_str(), &fileStat) == 0 && fileStat.st_size == 0)
	//The stat function retrieves information about the file, including its size
	{
		std::cerr << "Error: The file is empty." << std::endl;
		return (1);
	}
	if(s1.empty())
	{
		std::cerr << "Error: s1 cannot be an empty string." << std::endl;
		return (1); 
	}
	Replace replacer(filename, s1, s2);
	if (!replacer.processFile())
	{
		std::cerr << "Error: Failed to process file." << std::endl;
		return (1);
	}
	std::cout << "File processed successfully. Output: " << filename << ".replace" << std::endl;
	return (0);
}