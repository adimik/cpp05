/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 12:08:25 by didimitr          #+#    #+#             */
/*   Updated: 2026/02/02 15:22:22 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <ostream>
#include <exception>

class Bureaucrat 
{
    private:
        std::string _name;
        int         _grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();
        
        const std::string& getName(void) const;
        int getGrade(void) const;
        void incrementGrade(void);
        void decrementGrade(void);
        
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);