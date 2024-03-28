/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:06:46 by fduzant           #+#    #+#             */
/*   Updated: 2024/03/21 12:41:38 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string &name, int signgrade, int execgrade) : _name(name), _signGrade(signgrade), _execGrade(execgrade)
{
	_signed = false;
	std::cout << "Form parametric constructor called" << std::endl;
	if (execgrade < 1 || signgrade < 1)
		throw GradeTooHighException();
	if (execgrade > 150 || signgrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &src) : _name(src._name), _signed(src._signed), _signGrade(src._signGrade), _execGrade(src._execGrade)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form()
{
	// std::cout << "Default Form deconstructor called" << std::endl;
}

Form &Form::operator=(const Form &src)
{
	if (this != &src)
	{
		_signed = src._signed;
	}
	return *this;
}

std::string Form::getName() const
{
	return (_name);
}

bool Form::getSigned() const
{
	return _signed;
}

int Form::getSignGrade() const
{
	return _signGrade;
}

int Form::getExecGrade() const
{
	return _execGrade;
}

void Form::beSigned(const Bureaucrat &src)
{
	if (src.getGrade() > _signGrade)
		throw Form::GradeTooLowException(); 
	_signed = true;
}

std::ostream &operator<<(std::ostream &o, const Form &src)
{
	o << src.getName() << " form: ";
	o << "Grade to sign: " << src.getSignGrade() << ". ";
	o << "Grade to execute: " << src.getExecGrade() << ".";
	return o;
}