#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void player1();
void player2();

int p1_x = 0, p1_y = 0, p2_x = 0, p2_y = 0, loc = 0, game_count = 0;
char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

void print_board()
{
    printf(" %c | %c | %c\n-----------\n %c | %c | %c \n-----------\n %c | %c | %c \n", board[0][0], board[0][1], board[0][2], board[1][0], board[1][1], board[1][2], board[2][0], board[2][1], board[2][2]);
}

void board_cordinates(char symbol)
{
    switch(loc)
    {
        case 1:
        board[0][0] = symbol;
        break;

        case 2:
        board[0][1] = symbol;
        break;

        case 3:
        board[0][2] = symbol;
        break;

        case 4:
        board[1][0] = symbol;
        break;

        case 5:
        board[1][1] = symbol;
        break;

        case 6:
        board[1][2] = symbol;
        break;

        case 7:
        board[2][0] = symbol;
        break;

        case 8:
        board[2][1] = symbol;
        break;

        case 9:
        board[2][2] = symbol;
        break;

        default:
        printf("Invalid input, please type again!");
        if(symbol == 'x')
        {
            player1();
        }
        else if(symbol == 'o')
        {
            player2();
        }
    }
}

void player1()
{
    printf("Enter co-ordinates: ");
    scanf("%d", &loc);
    board_cordinates('x');
}

void player2()
{
    printf("Enter co-ordinates: ");
    scanf("%d", &loc);
    board_cordinates('o');
}

int check_win(char symbol)
{
    if((board[0][0] == symbol && board[0][1] == symbol && board[0][2] == symbol) || (board[1][0] == symbol && board[1][1] == symbol && board[1][2]  == symbol) || (board[2][0] == symbol && board[2][1] == symbol && board[2][2]  == symbol) || (board[0][0] == symbol && board[1][0] == symbol && board[2][0] == symbol) || (board[0][1] == symbol && board[1][1] == symbol && board[2][1]  == symbol) || (board[0][2] == symbol && board[1][2] == symbol && board[2][2]  == symbol) || (board[0][0] == symbol && board[1][1] == symbol && board[2][2]  == symbol) || (board[0][2] == symbol && board[1][1] == symbol && board[2][0]  == symbol))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void main()
{
    char symbol;
    srand(time(NULL));
    while(1)
    {
        game_count++;
        player1();
        if(game_count ==  9)
        {
            print_board();
            printf("It's a tie!\n");
            break;
        }
        if(check_win('x'))
        {
            print_board();
            printf("Player 1 wins!\n");
            break;
        }
        print_board();

        game_count++;
        player2();
        if(check_win('o'))
        {
            print_board();
            printf("Player 2 wins!\n");
            break;
        }
        print_board();
    }
}