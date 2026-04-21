#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    std::srand(std::time(0));
    
    std::cout << "========== BUREAUCRAT FORM EXECUTION TEST ==========" << std::endl;
    std::cout << std::endl;
    
    // Create bureaucrats with different grades
    Bureaucrat ceo("CEO", 1);
    Bureaucrat manager("Manager", 50);
    Bureaucrat intern("Intern", 150);
    
    std::cout << "--- BUREAUCRATS CREATED ---" << std::endl;
    std::cout << ceo << std::endl;
    std::cout << manager << std::endl;
    std::cout << intern << std::endl;
    std::cout << std::endl;
    
    // Create forms
    ShrubberyCreationForm garden("garden");
    RobotomyRequestForm robot("R2D2");
    PresidentialPardonForm pardon("Prisoner");
    
    std::cout << "--- SIGNING FORMS (Manager attempts) ---" << std::endl;
    manager.signForm(garden);
    manager.signForm(robot);
    manager.signForm(pardon);
    std::cout << std::endl;
    
    std::cout << "--- EXECUTING FORMS (CEO attempts) ---" << std::endl;
    ceo.executeForm(garden);
    ceo.executeForm(robot);
    ceo.executeForm(robot);  // Second robotomy attempt
    ceo.executeForm(pardon);
    std::cout << std::endl;
    
    std::cout << "--- INTERN ATTEMPTS (should fail) ---" << std::endl;
    ShrubberyCreationForm task("house");
    intern.signForm(task);      // Will fail - insufficient grade
    ceo.signForm(task);         // CEO signs it
    intern.executeForm(task);   // Will fail - insufficient grade
    ceo.executeForm(task);      // CEO executes it
    std::cout << std::endl;
    
    std::cout << "========== TEST COMPLETE ==========" << std::endl;
    
    Intern somebody;
    AForm* testForm;

    testForm = somebody.makeForm("Potato form", "Mr potato");
    testForm = somebody.makeForm("shrubbery creation", "Franta");
    return(0);
}
