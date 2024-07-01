/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:15:50 by cnascime          #+#    #+#             */
/*   Updated: 2024/06/28 20:03:35 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Alienação", target, 72, 45) {
};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy) {
	*this = copy;
};

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
	this->AForm::operator=(copy);
	return (*this);
};

RobotomyRequestForm::~RobotomyRequestForm(void) {
};

void RobotomyRequestForm::doAction(const Bureaucrat &executor) const {
	this->AForm::execute(executor);
	std::cout << "Drr drrr! Drrrrrrrrrrrrrrr… ";
	srand(time(NULL));
	if (rand() % 2) // 50% chance
		std::cout << "Pronto! " << this->getTarget() << " teve seu cérebro completamente removido." << std::endl;
	else
		std::cout << "Falha durante a extração cerebral. " << this->getTarget() << " já não tinha nada na cabeça." << std::endl;
};
