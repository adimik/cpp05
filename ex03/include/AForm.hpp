/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 20:15:26 by didimitr          #+#    #+#             */
/*   Updated: 2026/02/06 01:05:13 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <ostream>
#include <exception>

class Bureaucrat;

class AForm {
    private:
        std::string const _name;
        bool _sign;
        int const _gradeSign;
        int const _gradeExec;
        std::string _target;
    public:
        AForm();
        AForm(const std::string& name, bool sign, int const gradeSign, int const gradeExec, std::string target);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        ~AForm();

        const std::string& getName() const;
        void beSigned(Bureaucrat& bureaucrat);
        bool getSignStatus() const;
        int getGradeSign() const;
        int getGradeExec() const;
        const std::string& getTarget() const;
        void execute(Bureaucrat const& executor) const;
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
        class FormNotSignedException : public std::exception {
            public:
                const char* what() const throw();
        };
        protected:
            virtual void executeAction() const = 0;

};

std::ostream& operator<<(std::ostream& os, const AForm& data);