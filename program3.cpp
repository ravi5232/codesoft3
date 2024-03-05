#include <iostream>
#include <vector>

using namespace std;

// Function to print the Tic-Tac-Toe game board
void print_board(const vector<vector<char>>& board)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if a player has won the game
bool check_win(const vector<vector<char>>& board, char c)
{
    // Check rows and columns
    for (int i = 0; i < 3; i++)
    {
        if ((board[i][0] == c && board[i][1] == c && board[i][2] == c) ||
            (board[0][i] == c && board[1][i] == c && board[2][i] == c))
        {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == c && board[1][1] == c && board[2][2] == c) ||
        (board[0][2] == c && board[1][1] == c && board[2][0] == c))
    {
        return true;
    }

    return false;
}

// Function to check if the game is a draw
bool check_draw(const vector<vector<char>>& board)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == '-')
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    vector<vector<char>> board(3, vector<char>(3, '-'));
    int row, col;
    bool x_turn = true;
    char current_player = 'X';
    bool won = false;
    bool draw = false;

    while (!won && !draw)
    {
        print_board(board);
        cout << "Player " << current_player << ", enter your move (row and column): ";
        cin >> row >> col;

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == '-')
        {
            board[row][col] = current_player;

            if (check_win(board, current_player))
            {
                print_board(board);
                cout << "Player " << current_player << " wins!" << endl;
                won = true;
            }
            else if (check_draw(board))
            {
                print_board(board);
                cout << "It's a draw!" << endl;
                draw = true;
            }
            else
            {
                x_turn = !x_turn;
                current_player = x_turn ? 'X' : 'O';
            }
        }
        else
        {
            cout << "Invalid move. Try again." << endl;
        }
    }

    cout << "Do you want to play again? (y/n): ";
    char response;
    cin >> response;

    if (response == 'y' || response == 'Y')
    {
        board = vector<vector<char>>(3, vector<char>(3, '-'));
        x_turn = true;
        current_player = 'X';
        won = false;
        draw = false;
        main();
    }

    return 0;
}