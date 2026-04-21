/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 00:55:45 by didimitr          #+#    #+#             */
/*   Updated: 2026/02/06 14:13:02 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", false, 72, 45, target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {
    
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
    if(this != &other)
    {
        AForm::operator=(other);
    }
    return(*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {   
}

void RobotomyRequestForm::executeAction() const {
    int num = std::rand() % 2;
    if(num)
    {
        std::cout << "Piiii puuup Pipiiiiiip " << this->getTarget() << " has been robotomized successfully!!" << std::endl; 
    }
    else
    {
        std::cout << "Ouch! Robotomy failed!" << std::endl;
    }
}