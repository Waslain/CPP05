/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:25:31 by fduzant           #+#    #+#             */
/*   Updated: 2024/03/20 20:21:19 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	public:
		AForm(const std::string &name, int signgrade, int execgrade);
		AForm(const AForm &copy);
		virtual ~AForm();

		AForm &operator=(const AForm &src);

		std::string getName() const;
		bool getSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;

		void beSigned(const Bureaucrat &src);
		virtual void execute(const Bureaucrat &executor) const = 0;
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() { return "Grade too high"; }
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() { return "Grade too low"; }
		};
		class FormNotSignedException : public std::exception {
			public:
				virtual const char* what() const throw() { return "Form is not signed"; }
		};
	private:
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _execGrade;
		AForm();
};

std::ostream &operator<<(std::ostream &str, const AForm &src);