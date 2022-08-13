#include <iostream>
#include <math.h>

int sum;

void happyNumber(int number)
{
    sum = 0;
    if (number / 10 == 0)
    {
        if (number == 1)
        {
            std::cout << "Numero Feliz :)";
        }
        else
        {
            std::cout << "Numero Triste :(" << std::endl;
        }
    }
    else
    {
        while (number > 0)
        {
            int digit = pow((number % 10), 2);
            sum = sum + digit;
            number /= 10;
        }
        happyNumber(sum);
    }
}

main()
{
    int number;

    std::cout << "Ingrese el numero" << std::endl;
    std::cin >> number;

    happyNumber(number);
}