/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:07:45 by fduzant           #+#    #+#             */
/*   Updated: 2024/03/21 12:42:40 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void )
{
	Bureaucrat	boss("LE BOSS", 2);
	Bureaucrat	looser("LE LOOSER", 3);
	Form		superContract("The super contract", 2, 1);
	
	std::cout << std::endl;

	std::cout << boss << std::endl;
	std::cout << looser << std::endl;
	std::cout << superContract << std::endl;
	
	std::cout << std::endl;

	looser.signForm(superContract);
	boss.signForm(superContract);
	
	std::cout << std::endl;
    return (0);
}