#include <iostream>

//Необходимо подсчитать количество '0' выше и ниже главной и пробочной диагоналей матрицы заданного размера.

void aboveTheMain(int** matrix, int row)
{
    int aboveTheMainDiagonal = 0;

    for (int i = 0; i < row - 1; i++)
    {
        for (int k = i + 1; k < row; k++)
        {
            if (matrix[i][k] == 0)
                aboveTheMainDiagonal++;
        }
    }

    std::cout << "Выше главной диагонали " << aboveTheMainDiagonal << std::endl;
}

void belowTheMain(int** matrix, int row)
{
    int belowTheMainDiagonal = 0;

    for (int i = 1; i < row; i++)
    {
        for (int k = 0; k < i; k++)
        {
            if (matrix[i][k] == 0)
                belowTheMainDiagonal++;
        }
    }

    std::cout << "Ниже главной диагонали " << belowTheMainDiagonal << std::endl;
}

void aboveTheSide(int** matrix, int row)
{
    int aboveTheSideDiagonal = 0;

    for (int i = 0; i < row - 1; i++)
    {
        for (int k = 0; k < row - 1 - i; k++)
        {
            if (matrix[i][k] == 0)
                aboveTheSideDiagonal++;
        }
    }

    std::cout << "Выше побочной диагонали " << aboveTheSideDiagonal << std::endl;
}

void belowTheSide(int** matrix, int row) 
{
    int belowTheSideDiagonal = 0;

    for (int i = 1; i < row; i++)
    {
        for (int k = row - i; k < row; k++)
        {
            if (matrix[i][k] == 0)
                belowTheSideDiagonal++;
        }
    }

    std::cout << "Ниже побочной диагонали " << belowTheSideDiagonal << std::endl;
}