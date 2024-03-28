/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:07:42 by fduzant           #+#    #+#             */
/*   Updated: 2024/03/27 22:07:44 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "Parametric RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy._target)
{
	std::cout << "Copy RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm deconstructor called" << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	#include <iostream>
	#include <cstdlib>

		std::cout << executor.getName() << " try to execute form '" << getName() << "'" << std::endl;
		if (getSigned() == false)
			throw AForm::FormNotSignedException();
		if (executor.getGrade() > getExecGrade())
			throw AForm::GradeTooLowException();
		std::cout << "Making drilling noises..." << std::endl;
		
		// Randomly determine if the operation is successful 50% of the time
		srand(time(0));
		bool success = (rand() % 2 == 0);

		if (success)
			std::cout << getTarget() << " was successfully robotomized." << std::endl;
		else
			std::cout << "The operation failed." << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	std::cout << "Copy assignement RobotomyRequestForm operator called" << std::endl;
	(void)src;
	return (*this);
}

const std::string &RobotomyRequestForm::getTarget() const
{
	return (_target);
}