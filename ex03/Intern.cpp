/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 00:35:32 by cnascime          #+#    #+#             */
/*   Updated: 2024/06/29 09:46:49 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {
	std::cout << "Oi, chefinho! Se precisar de um formulário, é só estalar os dedos. "
			// << "*Cid faz cara de pidão e abana o rabinho, chacoalhando as medalhas.* "
			  << "Hoje estou com a papelada de jardinagem, alienação e anistia." << std::endl;
};

Intern::Intern(const Intern &copy) {
	*this = copy;
};

Intern &Intern::operator=(const Intern &copy) {
	(void)copy;
	return (*this);
};

Intern::~Intern(void) {
};

AForm *Intern::makeForm(const std::string &name, const std::string &target) const {
	std::string options[] = {"jardinagem", "alienação", "anistia"};
	int i = 0;
	while (i < 3 && options[i] != name)
		i++;
	if (i < 3)
		std::cout << "Tá na mão, chefuxo! " << std::endl;
	else
		std::cerr << "Capi, você vai me castigar? " << std::endl;
	switch (i) { // fallthrough is not needed because we're already returning.
		case 0:
			return (new ShrubberyCreationForm(target));
		case 1:
			return (new RobotomyRequestForm(target));
		case 2:
			return (new PresidentialPardonForm(target));
		default:
			throw Intern::MissingFormException();
	}
};
