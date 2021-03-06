#include <iostream>
#include <string>
using namespace std;

int board[3][3];
bool gameActive = 1;
int turnsTaken = 0;
bool playerTurn = 0; // 0 is X and 1 is O
bool debugEnabled = 1;
bool gameLoop = 1;

void resetBoard();
void showBoard();
void makeMove();
int checkWinner();
void checkWin();
void debugOut(string output);
char getPlayerLetter(int playerNumber);

int main(){
    while(gameLoop == 1){
        resetBoard();
        while(gameActive == 1){
            showBoard();
            makeMove();
        }//cout << "Play Again? (1 to play again)" << endl;
        //cin >> gameLoop;
    }
    return 0;
}

void resetBoard(){
    for(int i = 0; i < 3; i++){
       for(int j = 0; j < 3; j++){
           board[i][j] = 0;
       }
    }
}

void showBoard(){
    cout << "  0   1   2 " << endl << endl
         << "0 " << getPlayerLetter(board[0][0]) << " | " << getPlayerLetter(board[0][1]) << " | " << getPlayerLetter(board[0][2]) << endl
         << "----+---+----" << endl
         << "1 " << getPlayerLetter(board[1][0]) << " | " << getPlayerLetter(board[1][1]) << " | " << getPlayerLetter(board[1][2]) << endl
         << "----+---+----" << endl
         << "2 " << getPlayerLetter(board[2][0]) << " | " << getPlayerLetter(board[2][1]) << " | " << getPlayerLetter(board[2][2]) << endl;
}

int checkWinner(){
    if( (board[0][0] == board[0][1]) && (board[0][0] == board[0][2]) ){
        if(board[0][0] != 0){
            debugOut("END 1");
            return board[0][0];
        }
    }
    if( (board[1][0] == board[1][1]) && (board[1][0] == board[1][2]) ){
        if(board[1][0] != 0){
            debugOut("END 2");
            return board[1][0];
        }
    }
    if( (board[2][0] == board[2][1]) && (board[2][0] == board[2][2]) ){
        if(board[2][0] != 0){
            debugOut("END 3");
            return board[2][0];
        }
    }
    if( (board[0][0] == board[1][0]) && (board[0][0] == board[2][0]) ){
        if(board[0][0] != 0){
            debugOut("END 4");
            return board[0][0];
        }
    }
    if( (board[0][1] == board[1][1]) && (board[0][1] == board[2][1]) ){
        if(board[0][1] != 0){
            debugOut("END 5");
            return board[0][1];
        }
    }
    if( (board[0][2] == board[1][2]) && (board[0][2] == board[2][2]) ){
        if(board[0][2] != 0){
            debugOut("END 6");
            return board[0][2];
        }
    }
    if( (board[0][0] == board[1][1]) && (board[0][0] == board[2][2]) ){
        if(board[0][0] != 0){
            debugOut("END 7");
            return board[0][0];
        }
    }
    if( (board[0][2] == board[1][1]) && (board[0][2] == board[2][0]) ){
        if(board[0][2] != 0){
            debugOut("END 8");
            return board[0][2];
        }
    }
    return 0;
}
void checkWin(){
    if(checkWinner() == 1){
        //X Wins
        cout << "Player X Wins!" << endl;
        showBoard();
        gameActive = 0;
    }else if(checkWinner() == 2){
        //Y Wins
        cout << "Player O Wins!" << endl;
        showBoard();
        gameActive = 0;
    }else{
        debugOut("No win declared yet");
    }
}

void makeMove(){
    int row;
    int column;
    bool turnOver = 0;
    playerTurn = (turnsTaken % 2);
    cout << "Player ";
    if(playerTurn == 0){
        cout << "X";
    }else if(playerTurn == 1){
        cout << "O";
    }cout << "'s turn.\n";
    while(turnOver == 0){
        cout << "Select a row: ";
        cin >> row;
        cout << "Select a column: ";
        cin >> column;
        if(board[row][column] == 0){
            board[row][column] = (playerTurn + 1);
            turnOver = 1;
        }
    }
    checkWin();
    turnsTaken++;
}


void debugOut(string output){
    if(debugEnabled == 1){
        cout << output << endl;
    }
}

char getPlayerLetter(int playerNumber){
    if(playerNumber == 1){
        return 'X';
    }else if(playerNumber == 2){
        return 'O';
    }else{
        return ' ';
    }
}

