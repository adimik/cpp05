#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    try{
        Form a("Ucet", false, 140, 1);
        Bureaucrat b("Pepa", 120);
        std::cout << a;
        b.signForm(a);
        std::cout << std::endl;
        std::cout << a;
        Form c("Bill", false, 150, 1);
        std::cout << c;
        b.signForm(c);
        std::cout << c;

        Form d("test", false, 150, 151);
        Form e("test", false, 150, 150);
    }
    catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }    
    return(0);
}
