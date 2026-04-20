/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 20:15:26 by didimitr          #+#    #+#             */
/*   Updated: 2026/04/20 14:58:05 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <ostream>
#include <exception>

class Bureaucrat;

class Form {
    private:
        const std::string _name;
        bool _sign;
        const int _gradeSign;
        const int _gradeExec;
    
    public:
        Form();
        Form(const std::string& name, int const gradeSign, int const gradeExec);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        const std::string& getName() const;
        void beSigned(Bureaucrat& bureaucrat);
        bool getSignStatus() const;
        int getGradeSign() const;
        int getGradeExec() const;

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Form& data);