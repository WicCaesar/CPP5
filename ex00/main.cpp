/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:43:22 by cnascime          #+#    #+#             */
/*   Updated: 2024/04/16 21:43:24 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {
	//Bureaucrat fash;
	Bureaucrat nazi("Boçal-mor", 148);
	Bureaucrat scum("Pedir Macedo", 3);
	//Bureaucrat zero("Recruta", 0);
	//Bureaucrat lora("Cerâmica Vosta", 22002);

	for (int i = 0; i < 4; i++) {
		try {
		//fash.grade_down();
		//std::cout << fash << std::endl;
		nazi.grade_down();
		std::cout << nazi << std::endl;
		scum.grade_up();
		std::cout << scum << std::endl;
		//nazi--;
		//scum++;
		}
		// e is the default parameter name for caught exceptions, could be any.
		catch (Bureaucrat::GradeTooHighException &e) {
			std::cerr << e.what() << std::endl;
		}
		// It'll catch exceptions of type exception (custom or default, like 
		// logic_error > out_of range, bad_alloc, runtime_error, etc.)
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		// This will catch ANY type of exception (like throwing a random float).
		catch (...) {
			std::cerr << "Palma, palma! Não priemos cânico." << std::endl;
		};
	};
};
