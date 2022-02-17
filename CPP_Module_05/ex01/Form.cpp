/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:46:22 by bahn              #+#    #+#             */
/*   Updated: 2022/02/18 00:48:19 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string name, const int signGrade, const int executeGrade) 
	: _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (_signGrade < 1 || _executeGrade < 1) {
		if (_signGrade < 1 && _executeGrade < 1)
			throw GradeTooHighException("Standard grade required for execution and signing is too high.");
		else if (_signGrade < 1)
			throw GradeTooHighException("Standard grade required for signing is too high.");
		else
			throw GradeTooHighException("Standard grade required for execution is too high.");
	}
	else if (_signGrade > 150 || _executeGrade > 150) {
		if (_signGrade > 150 && _executeGrade > 150)
			throw GradeTooLowException("Standard grade required for execution and signing is too low.");
		else if (_signGrade > 150)
			throw GradeTooLowException("Standard grade required for signing is too low.");
		else
			throw GradeTooLowException("Standard grade required for execution is too low.");
	}
}

Form::~Form()
{
}

std::string	Form::getName( void ) const {
	return (_name);
}

int	Form::getSignGrade( void ) const {
	return (_signGrade);
}

int	Form::getExecuteGrade( void ) const {
	return (_executeGrade);
}

bool	Form::getSigned( void ) const  {
	return (_signed);
}

void	Form::beSigned(Bureaucrat& bureau) {
	_signed = false;
	if (bureau.getGrade() <= getSignGrade() && bureau.getGrade() >= 1)
		_signed = true;
	else if (bureau.getGrade() < 1)
		throw GradeTooHighException("A grade required for signing is too high.");
	else
		throw GradeTooLowException("A grade required for signing is too low.");
}

Form::GradeTooHighException::GradeTooHighException(std::string error) : _error(error) {

}

Form::GradeTooHighException::~GradeTooHighException() _GLIBCXX_NOTHROW {
	
}

const char* Form::GradeTooHighException::what() const throw() {
	return (_error.c_str());
}


Form::GradeTooLowException::GradeTooLowException(std::string error) : _error(error) {
	
}
		
Form::GradeTooLowException::~GradeTooLowException() _GLIBCXX_NOTHROW {
	
}

const char* Form::GradeTooLowException::what() const throw() {
	return (_error.c_str());
}

std::ostream&	operator<<(std::ostream& ostrm, Form& form) {
	ostrm << "<" + form.getName() + ">";
	return (ostrm);
}
