/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:07:45 by fduzant           #+#    #+#             */
/*   Updated: 2024/03/28 12:01:15 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void	testForm(AForm *form, Bureaucrat *boss, Bureaucrat *looser) {

	(void) looser;
	std::cout << *form << std::endl;
	// boss->executeForm(*form);
	boss->signForm(*form);
	// looser->executeForm(*form);
	boss->executeForm(*form);
}

int main( void )
{
	Bureaucrat	boss("LE BOSS", 1);
	Bureaucrat	looser("LE LOOSER", 150);
	AForm		*form;
	Intern		futurLooser;

	std::cout << std::endl;

	/* ************************************************************************** */

	std::cout << boss << std::endl;
	std::cout << looser << std::endl;
	
	std::cout << std::endl;

	/* ************************************************************************** */

	std::cout << "- SHRUBBERY CREATION FORM -" << std::endl;
	form = futurLooser.makeForm("shrubbery creation", "Dark oak");
	if (form != NULL) {

		testForm(form, &boss, &looser);
		delete form;
		std::cout << std::endl;
	}


	std::cout << "- ROBOTOMY REQUEST FORM -" << std::endl;
	form = futurLooser.makeForm("robotomy request", "Alfred");
	if (form != NULL) {

		testForm(form, &boss, &looser);
		delete form;
		std::cout << std::endl;
	}


	std::cout << "- PRESIDENTIAL PARDON FORM -" << std::endl;
	form = futurLooser.makeForm("presidential pardon", "Silvia");
	if (form != NULL) {

		testForm(form, &boss, &looser);
		delete form;
		std::cout << std::endl;
	}

	/* ************************************************************************** */

	std::cout << std::endl;
	
    return (0);
}