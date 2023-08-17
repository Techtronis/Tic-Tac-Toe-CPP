//By Alexis Jost
//Took me about 2.5 hours to make
//2023.17.06

#include <iostream>
using namespace std;

//declares an empty board
string board[9] = {"-", "-", "-",
                "-", "-", "-",
                "-", "-", "-"};

//draws the board in terminal
void drawBoard()
{
    std::cout << board[0] << board[1] << board[2] << endl
    << board[3] << board[4] << board[5] << endl
    << board[6] << board[7] << board[8] << endl;
}

//checks if theres a win could be possible
void checkRow(int y, int z, string player)
{
    if(board[z] == player && board[z - 1] == player && board[y] == player)
    {
        std::cout << player << " wins in row" << endl;
        abort();
    }
}

void checkColumn(int y, int z, string player)
{
    if(board[z] == player && board[y] == player && board[z - 3] == player)
    {
        std::cout << player << " wins in column" << endl;
        abort();
    }
}

void checkDiagonalRight(int y, int z, string player)
{
    if(board[z] == player && board[y] == player && board[z - 4] == player)
    {
        std::cout << player << " wins in diagonal -->" << endl;
        abort();
    }
}

void checkDiagonalLeft(int y, int z, string player)
{
    if(board[z] == player && board[y] == player && board[z - 2] == player)
    {
        std::cout << player << " wins in diagonal <--" << endl;
        abort();
    }
}

//checks the win by player
void checkWin(string player)
{
    checkRow(0, 2, player);
    checkRow(3, 5, player);
    checkRow(6, 8, player);
    checkColumn(0, 6, player);
    checkColumn(1, 7, player);
    checkColumn(2, 8, player);
    checkDiagonalRight(0, 8, player);
    checkDiagonalLeft(2, 6, player);
}

//handles the game
void play()
{
    int play;
    int player = 0;
    int playCounts = 0;

    while(playCounts <= 8)
    {   
        //using modulo to define odd number to X and vice versa
        if(playCounts %2 == 0)
        {
            player++;
            std::cout << "X's turn" << endl;
            std::cin >> play;
            play--;
            playCounts++;

            if(board[play] == "X" || board[play] == "0")
            {
                std::cout << "Spot already taken, try again:" << endl;
                std::cin >> play;
                play--;
            }
            else if(play > 9 || play < 0){
                std::cout << "Number Invalid, try again:" << endl;
                std::cin >> play;
                play--;
            }
            board[play] = "X";
            drawBoard();
            checkWin("X");

        }
        else if (playCounts %2 != 0)
        {
            player++;
            std::cout << "0's turn" << endl;
            std::cin >> play;
            play--;
            playCounts++;

            if(board[play] == "X" || board[play] == "0")
            {
                std::cout << "Spot already taken, try again:" << endl;
                std::cin >> play;
                play--;
            }
            else if(play > 8 || play < 0){
                std::cout << "Number Invalid, try again:" << endl;
                std::cin >> play;
                play--;
            }

            board[play] = "0";
            drawBoard();
            checkWin("0");
        }
        
    }

    if(playCounts >= 9)
    {
        std::cout << "it's a draw" << endl;
        abort();
    }
}

int main()
{
    play();
    return 0;
}
