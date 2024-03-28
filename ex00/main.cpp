/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:07:45 by fduzant           #+#    #+#             */
/*   Updated: 2024/03/19 11:08:16 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main( void ) {
	
	Bureaucrat boss("LE BOSS", 1);
	Bureaucrat looser("LE LOOSER", 150);
	try {
		Bureaucrat fraude("LA FRAUDE", 151);
	}
	catch (Bureaucrat::GradeTooHighException & e) {
		
		std::cout << "EXCEPTION: '" << e.what() << "'" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException & e) {
		std::cout << "EXCEPTION: '" << e.what() << "'" << std::endl;
	}

	std::cout << std::endl;

    try {
        std::cout << boss << std::endl;
		boss.decrementGrade();
		std::cout << boss << std::endl;
        boss.incrementGrade();
		std::cout << boss << std::endl;
        boss.incrementGrade();
		std::cout << boss << std::endl;
		boss.decrementGrade();
    }
	catch (Bureaucrat::GradeTooHighException & e) {
        
		std::cout << "EXCEPTION: '" << e.what() << "'" << std::endl;
    }

	std::cout << std::endl;

	try {

        std::cout << looser << std::endl;
		looser.incrementGrade();
		std::cout << looser << std::endl;
        looser.decrementGrade();
		std::cout << looser << std::endl;
        looser.decrementGrade();
		std::cout << looser << std::endl;
		looser.incrementGrade();
    }
	catch (Bureaucrat::GradeTooLowException & e) {
		
        std::cout << "EXCEPTION: '" << e.what() << "'" << std::endl;
    }
	
    return (0);
}