/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:43:22 by cnascime          #+#    #+#             */
/*   Updated: 2024/05/02 05:16:55 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
// #include "PresidentialPardonForm.hpp"
// #include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void) {
	Bureaucrat flavio("Flávio Boçal-mor", 71);
	Bureaucrat salles("Ricardo Salles", 10);
	ShrubberyCreationForm queimada("Amazônia");
	
	try {
		flavio.signForm(queimada);
		queimada.doAction(salles);
		salles.executeForm(queimada);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	};
};
