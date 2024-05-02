/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:43:03 by cnascime          #+#    #+#             */
/*   Updated: 2024/05/02 04:53:25 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Bureaucrat;

class AForm {
	private:
		const std::string	name_;
		std::string			target_;
		bool				is_signed_;
		std::string			signatory_;
		const unsigned int	signing_grade_;
		const unsigned int	execution_grade_;

	public:
		AForm(void);
		AForm(const std::string name);
		AForm(const std::string name, const std::string target);
		AForm(const std::string name, const int signing_grade, const int execution_grade);
		AForm(const std::string name, const std::string target, const int signing_grade, const int execution_grade);
		AForm(const AForm &copy);
		AForm &operator=(const AForm &copy);
		virtual ~AForm(void);
		
		std::string		getName(void) const;
		std::string		getTarget(void) const;
		std::string		getSignatory(void) const;
		bool			getSignature(void) const;
		unsigned int	getSigningGrade(void) const;
		unsigned int	getExecutionGrade(void) const;

		void beSigned(const Bureaucrat &bureaucrat);
		void execute(const Bureaucrat &executor) const;
		virtual void doAction(const Bureaucrat &executor) const = 0;

		class UnsignedFormException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &output, const AForm &rhs);
