/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:43:22 by cnascime          #+#    #+#             */
/*   Updated: 2024/04/21 22:09:26 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void) {
	// Test form exceptions.
	try {
		Form vivendas("Vivendas", 151, 42);
		Form da_barra("Da Barra", 0, 23);
		Form racha("Racha", 42, 151);
		Form dinha("Dinha", 23, 0);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	};
	
	Bureaucrat flavio("Flávio", 71);

	try {
		flavio.grade_up();
		flavio.grade_up();
		std::cout << flavio << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	};
	
	Form queiroz("Rachadinha do Queiroz", 66, 6);
	flavio.signForm(queiroz); // won't be signed
	std::cout << queiroz << std::endl;
	
	Form michelle("Rachadinha da Michelle", 89, 89);
	std::cout << michelle << std::endl;
	flavio.signForm(michelle); // will be signed
	flavio.signForm(michelle); // already signed

	Form marcia("Rachadinha da Márcia", 69, 150);
	try {
		flavio.grade_down();
		std::cout << flavio << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	};
	// Flávio was demoted and cannot slip Márcia's rachadinha.
	flavio.signForm(marcia);
};
