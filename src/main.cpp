#include <iostream>
using namespace std;

int board[3][3];
bool gameActive = 1;
int turnsTaken = 0;
bool playerTurn = 0; // 0 is X and 1 is Y

void resetBoard();
void showBoard();
void makeMove();
int checkWinner();
void checkWin();

int main(){
    resetBoard();
    while(gameActive == 1){
        showBoard();
        makeMove();
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
         << "0 " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl
         << "----+---+----" << endl
         << "1 " << board[1][0] << " | " << board[1][1] << " | " << board[2][2] << endl
         << "----+---+----" << endl
         << "2 " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

int checkWinner(){
    if(board[0][0] == board[0][1] == board[0][2] != 0){
        return board[0][0];
    }else if(board[1][0] == board[1][1] == board[1][2] != 0){
        return board[1][0];
    }else if(board[2][0] == board[2][1] == board[2][2] != 0){
        return board[2][0];
    }else if(board[0][0] == board[1][0] == board[2][0] != 0){
        return board[0][0];
    }else if(board[0][1] == board[1][1] == board[2][1] != 0){
        return board[0][1];
    }else if(board[0][2] == board[1][2] == board[2][2] != 0){
        return board[0][1];
    }else if(board[0][0] == board[1][1] == board[2][2] != 0){
        return board[0][0];
    }else if(board[0][2] == board[1][1] == board[2][0] != 0){
        return board[0][1];
    }else{
        return 0;
    }
}
void checkWin(){
    if(checkWinner() == 1){
        //X Wins
        cout << "Player X Wins!" << endl;
        gameActive = 0;
    }else if(checkWinner() == 2){
        //Y Wins
        cout << "Player Y Wins!" << endl;
        gameActive = 0;
    }else{}
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
    }cout << "'s turn.";
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





