/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:32:35 by wzielins          #+#    #+#             */
/*   Updated: 2025/10/15 13:41:35 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap noName;
    ClapTrap bot1("Bot1");
    ClapTrap bot2("Bot2");
    ClapTrap bot3(bot1);
    noName = bot1;

    for (int i = 0; i < 11; i++)
    {
        bot1.attack("Bot2");
        bot2.takeDamage(1);
        bot2.beRepaired(1);
    }
    ScavTrap noName1;
    ScavTrap Guardian1("Guardian");
    ScavTrap Guardian2(Guardian1);
    noName1 = Guardian1;

    Guardian1.attack("Bot1");
    bot1.takeDamage(20);
    bot1.beRepaired(1);
    Guardian1.takeDamage(15);
    Guardian1.beRepaired(10);
    Guardian1.guardGate();

    FragTrap noName2;
    FragTrap DudeBot1("DudeBot");
    FragTrap DudeBot2(DudeBot1);
    noName2 = DudeBot1;

    DudeBot1.attack("Bot1");
    bot1.takeDamage(30);
    bot1.beRepaired(1);
    DudeBot1.takeDamage(50);
    DudeBot1.beRepaired(20);
    DudeBot1.highFivesGuys();


    return 0;
}