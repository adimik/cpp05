/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 20:15:47 by didimitr          #+#    #+#             */
/*   Updated: 2026/04/20 14:57:55 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"


Form::Form() 
    : _name("default"), _sign(false), _gradeSign(150), _gradeExec(150)
{
}
Form::Form(const std::string& name, int const gradeSign, int const gradeExec) 
    : _name(name), _sign(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{    
    if(gradeSign > 150 || gradeExec > 150)
        throw GradeTooLowException();
    else if(gradeSign < 1 || gradeExec < 1)
        throw GradeTooHighException();
}

Form::Form(const Form& other)
    : _name(other._name), _sign(other._sign), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec)
{
}
Form& Form::operator=(const Form& other)
{
    if(this != &other)
        this->_sign = other._sign;
    return(*this);
}

Form::~Form()
{}

void Form::beSigned(Bureaucrat& bureaucrat){
    if(bureaucrat.getGrade() > this->_gradeSign)
        throw GradeTooLowException();
    else
        this->_sign = true;
}

bool Form::getSignStatus() const {
    if(this->_sign)
        return(true);
    return(false);
}

const std::string& Form::getName() const{
    return(this->_name);
}
int Form::getGradeSign() const {
    return(this->_gradeSign);
}

int Form::getGradeExec() const {
    return(this->_gradeExec);
}

const char* Form::GradeTooHighException::what() const throw() {
    return("Grade to High.");
}

const char* Form::GradeTooLowException::what() const throw() {
    return("Grade to Low.");
}

std::ostream& operator<<(std::ostream& os, const Form& data) {
     return(os << "Form name:" << data.getName() << std::endl
        << "Form signes:" << (data.getSignStatus() ? "true" : "false") << std::endl
        << "Grade needed for sign:" << data.getGradeSign() << std::endl
        << "Grade needed for execution:" << data.getGradeExec() << std::endl);
}
