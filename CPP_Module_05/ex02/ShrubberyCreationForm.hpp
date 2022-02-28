/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:05:40 by bahn              #+#    #+#             */
/*   Updated: 2022/02/28 18:43:29 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include <iostream>
# include <string>
# include <fstream>

# include "Form.hpp"
# include "ASCII_ART.hpp"

class Form;

class ShrubberyCreationForm : public Form
{
private:
	
public:
	ShrubberyCreationForm(std::string const & target);
	ShrubberyCreationForm(const ShrubberyCreationForm& form);
	~ShrubberyCreationForm();

	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& form);

	virtual void	execute(Bureaucrat const & executer) const ;
};

#endif