#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int count;
void reset(int board[8][8]);
void test(int board[8][8]);
bool test_right_left(int board[8][8], int col, int row);
bool test_up_down(int board[8][8], int col, int row);
bool test_right_up_diagonal(int board[8][8], int col, int row);
bool test_left_up_diagonal(int board[8][8], int col, int row);
bool test_right_down_diagonal(int board[8][8], int col, int row);
bool test_left_down_diagonal(int board[8][8], int col, int row);
void show_board(int board[8][8]);

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
	reset(board);

	for (int a = 0; a < 8; a++)
	{
		board[a - 1][6] = 0;
		board[a][6] = 1;
		for (int b = 0; b < 8; b++)
		{
			board[b - 1][7] = 0;
			board[b][7] = 1;
			test(board);
		}
	} 

	reset(board);

	for (int a = 1; a < 8; a++)
	{
		board[a - 1][5] = 0;
		board[a][5] = 1;
		for (int b = 0; b < 8; b++)
		{
			board[b - 1][6] = 0;
			board[b][6] = 1;
			for (int c = 0; c < 8; c++)
			{
				board[c - 1][7] = 0;
				board[c][7] = 1;
				test(board);
			}
			board[7][7] = 0;
		}
		board[7][6] = 0;
	} 

	reset(board);

	for (int a = 1; a < 8; a++)
	{
		board[a - 1][4] = 0;
		board[a][4] = 1;
		for (int b = 0; b < 8; b++)
		{
			board[b - 1][5] = 0;
			board[b][5] = 1;
			for (int c = 0; c < 8; c++)
			{
				board[c - 1][6] = 0;
				board[c][6] = 1;
				for (int d = 0; d < 8; d++)
				{
					board[d - 1][7] = 0;
					board[d][7] = 1;
					test(board);
				}
				board[7][7] = 0;
			}
			board[7][6] = 0;
		}
		board[7][5] = 0;
	} 

	reset(board);

	for (int a = 1; a < 8; a++)
	{
		board[a - 1][3] = 0;
		board[a][3] = 1;
		for (int b = 0; b < 8; b++)
		{
			board[b - 1][4] = 0;
			board[b][4] = 1;
			for (int c = 0; c < 8; c++)
			{
				board[c - 1][5] = 0;
				board[c][5] = 1;
				for (int d = 0; d < 8; d++)
				{
					board[d - 1][6] = 0;
					board[d][6] = 1;
					for (int e = 0; e < 8; e++)
					{
						board[e - 1][7] = 0;
						board[e][7] = 1;
						test(board);
					}
					board[7][7] = 0;
				}
				board[7][6] = 0;
			}
			board[7][5] = 0;
		}
		board[7][4] = 0;
	} 

	reset(board);

	for (int a = 1; a < 8; a++)
	{
		board[a - 1][2] = 0;
		board[a][2] = 1;
		for (int b = 0; b < 8; b++)
		{
			board[b - 1][3] = 0;
			board[b][3] = 1;
			for (int c = 0; c < 8; c++)
			{
				board[c - 1][4] = 0;
				board[c][4] = 1;
				for (int d = 0; d < 8; d++)
				{
					board[d - 1][5] = 0;
					board[d][5] = 1;
					for (int e = 0; e < 8; e++)
					{
						board[e - 1][6] = 0;
						board[e][6] = 1;
						for (int f = 0; f < 8; f++)
						{
							board[f - 1][7] = 0;
							board[f][7] = 1;
							test(board);
						}
						board[7][7] = 0;
					}
					board[7][6] = 0;
				}
				board[7][5] = 0;
			}
			board[7][4] = 0;
		}
		board[7][3] = 0;
	}

	reset(board);

	for (int a = 1; a < 8; a++)
	{
		board[a - 1][1] = 0;
		board[a][1] = 1;
		for (int b = 0; b < 8; b++)
		{
			board[b - 1][2] = 0;
			board[b][2] = 1;
			for (int c = 0; c < 8; c++)
			{
				board[c - 1][3] = 0;
				board[c][3] = 1;
				for (int d = 0; d < 8; d++)
				{
					board[d - 1][4] = 0;
					board[d][4] = 1;
					for (int e = 0; e < 8; e++)
					{
						board[e - 1][5] = 0;
						board[e][5] = 1;
						for (int f = 0; f < 8; f++)
						{
							board[f - 1][6] = 0;
							board[f][6] = 1;
							for (int g = 0; g < 8; g++)
							{
								board[g - 1][7] = 0;
								board[g][7] = 1;
								test(board);
							}
							board[7][7] = 0;
						}
						board[7][6] = 0;
					}
					board[7][6] = 0;
				}
				board[7][4] = 0;
			}
			board[7][3] = 0;
		}
		board[7][2] = 0;
	}

	reset(board);

	for (int a = 1; a < 8; a++)
	{
		board[a - 1][0] = 0;
		board[a][0] = 1;
		for (int b = 0; b < 8; b++)
		{
			board[b - 1][1] = 0;
			board[b][1] = 1;
			for (int c = 0; c < 8; c++)
			{
				board[c - 1][2] = 0;
				board[c][2] = 1;
				for (int d = 0; d < 8; d++)
				{
					board[d - 1][3] = 0;
					board[d][3] = 1;
					for (int e = 0; e < 8; e++)
					{
						board[e - 1][4] = 0;
						board[e][4] = 1;
						for (int f = 0; f < 8; f++)
						{
							board[f - 1][5] = 0;
							board[f][5] = 1;
							for (int g = 0; g < 8; g++)
							{
								board[g - 1][6] = 0;
								board[g][6] = 1;
								for (int h = 0; g < 8; h++)
								{
									board[h - 1][7] = 0;
									board[h][7] = 1;
									test(board);
								}
								board[7][7] = 0;
							}
							board[7][6] = 0;
						}
						board[7][5] = 0;
					}
					board[7][4] = 0;
				}
				board[7][3] = 0;
			}
			board[7][2] = 0;
		}
		board[7][1] = 0;
	}
	
}

