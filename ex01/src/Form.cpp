/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 20:15:47 by didimitr          #+#    #+#             */
/*   Updated: 2026/02/03 18:16:58 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

Form::Form() 
    : _name("default"), _sign(false), _gradeSign(150), _gradeExec(150)
{
}
Form::Form(const std::string name, bool sign, int const gradeSign, int const gradeExec) 
    : _name(name), _sign(sign), _gradeSign(gradeSign), _gradeExec(gradeExec)
{    
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

