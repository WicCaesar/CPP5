/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:43:22 by cnascime          #+#    #+#             */
/*   Updated: 2024/06/28 22:32:54 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void) {
	Bureaucrat flavio("Flávio Boçal-mor", 71);
	Bureaucrat salles("Ricardo Salles", 10);
	ShrubberyCreationForm fire("Amazônia");
	
	try {
		flavio.signForm(fire);
		salles.executeForm(fire);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	};

	Bureaucrat spanish("Carla Zambelli", 73);
	RobotomyRequestForm brainwashed("Sua avó");

	try {
		spanish.signForm(brainwashed);
		spanish.executeForm(brainwashed);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	};

	Bureaucrat president("Zaphod Beeblebrox", 3);
	PresidentialPardonForm pardon("Cássia Kiss");

	try {
		president.signForm(pardon);
		president.executeForm(pardon);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	};
};
