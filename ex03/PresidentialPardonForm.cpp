/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 20:02:40 by cnascime          #+#    #+#             */
/*   Updated: 2024/06/28 22:32:35 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("Anistia", target, 25, 5) {
};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy) {
	*this = copy;
};

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy) {
	this->AForm::operator=(copy);
	return(*this);
};

PresidentialPardonForm::~PresidentialPardonForm(void) {
};

void PresidentialPardonForm::doAction(const Bureaucrat &executor) const {
	this->AForm::execute(executor);
	std::cout << "Do alto de sua moral e altruísmo, Zaphod Beeblebrox, o presidente da galáxia, concede o perdão a "
			  << this->getTarget() << ". Povo, liberdade, democracia, essas coisas." << std::endl;
};
