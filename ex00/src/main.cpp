#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try{
        Bureaucrat a("Pepa", 150);
        //Bureaucrat b("Pepa", 151);
        //Bureaucrat c("Pepa", 0);
        std::cout << a << std::endl;
        a.decrementGrade();
        std::cout << a << std::endl;
    }
    catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }
    
    return(0);
}
