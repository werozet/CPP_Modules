/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:32:09 by wzielins          #+#    #+#             */
/*   Updated: 2025/08/27 14:32:17 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>

class Replace
{
	private:
		std::string _filename;
		std::string _s1;
		std::string _s2;
	public:
		Replace(const std::string& filename, const std::string& s1, const std::string& s2);
		~Replace();

		bool processFile() const;
};

#endif