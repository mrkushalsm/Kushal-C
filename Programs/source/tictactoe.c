#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void computer();
void player();

int p_x = 0, p_y = 0, c_x = 0, c_y = 0, loc = 0, game_count = 0;
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

void computer()
{
    c_x = rand() % 3, c_y = rand() % 3;
    if(board[c_x][c_y] != 'x')
    {
        board[c_x][c_y] = 'o';
    }
    else
    {
        computer();
    }
}

void player()
{
    printf("Enter co-ordinates: ");
    scanf("%d%d", &p_x, &p_y);
    board[p_x][p_y] = 'x';
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
        player();
        if(game_count ==  9)
        {
            print_board();
            printf("It's a tie!\n");
            break;
        }
        if(check_win('x'))
        {
            print_board();
            printf("Player wins!\n");
            break;
        }

        game_count++;
        computer();
        if(check_win('o'))
        {
            print_board();
            printf("Computer wins!\n");
            break;
        }
        print_board();
    }
}