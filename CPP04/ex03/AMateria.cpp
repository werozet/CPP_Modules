/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 19:02:49 by wzielins          #+#    #+#             */
/*   Updated: 2025/08/28 19:02:58 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type("unknown AMateria") {}

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria::AMateria(const AMateria& sourceObj) : type(sourceObj.type) {}

AMateria& AMateria::operator=(const AMateria& sourceObj)
{
    if (this != &sourceObj)
        type = sourceObj.type;
    return *this;
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const
{
    return type;
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}