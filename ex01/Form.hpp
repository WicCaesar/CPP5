/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:43:03 by cnascime          #+#    #+#             */
/*   Updated: 2024/04/22 02:38:53 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Bureaucrat;

class Form {
	private:
		const std::string	name_;
		bool				is_signed_;
		std::string			signatory_;
		const int			signing_grade_;
		const int			execution_grade_;

	public:
		Form(void);
		Form(const std::string name, const int signing_grade, const int execution_grade);
		Form(const Form &copy);
		Form &operator=(const Form &copy);
		~Form(void);
		
		std::string	getName(void) const;
		std::string getSignatory(void) const;
		bool		getSignature(void) const;
		int			getSigningGrade(void) const;
		int			getExecutionGrade(void) const;

		void beSigned(const Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &output, const Form &rhs);
