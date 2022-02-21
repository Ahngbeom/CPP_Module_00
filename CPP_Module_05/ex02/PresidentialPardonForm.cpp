/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:20:42 by bahn              #+#    #+#             */
/*   Updated: 2022/02/18 14:59:07 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const & target)
 : Form(target, 25, 5)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void	PresidentialPardonForm::execute(Bureaucrat const & executer) {
	if (executer.getGrade() < 1)
		throw GradeTooHighException("a grade required for executing is too high.");
	else if (executer.getGrade() > getExecuteGrade())
		throw GradeTooLowException("a grade required for executing is too low.");
	else {
		std::cout << GAVEL;
		std::cout << *this << " has been pardoned by Zafod Beeblebrox" << std::endl;
	}
}