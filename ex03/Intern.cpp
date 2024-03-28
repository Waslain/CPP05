/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:54:56 by fduzant           #+#    #+#             */
/*   Updated: 2024/03/28 11:57:46 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Default Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = copy;
}

Intern::~Intern()
{
	std::cout << "Intern deconstructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &src)
{
	std::cout << "Intern assignation operator called" << std::endl;
	(void)src;
	return (*this);
}

AForm *Intern::createPresidentialPardonForm(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::createRobotomyRequestForm(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createShrubberyCreationForm(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}


AForm *Intern::makeForm(const std::string form_name, const std::string &target)
{
	// without if/else forest
	AForm *form = NULL;
	AForm *(Intern::*form_creator[3])(const std::string &) = {
		&Intern::createShrubberyCreationForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm
	};
	std::string form_names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	for(int i = 0; i < 3; i++)
	{
		if (form_name == form_names[i])
		{
			form = (this->*form_creator[i])(target);
			std::cout << "Intern creates " << form_name << " form" << std::endl;
			return (form);
		}
	}
	std::cout << "Intern could not create form " << form_name << std::endl;
	return (NULL);

}