/* Simple TicTacToe Game
 * Version 1.0
 * Author: Ethan Seligman
*/

#include <iostream>
#include <string>

#define logln(x) std::cout << x << std::endl
#define log(x) std::cout << x
#define input(x) std::cin >> x
#define RUN 1
#define STOP 0
#define b(x, y) board[x][y]

char board[3][3];

class Game
{
public:
    char turn;

    Game()
    {
        this->turn = 'X';
    }

    char getTurn()
    {
        return this->turn;
    }

    void generateBoard()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                b(i, j) = '-';
            }
        }
    }

    void display()
    {
        logln("");
        for (int i = 0; i < 3; i++)
        {
            if (i >= 1)
            {
                logln("\n");
            }
            for (int j = 0; j < 3; j++)
            {
                if (j == 0)
                {
                    log("   ");
                }
                log(board[i][j] << "   ");
            }
        }
        logln("\n");
    }

    void start()
    {
        this->generateBoard();
        logln("TIC TAC TOE - X BEGINS FIRST.");
    }

    int setTurn(int box)
    {
        char t = this->turn;
        switch (box)
        {
        case (1):
            if (b(2, 0) != 'X' && b(2, 0) != 'O')
            {
                b(2, 0) = t;
            }
            else
            {
                return -1;
            }
            break;
        case (2):
            if (b(2, 1) != 'X' && b(2, 1) != 'O')
            {
                b(2, 1) = t;
            }
            else
            {
                return -1;
            }
            break;
        case (3):
            if (b(2, 2) != 'X' && b(2, 2) != 'O')
            {
                b(2, 2) = t;
            }
            else
            {
                return -1;
            }
            break;
        case (4):
            if (b(1, 0) != 'X' && b(1, 0) != 'O')
            {
                b(1, 0) = t;
            }
            else
            {
                return -1;
            }
            break;
        case (5):
            if (b(1, 1) != 'X' && b(1, 1) != 'O')
            {
                b(1, 1) = t;
            }
            else
            {
                return -1;
            }
            break;
        case (6):
            if (b(1, 2) != 'X' && b(1, 2) != 'O')
            {
                b(1, 2) = t;
            }
            else
            {
                return -1;
            }
            break;
        case (7):
            if (b(0, 0) != 'X' && b(0, 0) != 'O')
            {
                b(0, 0) = t;
            }
            else
            {
                return -1;
            }
            break;
        case (8):
            if (b(0, 1) != 'X' && b(0, 1) != 'O')
            {
                b(0, 1) = t;
            }
            else
            {
                return -1;
            }
            break;
        case (9):
            if (b(0, 2) != 'X' && b(0, 2) != 'O')
            {
                b(0, 2) = t;
            }
            else
            {
                return -1;
            }
            break;
        default:
            return -1;
            break;
        }
        //change turn after move
        if (t == 'X')
        {
            this->turn = 'O';
        }
        else
        {
            this->turn = 'X';
        }
        return 1;
    }

    int check()
    {
        if (b(0, 0) == b(0, 1) && b(0, 1) == b(0, 2) && b(0, 0) != '-')
        {
            return 1;
        }
        else if (b(1, 0) == b(1, 1) && b(1, 1) == b(1, 2) && b(1, 0) != '-')
        {
            return 1;
        }
        else if (b(2, 0) == b(2, 1) && b(2, 1) == b(2, 2) && b(2, 0) != '-')
        {
            return 1;
        }
        else if (b(0, 0) == b(1, 0) && b(1, 0) == b(2, 0) && b(0, 0) != '-')
        {
            return 1;
        }
        else if (b(0, 1) == b(1, 1) && b(1, 1) == b(2, 1) && b(0, 1) != '-')
        {
            return 1;
        }
        else if (b(0, 2) == b(1, 2) && b(1, 2) == b(2, 2) && b(0, 2) != '-')
        {
            return 1;
        }
        else if (b(0, 0) == b(1, 1) && b(1, 1) == b(2, 2) && b(0, 0) != '-')
        {
            return 1;
        }
        else if (b(0, 2) == b(1, 1) && b(1, 1) == b(2, 0) && b(0, 2) != '-')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

int main()
{

    Game game = Game();

    game.start();

    int num_turns = 0;

    int state = RUN;
    while (state == RUN)
    {
        game.display();
        int box;
        log("Enter a move for " << game.getTurn() << ": ");
        input(box);
        log("\n");
        while (game.setTurn(box) != 1)
        {
            log("Move out of bounds.\nEnter a move for " << game.getTurn() << ": ");
            input(box);
            log("\n");
        }

        if (num_turns >= 3)
        {
            if (game.check() == 1)
            {
                state = STOP;
                game.display();
                if (game.getTurn() == 'X')
                {
                    logln("O WON!\n");
                }
                else
                {
                    logln("X WON!\n");
                }
            }
            else
            {
                system("CLS");
            }
        }
        else
        {
            if (num_turns == 9)
            {
                state = STOP;
                game.display();
                logln("DRAW!");
            }
            else
            {
                system("CLS");
            }
        }
        num_turns++;
    }

    system("PAUSE");
    return 0;
}