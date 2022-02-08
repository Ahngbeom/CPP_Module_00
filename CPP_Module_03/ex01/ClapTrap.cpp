/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:52:43 by bahn              #+#    #+#             */
/*   Updated: 2022/02/08 21:49:33 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "[ClapTrap] Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) \
	: name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "[ClapTrap] Name constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "[ClapTrap] Deconstructor called" << std::endl;
}

void ClapTrap::attack(std::string const & target) {
	std::cout << "ClapTrap <" << this->name << \
				"> attack <" << target << \
				">, causing <" << this->attackDamage << "> points of damage!" \
				<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if ((unsigned int)hitPoints <= amount)
		this->hitPoints = 0;
	else
		this->hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	this->hitPoints += amount;
}