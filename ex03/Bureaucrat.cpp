/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:43:14 by cnascime          #+#    #+#             */
/*   Updated: 2024/06/29 09:36:09 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <exception>

Bureaucrat::Bureaucrat(void) : name_("Canalha") {
	this->grade_ = 150;
	std::cout << *this << std::endl;
};

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade_ = grade;
	std::cout << *this << std::endl;
};

Bureaucrat::Bureaucrat(const Bureaucrat &copy) {
	*this = copy;
};

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
	// No way of altering const name, so we can only atribute the grade.
	this->grade_ = copy.grade_;
	return (*this);
};

Bureaucrat &Bureaucrat::operator++(void) {
	// Increases its grade in the hierarchy by decreasing the number.
	if (this->grade_ == 1)
		throw Bureaucrat::GradeTooHighException();
	grade_--;
	return (*this);
};

Bureaucrat &Bureaucrat::operator--(void) {
	// Decreases its grade in the hierarchy by increasing the number.
	if (this->grade_ == 150)
		throw Bureaucrat::GradeTooLowException();
	grade_++;
	return (*this);
};

Bureaucrat::~Bureaucrat(void) {
};

const std::string Bureaucrat::getName(void) const {
	return (this->name_);
};

unsigned int	Bureaucrat::getGrade(void) const {
	return (this->grade_);
};

int Bureaucrat::grade_up(void) {
	if (this->grade_ == 1)
		throw Bureaucrat::GradeTooHighException();
	return (this->grade_--);
};

int Bureaucrat::grade_down(void) {
	if (this->grade_ == 150)
		throw Bureaucrat::GradeTooLowException();
	return (this->grade_++);
};

void Bureaucrat::signForm(AForm &form) const {
	if (form.getSignature() == true) {
		std::cout << "O formulário " << form.getName() << " já foi assinado por "
				  << form.getSignatory() << "." << std::endl;
		return;
	};
	try {
		form.beSigned(*this);
		// If an exception is thrown here, it won't go through the other lines.
		std::cout << this->name_ << " signed " << form.getName() << std::endl;
	}
	catch (AForm::GradeTooLowException &e) {
		std::cout << this->name_ << " couldn't sign " << form.getName()
				  << " because " << e.what() << std::endl;
	};
};

void Bureaucrat::executeForm(const AForm &form) const {
	if (this->grade_ <= form.getExecutionGrade()) {
		try {
			form.doAction(*this);
			std::cout << this->getName() << " executed " << form.getName() << std::endl;
		}
		catch (...) {
			std::cerr << "Erro ao executar formulário." << std::endl;
		}
	} else
		std::cerr << this->name_ << ", além de canalha, é incompetente." << std::endl;
};

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Esse canalha já está a um passo da decadência. Ovo podre nele.");
};

// Operator overloading for stream insertion.
// In other words, to make std::cout << Bureaucrat work.
std::ostream &operator<<(std::ostream &output, const Bureaucrat &rhs) {
	output << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return (output);
};
