#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void show_board(int board[8][8]);
void one_to_one(int board[8][8], int c1, int c2);
void one_to_two(int board[8][8], int c1, int c2, int c3);

int main()
{
	int board[8][8];

	// Crear Tablero
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			board[i][j] = 0;
		}
	}

	// Poner todas las fichas en la fila 0, en cada columna
	for (int j = 0; j < 8; j++)
	{
		board[0][j] = 1;
	}

	// Cambiar la posici�n de las filas de la ultima columna
	/*for(int i = 0; i < 8; i++) {
		board[i - 1][7] = 0;
		board[i][7] = 1;
		show_board(board);
	} */

	// Combinaciones posici�n dos ultimas columnas
	// one_to_one(board, 6, 7);
	// one_to_one(board, 5, 7);
	// one_to_one(board, 5, 6);

	// one_to_two(board, 5, 6, 7);

	// one_to_one(board, 4, 7);
	// one_to_one(board, 4, 6);
	// one_to_one(board, 4, 5);
	one_to_two(board, 4, 6, 7);
	// one_to_two(board, 4, 5, 7);
	// for (int i = 1; i < 8; i++)
	// {
	// 	board[i - 1][4] = 0;
	// 	board[i][4] = 1;

	// 	for (int j = 1; j < 8; j++)
	// 	{
	// 		board[j - 1][5] = 0;
	// 		board[j][5] = 1;

	// 		for (int k = 0; k < 8; k++)
	// 		{
	// 			board[k - 1][6] = 0;
	// 			board[k][6] = 1;
	// 			show_board(board);
	// 		}
	// 		board[7][6] = 0;
	// 	}
	// 	board[7][5] = 0;
	// }
}

// MOSTRAR TABLERO
void show_board(int board[8][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::cout << board[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void one_to_one(int board[8][8], int c1, int c2)
{
	for (int i = 1; i < 8; i++)
	{
		board[i - 1][c1] = 0;
		board[i][c1] = 1;

		for (int j = 0; j < 8; j++)
		{
			board[j - 1][c2] = 0;
			board[j][c2] = 1;
			show_board(board);
		}
		board[7][c2] = 0;
	}
}

void one_to_two(int board[8][8], int c1, int c2, int c3)
{
	for (int i = 1; i < 8; i++)
	{
		board[i - 1][c1] = 0;
		board[i][c1] = 1;

		for (int j = 1; j < 8; j++)
		{
			board[j - 1][c2] = 0;
			board[j][c2] = 1;

			for (int k = 0; k < 8; k++)
			{
				board[k - 1][c3] = 0;
				board[k][c3] = 1;
				show_board(board);
			}
			board[7][c3] = 0;
		}
		board[7][c2] = 0;
	}
}
