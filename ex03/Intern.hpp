/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 00:32:34 by cnascime          #+#    #+#             */
/*   Updated: 2024/06/29 09:38:48 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	public:
		Intern(void);
		Intern(const Intern &copy);
		Intern &operator=(const Intern &copy);
		~Intern(void);

		AForm *makeForm(const std::string &name, const std::string &target) const;

		class MissingFormException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Não tenho essa papelada.");
				};
		};
};
