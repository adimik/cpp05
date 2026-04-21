/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 12:08:01 by didimitr          #+#    #+#             */
/*   Updated: 2026/02/06 00:07:24 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include <iostream>

Bureaucrat::Bureaucrat()
    : _name("default"), _grade(150){
}

Bureaucrat::Bureaucrat(std::string _name, int _grade)
    : _name(_name), _grade(_grade){
        if(_grade < 1)
            throw GradeTooHighException();
        if(_grade > 150)
            throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other){
    *this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
    if (this != &other) {
        _grade = other._grade;
    }
    return(*this);
}

Bureaucrat::~Bureaucrat(){
    
}

const std::string& Bureaucrat::getName(void) const{
    return(this->_name);
}

int Bureaucrat::getGrade(void) const{
    return(this->_grade);
}

void Bureaucrat::signForm(AForm& form){
    try{
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch(std::exception& e){
        std::cout << this->getName() << " couldn't sign " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}
    


const char* Bureaucrat::GradeTooHighException::what()const throw(){
    return("Bureaucrat::exeption. Grade out of range (1-150).");
}

const char* Bureaucrat::GradeTooLowException::what()const throw(){
    return("Bureaucrat::exeption. Grade out of range (1-150).");
}

void Bureaucrat::incrementGrade(void){
    if(this->_grade <= 1)
        throw GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decrementGrade(void){
    if(this->_grade >= 150)
    {
        throw GradeTooLowException();
    }
    this->_grade++;
}

void Bureaucrat::executeForm(AForm const& form) const {
    try{
    form.execute(*this);
    std::cout << this->getName() << " executed " << form.getName() << std::endl;
    }
    catch(std::exception& e){
        std::cout << this->getName() << " couldn't execute " << form.getName() 
            << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b){
    return(os << b.getName() << ", bureaucrat grade " << b.getGrade());
}