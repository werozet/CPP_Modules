/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:34:40 by wzielins          #+#    #+#             */
/*   Updated: 2025/09/25 18:20:20 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl harl;

	std::cout << "[DEBUG]"  << std::endl;
	harl.complain("DEBUG");

	std::cout << "[INFO]" << std::endl;
    harl.complain("INFO");

    std::cout << "[WARNING]" << std::endl;
    harl.complain("WARNING");

    std::cout << "[ERROR]" << std::endl;
    harl.complain("ERROR");

	/*std::cout << "[42]" << std::endl;
    harl.complain("42");*/

    return 0;
}