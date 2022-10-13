#include <iostream>
#include <limits>

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
int row, col;
bool gameOver;
char playerTurn = 'X';

enum gameStatus {TIE, WIN, UNRESOLVED};


using namespace std;

void drawBoard(){
    cout << "     |     |" << endl;
    cout << "  " << board[0][0] <<"  |  "<<board[0][1]<<"  |  "<<board[0][2]  << endl;
    cout << "_____|_____|_____"  << endl;
    cout << "     |     |" << endl;
    cout << "  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]  << endl;
    cout << "_____|_____|_____"  << endl;
    cout << "     |     |" << endl;
    cout << "  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2] << endl;
    cout << "     |     |" << endl;

}

bool checkGameStatus(){

    return false;
}

bool validatePosition(int row, int col){
    return (row <= 3 && 1 <= row) && (col <= 3 && 1 <= row) && (board[row-1][col-1] == ' ') ? true : false;
}

void getPlayerMove(){

    //Loop forever
    for (;;) {
        cout << "It is Player " << playerTurn << " turn." << endl;
        cout << "Specify your move. (Row, Column EX: 1 3)" << endl << endl;
        if (cin >> row >> col && validatePosition(row, col)) {
            break;
        } else {
            cout << "Please enter a valid position! (Row 0-2, Column 0-2)" << endl << endl;
            //Clear the failed state of stream
            cin.clear();

            /*
             * numeric_limits<streamsize>::max() -- sets the maximum number of characters to ignore.
             * Since this is the upper limit on the size of a stream,
             * you are effectively telling cin that there is no limit to the number of characters to ignore.
             *
             * '\n' -- sets the delimiter, i.e. the character after which cin stops ignoring
             */
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    if(playerTurn == 'X'){
        playerTurn = 'O';
    } else {
        playerTurn = 'X';
    }

}

int main() {
    while(checkGameStatus()){
        drawBoard();
        getPlayerMove();
    }
    cout << "Game Over!" << endl;

    return 0;
}
