/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:53:47 by cnascime          #+#    #+#             */
/*   Updated: 2024/04/22 02:39:01 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) : name_("Pacto"), is_signed_(false), signing_grade_(75), execution_grade_(75) {
};

Form::Form(const std::string name, const int signing_grade, const int execution_grade) : name_(name), signing_grade_(signing_grade), execution_grade_(execution_grade) {
	if (this->signing_grade_ < 1 || this->execution_grade_ < 1)
		throw Form::GradeTooHighException();
	if (this->signing_grade_ > 150 || this->execution_grade_ > 150)
		throw Form::GradeTooLowException();
	this->is_signed_ = false;
};

Form::Form(const Form &copy) : name_(copy.getName()), is_signed_(copy.getSignature()), signing_grade_(copy.getSigningGrade()), execution_grade_(copy.getExecutionGrade()) {
	*this = copy;
};

Form &Form::operator=(const Form &copy) {
	//this->name_ = copy.getName();
	this->is_signed_ = copy.getSignature();
	//this->signing_grade_ = copy.getSigningGrade();
	//this->execution_grade_ = copy.getExecutionGrade();
	return (*this);
};

Form::~Form() {
};

std::string Form::getName(void) const {
	return (this->name_);
};

std::string Form::getSignatory(void) const {
	if (this->is_signed_ == true)
		return (this->signatory_);
	return (NULL);
};

bool Form::getSignature(void) const {
	return (this->is_signed_);
};

int Form::getSigningGrade(void) const {
	return (this->signing_grade_);
};

int Form::getExecutionGrade(void) const {
	return (this->execution_grade_);
};

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= this->signing_grade_) {
		this->signatory_ = bureaucrat.getName();
		this->is_signed_ = true;
	}
	else
		throw (Form::GradeTooLowException());
};

const char *Form::GradeTooHighException::what() const throw() {
	return ("Muito alto na hierarquia para lidar com essas miudezas.");
};

const char *Form::GradeTooLowException::what() const throw() {
	return ("Não tem cacife. Resuma-se à sua insignificância.");
};

std::ostream &operator<<(std::ostream &output, const Form &rhs) {
	output << "O formulário " << rhs.getName();
	if (rhs.getSignature() == false)
		std::cout << " não";
	std::cout << " foi assinado";
	if (rhs.getSignature() == true)
		std::cout << " por " << rhs.getSignatory();
	std::cout << ". Nível hierárquico mínimo para assinar: "
			  << rhs.getSigningGrade()
			  << ". Nível hierárquico mínimo para executar: "
			  << rhs.getExecutionGrade() << ".";
	return (output);
};
