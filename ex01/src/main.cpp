#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"
#include <iostream>

int main()
{
	try
	{
		std::cout << "=== Test 1: Valid form and bureaucrats ===" << std::endl;
		Form form("Petition", 50, 25);
		Bureaucrat alice("Alice", 40);
		Bureaucrat bob("Bob", 100);

		std::cout << form << std::endl;
		std::cout << alice << std::endl;
		std::cout << bob << std::endl;

		std::cout << "\n=== Test 2: Alice signs (grade 40 <= 50) ===" << std::endl;
		alice.signForm(form);
		std::cout << form << std::endl;

		std::cout << "\n=== Test 3: Bob tries to sign (grade 100 > 50) ===" << std::endl;
		bob.signForm(form);
		std::cout << form << std::endl;

		std::cout << "\n=== Test 4: Boundary test (exactly grade 50) ===" << std::endl;
		Form petition2("Boundary", 50, 30);
		Bureaucrat charlie("Charlie", 50);
		charlie.signForm(petition2);

		std::cout << "\n=== Test 5: Invalid form grade (0 < 1) ===" << std::endl;
		Form invalid("Bad", 0, 25);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 6: Invalid bureaucrat grade (200 > 150) ===" << std::endl;
	try
	{
		Bureaucrat invalid("Invalid", 200);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return (0);
}
