#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char names[2][20];
char symbols[] = {'X', 'O'};
char board[3][3];

void initializeGameBoard(void)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(void)
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < 2)
            {
                printf("|");
            }
        }
        printf("\n");
        if (i < 2)
        {
            printf("-----------\n");
        }
    }
    printf("\n");
}

bool checkForWinner(void)
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
        {
            return true;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
        {
            return true;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
    {
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
    {
        return true;
    }
    
    return false;
}

bool emptySpaces(void)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                return true;
            }
        }
    }
    return false;
}

void placeSymbol(char symbol)
{
    int row, column;
    while (1)
    {
        printf("%s, enter your move (column then row): ", names[symbol - 'X']);
        scanf("%d%d", &row, &column);
        if (row >= 1 && row <= 3 && column >= 1 && column <= 3 && board[row-1][column-1] == ' ')
        {
            board[row-1][column-1] = symbol;
            break;
        }
        else
        {
            printf("That spot is taken! Try again.\n");
        }
    }
}

void computerMove(char symbol)
{
    int row, column;
    while (1)
    {
        row = rand() % 3;
        column = rand() % 3;
        if (board[row][column] == ' ')
        {
            board[row][column] = symbol;
            break;
        }
    }
}

void chooseOpponent(int *opponent)
{
    printf("Choose who you want to play against:\n");
    printf("1. Friend\n");
    printf("2. Computer\n");
    scanf("%d", opponent);
}

int main(void)
{
    int jucator;
    bool finish = false;
    bool turn = true;
    char symbol;
    chooseOpponent(&jucator);
    printf("Introduceți numele dumneavoastra: ");
    scanf("%s", names[0]);
    strcpy(names[1], "Computer");
    
    initializeGameBoard();
    while (!finish)
    {
        displayBoard();
        symbol = turn ? 'X' : 'O';
        if (jucator == 1)
        {
            if (turn)
            {
                placeSymbol(symbol);
            }
            else
            {
                placeSymbol(symbol);
            }
        }
        else
        {
            if (turn)
            {
                placeSymbol(symbol);
            }
            else
            {
                computerMove(symbol);
            }
        }
        if (checkForWinner())
        {
            displayBoard();
            printf("%s câștigă!\n", names[symbol - 'X']);
            finish = true;
        }
        else if (!emptySpaces())
        {
            displayBoard();
            printf("Egal!\n");
            finish = true;
        }
        turn = !turn;
    }
    
    return 0;
}
