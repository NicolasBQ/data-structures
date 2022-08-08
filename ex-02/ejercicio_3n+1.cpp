#include <iostream>

int count;

int counter(int n)
{
    if (n == 1)
    {
        return count;
    }
    else if (n % 2 != 0)
    {
        count++;
        std::cout << 3 * n + 1 << std::endl;
        counter(3 * n + 1);
    }
    else
    {
        count++;
        std::cout << n / 2 << std::endl;
        counter(n / 2);
    }
}

int main(int argc, char **argv)
{
    int initialNumber, count;
    std::cout << "Ingrese el numero: " << std::endl;
    std::cin >> initialNumber;
    int result = counter(initialNumber);

    std::cout << "el número de iteraciones fue: " << result << std::endl;

    return 0;
}