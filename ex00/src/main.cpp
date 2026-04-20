#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    // Test 1: Valid bureaucrat
    std::cout << "=== Test 1: Valid bureaucrat ===" << std::endl;
    try{
        Bureaucrat a("Pepa", 150);
        std::cout << a << std::endl;
    }
    catch(std::exception& e){
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // Test 2: Grade too high (0)
    std::cout << "\n=== Test 2: Grade too high (0) ===" << std::endl;
    try{
        Bureaucrat b("Pepa", 0);
        std::cout << b << std::endl;
    }
    catch(std::exception& e){
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // Test 3: Grade too low (151)
    std::cout << "\n=== Test 3: Grade too low (151) ===" << std::endl;
    try{
        Bureaucrat c("Pepa", 151);
        std::cout << c << std::endl;
    }
    catch(std::exception& e){
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // Test 4: Increment at highest grade (should throw)
    std::cout << "\n=== Test 4: Increment at highest grade ===" << std::endl;
    try{
        Bureaucrat d("Pepa", 1);
        std::cout << "Before: " << d << std::endl;
        d.incrementGrade();
        std::cout << "After: " << d << std::endl;
    }
    catch(std::exception& e){
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // Test 5: Decrement at lowest grade (should throw)
    std::cout << "\n=== Test 5: Decrement at lowest grade ===" << std::endl;
    try{
        Bureaucrat e("Pepa", 150);
        std::cout << "Before: " << e << std::endl;
        e.decrementGrade();
        std::cout << "After: " << e << std::endl;
    }
    catch(std::exception& e){
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // Test 6: Normal increment/decrement
    std::cout << "\n=== Test 6: Normal increment/decrement ===" << std::endl;
    try{
        Bureaucrat f("Pepa", 75);
        std::cout << "Original: " << f << std::endl;
        f.incrementGrade();
        std::cout << "After increment: " << f << std::endl;
        f.decrementGrade();
        std::cout << "After decrement: " << f << std::endl;
    }
    catch(std::exception& e){
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return(0);
}
