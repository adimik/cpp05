/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 20:15:47 by didimitr          #+#    #+#             */
/*   Updated: 2026/04/20 15:48:07 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"


AForm::AForm() 
    : _name("default"), _sign(false), _gradeSign(150), _gradeExec(150)
{
}
AForm::AForm(const std::string& name, bool sign, int const gradeSign, int const gradeExec, std::string target) 
    : _name(name), _sign(sign), _gradeSign(gradeSign), _gradeExec(gradeExec), _target(target)
{    
    if(gradeSign > 150 || gradeExec > 150)
        throw GradeTooHighException();
    else if(gradeSign < 1 || gradeExec < 1)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : _name(other._name), _sign(other._sign), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec), _target()
{
}
AForm& AForm::operator=(const AForm& other)
{
    if(this != &other)
    {
        this->_sign = other._sign;
        this->_target = other._target;
    }
    return(*this);
}

AForm::~AForm()
{}

void AForm::execute(Bureaucrat const& executor) const {
    if (!this->_sign)
        throw FormNotSignedException();
    if (executor.getGrade() > this->getGradeExec())
        throw GradeTooLowException();
    this->executeAction();
}

void AForm::beSigned(Bureaucrat& bureaucrat){
    if(bureaucrat.getGrade() <= this->_gradeSign)
        this->_sign = true;
    else
        throw GradeTooHighException();
}

bool AForm::getSignStatus() const {
    if(this->_sign)
        return(true);
    return(false);
}

const std::string& AForm::getName() const{
    return(this->_name);
}
int AForm::getGradeSign() const {
    return(this->_gradeSign);
}

int AForm::getGradeExec() const {
    return(this->_gradeExec);
}

const std::string& AForm::getTarget() const {
    return(this->_target);
}

const char* AForm::GradeTooHighException::what() const throw() {
    return("Grade to High.");
}

const char* AForm::GradeTooLowException::what() const throw() {
    return("Grade to Low.");
}
const char* AForm::FormNotSignedException::what() const throw(){
    return("Form is not signed!");
}


std::ostream& operator<<(std::ostream& os, const AForm& data) {
     return(os << "AForm name:" << data.getName() << std::endl
        << "AForm signes:" << (data.getSignStatus() ? "true" : "false") << std::endl
        << "Grade needed for sign:" << data.getGradeSign() << std::endl
        << "Grade needed for execution:" << data.getGradeExec() << std::endl);
}
