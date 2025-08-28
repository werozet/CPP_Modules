/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:37:15 by wzielins          #+#    #+#             */
/*   Updated: 2025/08/28 14:37:17 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

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
    FragTrap dudeBot1("dudeBot");
    FragTrap dudeBot2(dudeBot1);
    noName2 = dudeBot1;

    dudeBot1.attack("Bot1");
    bot1.takeDamage(30);
    bot1.beRepaired(1);
    dudeBot1.takeDamage(50);
    dudeBot1.beRepaired(20);
    dudeBot1.highFivesGuys();

    DiamondTrap noName3;
    DiamondTrap guardianDudeBot1("guardianDudeBot");
    DiamondTrap guardianDudeBot2(guardianDudeBot1);
    noName3 = guardianDudeBot1;

    guardianDudeBot1.attack("Bot2");
    bot2.takeDamage(30);
    bot2.beRepaired(1);
    guardianDudeBot1.takeDamage(50);
    guardianDudeBot1.beRepaired(20);
    guardianDudeBot1.guardGate();
    guardianDudeBot1.highFivesGuys();
    guardianDudeBot1.whoAmI();

    return 0;
}
/*
int main()
{
    ClapTrap bot1("Bot1");
    ClapTrap bot2("Bot2");

    for (int i = 0; i < 3; i++)
    {
        bot1.attack("Bot2");
        bot2.takeDamage(5);
        bot2.beRepaired(1);
    }
    return 0;
}*/