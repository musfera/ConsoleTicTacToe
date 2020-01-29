
//  Created by Musfera Khan
//

#include "tictactoe.hpp"
#include <iostream>

using namespace std;


char board [3][3]= {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
int temp1;
int temp2;
bool valid =false;

void turn();
void check();
void wins();

char player = 'X';
int rem_slots = 9;

void draw(){
    //prints board at each turn
    cout << " 0    1    2 \n";
    for (int i =0; i < 3; i++){
        cout << i << " | ";
        for(int j =0; j < 3; j++){
            cout << board[i][j];
            cout << " | ";
        }
        cout << "\n";
        cout << " ------------ \n";
    }
    
    
    turn();
    
}

void turn(){
    
    while(!valid){
    cout << "Turn for player " << player << ". Enter valid grid location x,y between 0 to 2 \n";
    cout << "first number: \n";
    cin >> temp1;
    cout << "second number: \n";
    cin >> temp2;
        
    if(temp1 < 0 || temp1 > 2 || temp2 < 0 || temp2 >2){
        cout << "invalid input. Please enter again: \n";
        continue;
    }
    else if (board[temp1][temp2] == 'X' || board[temp1][temp2] == 'O'){
        cout << "position is already taken. Please enter again: \n";
        continue;
    }
    else{
        valid = true;
    }

    }
    
    board[temp1][temp2] = player;
    
    valid = false;
   
    
    check();
}

void check(){
    
    if((board[0][0] == 'X' || board[0][0] == 'O') && board[0][0] == board[0][1] && board[0][0] == board[0][2]) wins();
    else if((board[1][0] == 'X' || board[1][0] == 'O') && board[1][0] == board[1][1] && board[1][0] == board[1][2]) wins();
    else if((board[2][0] == 'X' || board[2][0] == 'O') && board[2][0] == board[2][1] && board[2][0] == board[2][2]) wins();
    else if((board[0][0] == 'X' || board[0][0] == 'O') && board[0][0] == board[1][0] && board[0][0] == board[2][0]) wins();
    else if((board[0][1] == 'X' || board[0][1] == 'O') && board[0][1] == board[1][1] && board[0][1] == board[2][1]) wins();
    else if((board[0][2] == 'X' || board[0][2] == 'O') && board[0][2] == board[1][2] && board[0][2] == board[2][2]) wins();
    else if((board[0][0] == 'X' || board[0][0] == 'O') && board[0][0] == board[1][1] && board[0][0] == board[2][2]) wins();
    else if((board[0][2] == 'X' || board[0][2] == 'O') && board[0][2] == board[1][1] && board[0][2] == board[2][0]) wins();

    rem_slots--;
    if (rem_slots ==0) wins();
    else{
        if (player == 'X'){
            player ='O';
            draw();
        }
        else {
            player ='X';
            draw();
        }
    }
    
    
}

void wins(){
    if (rem_slots == 0) cout << "There's a tie! \n";
    cout << "Player " << player << "wins! \n";
    cout << "Play again? 1 for yes and 0 for no \n";
    
    int again;
    cin >> again;
    if (again == 1) {
        rem_slots = 9;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                board[i][j] = ' ';
            }
        }
        draw();
    }
    else{
        cout << "exiting \n";
        return;
    }
    
}



int main(){
    cout << "Welcome to Tic Tac Toe! player X starts. \n";
    
    draw();
   
    
}