// RESETEAR TABLERO
void reset(int board[8][8])
{
	for (int j = 0; j < 8; j++)
	{
		board[0][j] = 1;
	}
}

void test(int board[8][8])
{
    bool test_valid = true;
    bool end_iteration = false;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] == 1)
            {
                if (!test_right_left(board, j, i))
                {
                    test_valid = false;
                    end_iteration = true;
                }
                else
                {
                    if (!test_up_down(board, j, i))
                    {
                        test_valid = false;
                        end_iteration = true;
                    }
                    else
                    { 
                        if (!test_right_up_diagonal(board, j, i))
                        {
                            test_valid = false;
                            end_iteration = true;
                        }
                        
                        else
                        {
                            if (!test_left_up_diagonal(board, j, i))
                            {
                                test_valid = false;
                                end_iteration = true;
                            }
                            else
                            {
                                if (!test_right_up_diagonal(board, j, i))
                                {
                                    test_valid = false;
                                    end_iteration = true;
                                }
                            }
                        } 
                    }
                } 
            } 
        }
        if (end_iteration)
        {
            break;
        }
    }

    if (test_valid)
    {
        show_board(board);
    }
}

bool test_right_left(int board[8][8], int col, int row)
{
    bool passed_test = true;
    bool end_iteration = false;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (i == row)
            {
                if (board[i][j] == 1)
                {
                    if (i == row && j == col)
                    {
                        continue;
                    }
                    else
                    {
                        passed_test = false;
                        end_iteration = true;
                    }
                }
            }
        }
        if (end_iteration)
        {
            break;
        }
    }

    return passed_test;
}

bool test_up_down(int board[8][8], int col, int row)
{
    bool passed_test = true;
    bool end_iteration = false;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (j == col)
            {
                if (board[i][j] == 1)
                {
                    if (i == row && j == col)
                    {
                        continue;
                    }
                    else
                    {
                        passed_test = false;
                        end_iteration = true;
                    }
                }
            }
        }
        if (end_iteration)
        {
            break;
        }
    }

    return passed_test;
}

bool test_right_up_diagonal(int board[8][8], int col, int row)
{
    bool passed_test = true;

    for (int i = 1; i < 8; i++)
    {
		if(col + 1 < 8 && row - 1 > -1) {
			if(board[row - 1][col + 1] == 1) {
				passed_test = false;
				break;
			}
		}
    } 

    return passed_test;
}

bool test_left_up_diagonal(int board[8][8], int col, int row)
{
    bool passed_test = true;

    for (int i = 1; i < 8; i++)
    {
        if (col - i > -1 && row - i > -1)
        {
            if (board[row - i][col - i] == 1)
            {
                passed_test = false;
                break;
            }
        }
    }

    return passed_test;
}

bool test_right_down_diagonal(int board[8][8], int col, int row)
{
    bool passed_test = true;

    for (int i = 1; i < 8; i++)
    {
        if (col + i < 8 && row + i < 8)
        {
            if (board[row + 1][col + 1] == 1)
            {
                passed_test = false;
                break;
            }
        }
    }

    return passed_test;
}

bool test_left_down_diagonal(int board[8][8], int col, int row)
{
    bool passed_test = true;

    for (int i = 1; i < 8; i++)
    {
        if (col - i > -1 && row + i < 8)
        {
            if (board[row + 1][col - 1] == 1)
            {
                passed_test = false;
                break;
            }
        }
    }

    return passed_test;
}

void show_board(int board[8][8])
{
    // i son filas, j son columnas
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
