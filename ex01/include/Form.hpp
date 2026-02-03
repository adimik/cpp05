/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 20:15:26 by didimitr          #+#    #+#             */
/*   Updated: 2026/02/02 20:55:30 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <ostream>
#include <exception>

class Form {
    private:
        std::string const _name;
        bool _sign;
        int const _gradeSign;
        int const _gradeExec;
    
    public:
        Form();
        Form(std::string const name, bool sign, int const gradeSign, int const gradeExec);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();
};