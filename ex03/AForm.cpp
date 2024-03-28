/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:06:46 by fduzant           #+#    #+#             */
/*   Updated: 2024/03/21 12:41:38 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string &name, int signgrade, int execgrade) : _name(name), _signGrade(signgrade), _execGrade(execgrade)
{
	_signed = false;
	std::cout << "AForm parametric constructor called" << std::endl;
	if (execgrade < 1 || signgrade < 1)
		throw GradeTooHighException();
	if (execgrade > 150 || signgrade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &src) : _name(src._name), _signed(src._signed), _signGrade(src._signGrade), _execGrade(src._execGrade)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm()
{
	// std::cout << "Default AForm deconstructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &src)
{
	if (this != &src)
	{
		_signed = src._signed;
	}
	return *this;
}

std::string AForm::getName() const
{
	return (_name);
}

bool AForm::getSigned() const
{
	return _signed;
}

int AForm::getSignGrade() const
{
	return _signGrade;
}

int AForm::getExecGrade() const
{
	return _execGrade;
}

void AForm::beSigned(const Bureaucrat &src)
{
	if (src.getGrade() > _signGrade)
		throw AForm::GradeTooLowException(); 
	_signed = true;
}

std::ostream &operator<<(std::ostream &o, const AForm &src)
{
	o << src.getName() << " AForm: ";
	o << "Grade to sign: " << src.getSignGrade() << ". ";
	o << "Grade to execute: " << src.getExecGrade() << ".";
	return o;
}