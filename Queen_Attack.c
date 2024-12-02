#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// function to check, if turning true, if 2 queens can attack.
bool canQueensAttack (int row1, int col1, int row2, int col2)
{
    // same row / collumn / diagonal.
    return row1 == row2 || col1 == col2 || abs(row1 - row2) == abs(col1 - col2);
}
// printing the board.
void printBoard(int row1, int col1, int row2, int col2)
{
    printf("  a b c d e f g h\n");
    for (int row = 8; row >=1; row--)
    {
        printf("%d ",row);
        for (int col = 1; col <=8; col++)
        {
            if (row == row1 && col == col1) {
                printf("W ");
            }
            else if (row == row2 && col == col2) {
                printf("B ");
            }
            else
            {
                printf("_ ");
            }
        }
        printf("%d\n", row);
    }
    printf("  a b c d e f g h\n");

}

int main() {
    int row1, col1, row2, col2;
    printf("Enter white queen's position (row/collum): ");
    scanf("%d %d", &row1, &col1);

    printf("Enter black queen's position (row/collum): ");
    scanf("%d %d", &row2, &col2);

    // checking for valid input.
    if (row1 < 1 || row1 > 8 || col1 < 1 || col1 > 8)
    {
        printf("Invalid input\n");
        return 1;
    }
    printBoard(row1, col1, row2, col2);

    // checking if the queens can attack
    if (canQueensAttack(row1, col1, row2, col2))
    {
    printf("Queens can attack eachother\n");
    }
    else
    {
    printf("Queens can't attack eachother\n");
    }
}


