/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:07:45 by fduzant           #+#    #+#             */
/*   Updated: 2024/03/27 22:07:23 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void )
{
	Bureaucrat				boss("LE BOSS", 1);
	Bureaucrat				looser("LE LOOSER", 150);
	ShrubberyCreationForm	shrubberyCreationForm("BigTree");
	RobotomyRequestForm		RobotomyRequestForm("Joseph");
	PresidentialPardonForm	PresidentialPardonForm("Kevin");

	std::cout << std::endl;

	/* ************************************************************************** */

	std::cout << boss << std::endl;
	std::cout << looser << std::endl;
	std::cout << shrubberyCreationForm << std::endl;
	std::cout << RobotomyRequestForm << std::endl;
	std::cout << PresidentialPardonForm << std::endl;

	std::cout << std::endl;

	/* ************************************************************************** */

	std::cout << "- SHRUBBERY CREATION FORM -" << std::endl;
	boss.executeForm(shrubberyCreationForm);
	boss.signForm(shrubberyCreationForm);
	looser.executeForm(shrubberyCreationForm);
	boss.executeForm(shrubberyCreationForm);
	
	std::cout << std::endl;

	/* ************************************************************************** */

	std::cout << "- ROBOTOMY REQUEST FORM -" << std::endl;
	boss.executeForm(RobotomyRequestForm);
	boss.signForm(RobotomyRequestForm);
	looser.executeForm(RobotomyRequestForm);
	boss.executeForm(RobotomyRequestForm);

	std::cout << std::endl;
	
	/* ************************************************************************** */

	std::cout << "- PRESIDENTIAL PARDON FORM -" << std::endl;
	boss.executeForm(PresidentialPardonForm);
	boss.signForm(PresidentialPardonForm);
	looser.executeForm(PresidentialPardonForm);
	boss.executeForm(PresidentialPardonForm);

	std::cout << std::endl;
	/* ************************************************************************** */

    return (0);
}