#include <iostream>
#include <stdexcept>
#include <cmath>

double add(double num1, double num2)
{
    return num1 + num2;
}

double subtract(double num1, double num2)
{
    return num1 - num2;
}

double multiply(double num1, double num2)
{
    return num1 * num2;
}

double divide(double num1, double num2)
{
    if (num2 == 0)
    {
        throw std::invalid_argument("Cannot divide by zero");
    }
    return num1 / num2;
}

void showMenu()
{
    std::cout << "Basic Calculator Menu:" << std::endl;
    std::cout << "1. Add" << std::endl;
    std::cout << "2. Subtract" << std::endl;
    std::cout << "3. Multiply" << std::endl;
    std::cout << "4. Divide" << std::endl;
    std::cout << "5. Square Root" << std::endl;
    std::cout << "6. Power" << std::endl;
    std::cout << "7. Exit" << std::endl;
}

int main()
{
    int choice;
    double num1, num2;

    do
    {
        showMenu();
        std::cout << "Choose an operation: ";
        std::cin >> choice;

        if (choice == 7)
        {
            std::cout << "Exiting calculator." << std::endl;
            break;
        }

        if (choice >= 1 && choice <= 4)
        {
            std::cout << "Enter first number: ";
            std::cin >> num1;
            std::cout << "Enter second number: ";
            std::cin >> num2;
        }
        else if (choice >= 5 && choice <= 6)
        {
            std::cout << "Enter number: ";
            std::cin >> num1;
        }

        try
        {
            switch (choice)
            {
            case 1:
                std::cout << "Result: " << add(num1, num2) << std::endl;
                std::cout << "" << std::endl;
                break;
            case 2:
                std::cout << "Result: " << subtract(num1, num2) << std::endl;
                break;
            case 3:
                std::cout << "Result: " << multiply(num1, num2) << std::endl;
                break;
            case 4:
                std::cout << "Result: " << divide(num1, num2) << std::endl;
                break;
            case 5:
                std::cout << "Result: " << sqrt(num1) << std::endl;
                break;
            case 6:
                std::cout << "Enter exponent: ";
                std::cin >> num2;
                std::cout << "Result: " << pow(num1, num2) << std::endl;
                break;

            default:
                std::cout << "Invalid options" << std::endl;
                std::cout << "" << std::endl;
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
            std::cout << "" << std::endl;
        }

    } while (true);
}