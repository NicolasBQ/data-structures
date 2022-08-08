#include <iostream>
#include <windows.h> // Windows Library
#include <cstdlib>   // Random Number Library

main()
{
    int arr[8][8];
    int positionI_1; // Up
    int positionJ_1; // Left - Right
    int positionI_2; // Current
    int positionJ_2; // Current
    int positionI_3; // Down
    int positionJ_3; // Right - Left;
    int max_value;
    int product;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Llena subarrays con numeros aleatorios
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            arr[i][j] = rand() % 10;
        };
    };

    // Recorrer Matriz de izquierda a derecha comparando diagonales
    for (int i = 1; i < 7; i++)
    {
        for (int j = 1; j < 7; j++)
        {
            product = arr[i][j] * arr[i - 1][j - 1] * arr[i + 1][j + 1];

            if (product > max_value)
            {
                max_value = product;
                positionI_1 = i - 1;
                positionJ_1 = j - 1;
                positionI_2 = i;
                positionJ_2 = j;
                positionI_3 = i + 1;
                positionJ_3 = j + 1;
            }
        }
    };

    // Recorrer Matriz de derecha a izquierda comparando diagonales
    for (int i = 1; i < 7; i++)
    {
        for (int j = 6; j > 0; j--)
        {
            product = arr[i][j] * arr[i - 1][j + 1] * arr[i + 1][j - 1];

            if (product > max_value)
            {
                max_value = product;
                positionI_1 = i - 1;
                positionJ_1 = j + 1;
                positionI_2 = i;
                positionJ_2 = j;
                positionI_3 = i + 1;
                positionJ_3 = j - 1;
            }
        }
    };

    // Color en consolola con la diagonal que genera el mayor producto
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (
                i == positionI_1 && j == positionJ_1 || i == positionI_2 && j == positionJ_2 || i == positionI_3 && j == positionJ_3)
            {
                SetConsoleTextAttribute(hConsole, 12);
                std::cout << arr[i][j];
            }
            else
            {
                SetConsoleTextAttribute(hConsole, 15);
                std::cout << arr[i][j];
            }
        };
        std::cout << std::endl;
    };

    // Imprime el valor y las coordenadas donde se encuentra
    std::cout << "El val max es: " << max_value << std::endl;
    std::cout << "Y se encuentra en las cordenadas {" << positionI_1 << ", " << positionJ_1 << "}"
              << " {" << positionI_2 << ", " << positionJ_2 << "}"
              << " {" << positionI_3 << ", " << positionJ_3 << "}" << std::endl;

    return 0;
}