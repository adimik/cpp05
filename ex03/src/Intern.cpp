/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 12:21:33 by didimitr          #+#    #+#             */
/*   Updated: 2026/04/21 14:15:41 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"

Intern::Intern() {

}

Intern::~Intern() {

}

Intern::Intern(const Intern& other) {
    *this = other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return(*this);
}

AForm* Intern::makeForm(std::string form, std::string target) {
    
    std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    int i = 0;
    while(i < 3 && forms[i] != form)
    {
        i++;
    }
    switch (i)
    {
    case 0:
        std::cout << "Intern creates " << form << std::endl;
        return(new ShrubberyCreationForm(target));
        break;
    
    case 1:
        std::cout << "Intern creates " << form << std::endl;
        return(new RobotomyRequestForm(target));
        break;
    case 2:
        std::cout << "Intern creates " << form << std::endl;
        return(new PresidentialPardonForm(target));
        break;
    default:
        std::cout << "This form doesnt exist." << std::endl;
        return(NULL);
    }
}
