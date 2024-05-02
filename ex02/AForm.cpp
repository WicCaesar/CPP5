/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:53:47 by cnascime          #+#    #+#             */
/*   Updated: 2024/04/19 20:11:50 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void) : name_("Pacto"), is_signed_(false), signing_grade_(75), execution_grade_(75) {
};

AForm::AForm(const std::string name) : name_(name), signing_grade_(75), execution_grade_(75) {
};

AForm::AForm(const std::string name, std::string target) : name_(name), target_(target), signing_grade_(75), execution_grade_(75) {
};

AForm::AForm(const std::string name, const int signing_grade, const int execution_grade) : name_(name), signing_grade_(signing_grade), execution_grade_(execution_grade) {
	if (this->signing_grade_ < 1 || this->execution_grade_ < 1)
		throw AForm::GradeTooHighException();
	if (this->signing_grade_ > 150 || this->execution_grade_ > 150)
		throw AForm::GradeTooLowException();
	this->is_signed_ = false;
};

AForm::AForm(const std::string name, std::string target, const int signing_grade, const int execution_grade) : name_(name), target_(target), signing_grade_(signing_grade), execution_grade_(execution_grade) {
	if (this->signing_grade_ < 1 || this->execution_grade_ < 1)
		throw AForm::GradeTooHighException();
	if (this->signing_grade_ > 150 || this->execution_grade_ > 150)
		throw AForm::GradeTooLowException();
	this->is_signed_ = false;
};

AForm::AForm(const AForm &copy) : name_(copy.getName()), is_signed_(copy.getSignature()), signing_grade_(copy.getSigningGrade()), execution_grade_(copy.getExecutionGrade()) {
	*this = copy;
};

AForm &AForm::operator=(const AForm &copy) {
	//this->name_ = copy.getName();
	this->is_signed_ = copy.getSignature();
	//this->signing_grade_ = copy.getSigningGrade();
	//this->execution_grade_ = copy.getExecutionGrade();
	return (*this);
};

AForm::~AForm() {
};

std::string AForm::getName(void) const {
	return (this->name_);
};

std::string AForm::getTarget(void) const {
	return (this->target_);
};

std::string AForm::getSignatory(void) const {
	if (this->is_signed_ == true)
		return (this->signatory_);
	return (NULL);
};

bool AForm::getSignature(void) const {
	return (this->is_signed_);
};

unsigned int AForm::getSigningGrade(void) const {
	return (this->signing_grade_);
};

unsigned int AForm::getExecutionGrade(void) const {
	return (this->execution_grade_);
};

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= this->signing_grade_) {
		this->signatory_ = bureaucrat.getName();
		this->is_signed_ = true;
	}
	else
		throw (AForm::GradeTooLowException());
};

void AForm::execute(const Bureaucrat &executor) const {
	if (this->is_signed_ == true) {
		if (executor.getGrade() <= this->execution_grade_)
			executor.executeForm(*this);
		else
			throw (AForm::GradeTooLowException());
	} else
		throw (AForm::UnsignedFormException());
};

const char *AForm::UnsignedFormException::what() const throw() {
	return ("O formulário não foi assinado.");
}

const char *AForm::GradeTooHighException::what() const throw() {
	return ("Muito alto na hierarquia para lidar com essas miudezas.");
};

const char *AForm::GradeTooLowException::what() const throw() {
	return ("Não tem cacife. Resuma-se à sua insignificância.");
};

std::ostream &operator<<(std::ostream &output, const AForm &rhs) {
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
