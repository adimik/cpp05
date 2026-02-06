/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:14:04 by didimitr          #+#    #+#             */
/*   Updated: 2026/02/06 14:42:57 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", false, 25, 5, target) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other) {
}

PresidentialPardonForm& PresidentialPardonForm:: operator=(const PresidentialPardonForm& other) {
    if(this != &other)
    {
        AForm::operator=(other);
    }
    return(*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
    
}

void PresidentialPardonForm::executeAction() const{
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}