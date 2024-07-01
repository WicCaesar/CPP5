/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:13:21 by cnascime          #+#    #+#             */
/*   Updated: 2024/06/28 14:15:31 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class AForm;

class Bureaucrat {
	private:
		const std::string	name_;
		unsigned int		grade_;

	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &copy);
		Bureaucrat &operator++(void);
		Bureaucrat &operator--(void);
		~Bureaucrat(void);

		const std::string	getName(void) const;
		unsigned int		getGrade(void) const;

		int grade_up(void);
		int grade_down(void);
		void signForm(AForm &form) const;
		void executeForm(const AForm &form) const;

		// Creating customised exception classes, inherited from the standard.
		// const char *what is the default parameter whose output identifies
		// which exception has been reached, here implemented on the .cpp file.
		// throw() is only used in C++98. Use the noexcept specifier instead.
		// It means that this function will not throw an exception.
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Esse é o maior canalha de todos. Gasolina nele!");
				};
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &output, const Bureaucrat &rhs);
