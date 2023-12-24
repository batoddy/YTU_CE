#include <stdio.h>

#define MAX_SIZE 100

int n = 0, m = 0;

int tetremino1[3][3] = {
    {1, 1, 1},
    {0, 0, 0},
    {0, 0, 0}};

int tetremino2[3][3] = {
    {1, 1, 0},
    {1, 1, 0},
    {0, 0, 0}};

int tetremino3[3][3] = {
    {0, 1, 0},
    {0, 1, 0},
    {0, 0, 0}};

int tetremino4[3][3] = {
    {0, 0, 0},
    {0, 1, 0},
    {0, 0, 0}};

int tetremino5[3][3] = {
    {0, 1, 0},
    {0, 1, 0},
    {0, 1, 1}};

int tetremino6[3][3] = {
    {0, 1, 0},
    {0, 1, 0},
    {0, 1, 0}};

int tetremino7[3][3] = {
    {0, 1, 1},
    {1, 1, 0},
    {0, 0, 0}};

void reset_board(int board[MAX_SIZE][MAX_SIZE]);

void print_board(int board[MAX_SIZE][MAX_SIZE]);

void print_tetremino(int tetremino[][3]);

void equalize_tetreminos(int const_matris[][3], int matris_to_equaled[][3]);

void rotate_tetremino_left(int tetremino[][3]);
void rotate_tetremino_right(int tetremino[][3]);

void add_tetramino_to_board(int gameboard[][MAX_SIZE], int tetremino[][3], int coordinate, int height);

int main()
{
    int dummy_tetremino1[3][3];
    int dummy_tetremino2[3][3];
    int coordinate;
    printf("##########################\n");
    printf("\n");
    printf("Welcome to Tetris game !!!\n");
    printf("\n");
    printf("##########################\n");
    printf("\n");
    printf("Please enter the dimensions of game board: \n");
    printf("Height:\t");
    scanf("%d", &n);
    printf("Width:\t");
    scanf("%d", &m);

    int gameboard[MAX_SIZE][MAX_SIZE];

    reset_board(gameboard);

    print_board(gameboard);

    /*print_tetremino(tetremino1);
    print_tetremino(tetremino2);
    print_tetremino(tetremino3);
    print_tetremino(tetremino4);
    print_tetremino(tetremino5);
    print_tetremino(tetremino6);
    print_tetremino(tetremino7);*/

    /*equalize_tetreminos(tetremino3, dummy_tetremino1);
    equalize_tetreminos(tetremino3, dummy_tetremino2);

    print_tetremino(dummy_tetremino1);

    rotate_tetremino_left(dummy_tetremino1);
    rotate_tetremino_right(dummy_tetremino2);

    print_tetremino(tetremino7);*/
    /* printf("Enter the coordinate: ");
     scanf("%d\n", &coordinate);*/
    // add_tetramino_to_board(gameboard, tetremino7, 3, n);
    print_board(gameboard);
}

void reset_board(int board[MAX_SIZE][MAX_SIZE])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            board[i][j] = 1;
        }
    }
}

void print_board(int board[MAX_SIZE][MAX_SIZE])
{
    for (int j = 0; j < m; j++)
    {
        printf(" - ");
    }
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[n][m] == 0)
                printf("| %d ", board[n][m]);
            else
                printf("| %d ", board[n][m]);
        }
        printf("|\n");
        for (int j = 0; j < m; j++)
        {
            printf(" ---");
        }
        printf("\n");
    }
}

void print_tetremino(int tetremino[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (tetremino[i][j] == 0)
                printf(" ");
            else if (tetremino[i][j] == 1)
                printf("X");
            // printf("%d", tetremino[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void equalize_tetreminos(int const_matris[][3], int matris_to_equaled[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matris_to_equaled[i][j] = const_matris[i][j];
        }
    }
}

void rotate_tetremino_left(int tetremino[][3])
{

    int rotated_tetramino[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            rotated_tetramino[i][2 - j] = tetremino[j][i];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tetremino[i][j] = rotated_tetramino[i][j];
        }
    }
}

void rotate_tetremino_right(int tetremino[][3])
{

    int rotated_tetramino[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            rotated_tetramino[j][2 - i] = tetremino[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tetremino[i][j] = rotated_tetramino[i][j];
        }
    }
}

void add_tetramino_to_board(int gameboard[][MAX_SIZE], int tetremino[][3], int coordinate, int height)
{
    int tetremino_col = 0;
    int tetremino_row = 0;
    int gameboard_coordinate;
    int i = 0, j = 2, t = 0;
    int tetremino_point_flag = 0;
    int gameboard_coordinate_flag = 0;
    int tetremino_add_flag = 1;
    int tetremino_add_flag_1 = 0;

    printf("Halo");

    while (i < 3 && tetremino_point_flag == 0)
    {
        while (j >= 0 && tetremino_point_flag == 0)
        {
            printf("%d", tetremino[j][i]);
            if (tetremino[j][i] == 1 && tetremino_point_flag == 0)
            {
                tetremino_col = i;
                tetremino_row = j;
                tetremino_point_flag = 1;
            }
            printf(" | (%d,%d)\n\n", j, i);
            j--;
        }
        j = 2;
        i++;
    }
    printf("(%d,%d) - %d\n", tetremino_col, tetremino_row, tetremino_point_flag);

    while (t <= height && gameboard_coordinate_flag == 0)
    {
        printf("t= %d\n", t);
        if (gameboard[coordinate][t] == 1 && gameboard_coordinate_flag == 0)
        {
            gameboard_coordinate = t - 1;
            gameboard_coordinate_flag = 1;
            printf("t = %d flag = 1 (normal)\n", gameboard_coordinate);
        }

        if (t == height && gameboard_coordinate_flag == 0)
        {
            gameboard_coordinate = t - 1;
            gameboard_coordinate_flag = 1;
            printf("t = %d flag = 1 (max)\n", gameboard_coordinate);
        }
        t++;
    }
    while (tetremino_add_flag_1 == 0)
    {
        for (int k = 0; k < 3; k++)
        {
            if (tetremino[tetremino_row][k] == 1 && gameboard[gameboard_coordinate][coordinate + k])
            {
                printf("\nCheck: (%d,%d)\n", gameboard_coordinate, coordinate + k);
                tetremino_add_flag = 0;
            }
        }

        if (tetremino_add_flag == 1)
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    gameboard[gameboard_coordinate - 3 + i][coordinate + j] = tetremino[i][j] + gameboard[gameboard_coordinate - 3 + i][coordinate + j];
                    printf("\nAdd: (%d,%d)\n", gameboard_coordinate - 3 + i, coordinate + j);
                    printf("gameboard:%d\n", gameboard[gameboard_coordinate - 3 + i][coordinate + j]);
                }
            }
            tetremino_add_flag_1 = 1;
        }
        if (tetremino_add_flag == 0)
        {
            printf("j--\n");
            gameboard_coordinate--;
        }

        if (gameboard_coordinate == -1)
        {
            printf("Gameover\n");
            tetremino_add_flag_1 == 1;
            // gameover
        }
    }
}