/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:38:47 by fduzant           #+#    #+#             */
/*   Updated: 2024/03/27 21:49:37 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "Parametric ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy._target)
{
	std::cout << "Copy ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	std::cout << executor.getName() << " try to execute form '" << getName() << "'" << std::endl;
	if (getSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw AForm::GradeTooLowException();
	std::ofstream file ((_target + "_shrubbery").c_str());
	if (!file.is_open()) {
		std::cout << executor.getName() << " couldn't execute form '" << getName() << "' cause of an error at file's creation" << std::endl;
		return;
	}

	file << "   *\n";
	file << "  ***\n";
	file << " *****\n";
	file << "*******\n";
	file << "  |||\n";
	file << "  |||\n";

	file.close();
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	std::cout << "Copy assignement ShrubberyCreationForm operator called" << std::endl;
	(void)src;
	return (*this);
}

const std::string &ShrubberyCreationForm::getTarget() const
{
	return (_target);
}