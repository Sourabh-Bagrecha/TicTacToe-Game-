// Author- Sourabh G Bagrecha
// C Language
// TIC-TAC-TOE GAME

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void printBoard();
int checkWin();

char board[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

// player-1  as 'X'   and    player-2 as 'O'
void main()
{
  int player = 1, input, status = -1;
  printBoard();

  while (status == -1)
  {
    player = (player%2 == 0) ? 2 : 1;
    char mark = (player == 1) ? 'X' : 'O';
    printf("Please Enter Number For Player %d\n", player);
    scanf("%d", &input);

    if (input<1 || input>9)
    {
      printf("Invalid Input.");
    }

    board[input] = mark;
    printBoard();

    int result = checkWin();

    if (result == 1)
    {
      printf("CONGRATS..!! Player %d is the Winner\n", player);
    }
    else if (result == 0)
    {
      printf("Match Draw");
      return;
    }

    player++;
  }
}

void printBoard()
{
  system("cls");
  printf("\n\n\n");
  printf("******TIC-TAC-TOE*****\n");
  printf("      |      |     \n");
  printf("   %c  |  %c   |   %c \n", board[1], board[2], board[3]);
  printf("______|______|_____\n");
  printf("      |      |     \n");
  printf("   %c  |  %c   |  %c \n", board[4], board[5], board[6]);
  printf("______|______|_____\n");
  printf("      |      |     \n");
  printf("   %c  |  %c   |  %c \n", board[7], board[8], board[9]);
  printf("      |      |     \n");
  printf("\n\n\n");
}

int checkWin()
{

  if (board[1] == board[2] && board[2] == board[3])
  {
    return 1;
  }

  if (board[4] == board[5] && board[5] == board[6])
  {
    return 1;
  }

  if (board[7] == board[8] && board[8] == board[9])
  {
    return 1;
  }

  if (board[1] == board[4] && board[4] == board[7])
  {
    return 1;
  }

  if (board[2] == board[5] && board[5] == board[8])
  {
    return 1;
  }

  if (board[3] == board[6] && board[6] == board[9])
  {
    return 1;
  }

  if (board[1] == board[5] && board[5] == board[9])
  {
    return 1;
  }

  if (board[3] == board[5] && board[5] == board[7])
  {
    return 1;
  }

  int count=0;
  for (int i = 1; i <= 9; i++)
  {
    if (board[i] == 'X' || board[i] == 'O')
    {
       count++;
    }
    if (count == 9)
    {
      return 0;
    }
    return -1;
  }
}