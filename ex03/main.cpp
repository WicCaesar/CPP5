/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:43:22 by cnascime          #+#    #+#             */
/*   Updated: 2024/06/29 09:33:44 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void) {
	Bureaucrat	captain("Jair", 4);
	Intern		cid;
	AForm		*paperwork;
	std::string	command;
	std::string	target;

	std::cout << "Ajudo em algo, chefe?" << std::endl;
	std::cin >> command;
	std::cout << "Esse formulário seria sobre o quê, ou quem?" << std::endl;
	std::cin >> target;
	std::cout << "Vou ver o que posso fazer…" << std::endl;
	
	paperwork = cid.makeForm(command, target);
	paperwork->beSigned(captain);
	captain.executeForm(*paperwork);
};
