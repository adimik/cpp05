#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::srand(std::time(0));
    Bureaucrat a("Pepa", 1);
    Bureaucrat c("Franta", 1);
    ShrubberyCreationForm b("Sracka");
    RobotomyRequestForm r("R2D2");
    RobotomyRequestForm s("R2D3");
    PresidentialPardonForm amnesty("Dimik");
    c.signForm(amnesty);
    c.signForm(s);
    c.signForm(r);
    c.signForm(b);
    a.executeForm(b);
    a.executeForm(r);
    a.executeForm(s);
    a.executeForm(amnesty);
    return(0);
}
