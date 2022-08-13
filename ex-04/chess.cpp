#include <iostream>

void kingAttack(int kingArray[8][8], int x, int y);
void queenAttack(int queenArray[8][8], int x, int y);
void towerAttack(int towerArray[8][8], int x, int y);
void bishopAttack(int bishopArray[8][8], int x, int y);
void knightAttack(int knightArray[8][8], int x, int y);
void pawnAttack(int pawnArray[8][8], int x, int y);

main()
{
    int token, x, y;
    int board[8][8];

    for (int j = 0; j < 8; j++)
    {
        for (int i = 0; i < 8; i++)
        {
            board[j][i] = 0;
        }
    }

    std::cout << "Ingrese el codigo de la ficha: " << std::endl;
    std::cout << "1: Rey" << std::endl;
    std::cout << "2: Reina" << std::endl;
    std::cout << "3: Torre" << std::endl;
    std::cout << "4: Alfil" << std::endl;
    std::cout << "5: Caballo" << std::endl;
    std::cout << "6: Peones" << std::endl;
    std::cin >> token;

    std::cout << "Ingrese la cordenada X: " << std::endl;
    std::cin >> x;

    std::cout << "Ingrese la cordenada Y: " << std::endl;
    std::cin >> y;

    switch (token)
    {
    case 1:
        kingAttack(board, x, y);
        break;
    case 2:
        queenAttack(board, x, y);
        break;
    case 3:
        towerAttack(board, x, y);
        break;
    case 4:
        bishopAttack(board, x, y);
        break;
    case 5:
        knightAttack(board, x, y);
        break;
    case 6:
        pawnAttack(board, x, y);
        break;
    default:
        std::cout << "Ficha no encontrada" << std::endl;
    }

    for (int j = 0; j < 8; j++)
    {
        for (int i = 0; i < 8; i++)
        {
            std::cout << board[j][i];
        }
        std::cout << std::endl;
    }

    return 0;
}

void kingAttack(int kingArray[8][8], int x, int y)
{
    for (int j = 0; j < 8; j++)
    {
        for (int i = 0; i < 8; i++)
        {
            if (i == x + 1 && j == y)
            {
                kingArray[j][i] = 1;
            }
            else if (i == x + 1 && j == y - 1)
            {
                kingArray[j][i] = 1;
            }
            else if (i == x + 1 && j == y + 1)
            {
                kingArray[j][i] = 1;
            }
            else if (i == x && j == y + 1)
            {
                kingArray[j][i] = 1;
            }
            else if (i == x && j == y - 1)
            {
                kingArray[j][i] = 1;
            }
            else if (i == x - 1 && j == y)
            {
                kingArray[j][i] = 1;
            }
            else if (i == x - 1 && j == y + 1)
            {
                kingArray[j][i] = 1;
            }
            else if (i == x - 1 && j == y - 1)
            {
                kingArray[j][i] = 1;
            }
            else if (i == x && j == y)
            {
                kingArray[j][i] = 2;
            }
        }
    }
}

void queenAttack(int queenArray[8][8], int x, int y)
{
    towerAttack(queenArray, x, y);
    bishopAttack(queenArray, x, y);
}

void towerAttack(int towerArray[8][8], int x, int y)
{
    for (int j = 0; j < 8; j++)
    {
        for (int i = 0; i < 8; i++)
        {
            if (i == x)
            {
                towerArray[j][i] = 1;
            }
            else if (j == y)
            {
                towerArray[j][i] = 1;
            }
            else if (i == x && j == y)
            {
                towerArray[j][i] = 2;
            }
        }
    }
}

void bishopAttack(int bishopArray[8][8], int x, int y)
{
    bishopArray[y][x] = 2;

    for (int i = 1; i < 8; i++)
    {
        if (y + i < 8 && x + i < 8)
        {
            bishopArray[y + i][x + i] = 1;
        }
    }

    for (int i = 1; i < 8; i++)
    {
        if (y + i < 8 && x - i > -1)
        {
            bishopArray[y + i][x - i] = 1;
        }
    }

    for (int i = 1; i < 8; i++)
    {
        if (y - i > -1 && x - i > -1)
        {
            bishopArray[y - i][x - i] = 1;
        }
    }

    for (int i = 1; i < 8; i++)
    {
        if (y - i > -1 && x + i < 8)
        {
            bishopArray[y - i][x + i] = 1;
        }
    }
}

void knightAttack(int knightArray[8][8], int x, int y)
{
    for (int j = 0; j < 8; j++)
    {
        for (int i = 0; i < 8; i++)
        {
            if (j == y + 2 && i == x + 1)
            {
                knightArray[j][i] = 1;
            }
            else if (j == y + 2 && i == x - 1)
            {
                knightArray[j][i] = 1;
            }
            else if (j == y + 1 && i == x + 2)
            {
                knightArray[j][i] = 1;
            }
            else if (j == y + 1 && i == x - 2)
            {
                knightArray[j][i] = 1;
            }
            else if (j == y - 1 && i == x + 2)
            {
                knightArray[j][i] = 1;
            }
            else if (j == y - 1 && i == x - 2)
            {
                knightArray[j][i] = 1;
            }
            else if (j == y - 2 && i == x - 1)
            {
                knightArray[j][i] = 1;
            }
            else if (j == y - 2 && i == x + 1)
            {
                knightArray[j][i] = 1;
            }
            else if (j == y && i == x)
            {
                knightArray[j][i] = 2;
            }
        }
    }
}

void pawnAttack(int pawnArray[8][8], int x, int y)
{
    for (int j = 0; j < 8; j++)
    {
        for (int i = 0; i < 8; i++)
        {
            if (i == x + 1 && j == y - 1)
            {
                pawnArray[j][i] = 1;
            }
            else if (i == x - 1 && j == y - 1)
            {
                pawnArray[j][i] = 1;
            }
            else if (i == x && j == y)
            {
                pawnArray[j][i] = 2;
            }
        }
    }
}
