// Tic-Tac-Toe game in C++
#include<bits/stdc++.h>		// to include All Liberary
#include<windows.h>			// to access colour change on console
using namespace std;
void consoleColour(int colorNum){		// Code for console Colour change colorNum >= 1 && <= 7
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}
void delayWithDash(){					// Code to print dash with the delay of 200 mili seconds.
	for(int i = 0; i < 5; i++){
		cout<<"-";
		Sleep(200);
	}
}
char checkWinner(char arr[3][3]){		// To check for winner
	for(int i = 0; i < 3; i++){			// each row scan 1 2 3, 4 5 6, 7 8 9 
			if(arr[i][0] != '0' && arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]){
				return arr[i][0];
			}
	}
	for(int i = 0; i < 3; i++){			// each coloum 1 4 6, 2 5 8, 3 6 9
			if(arr[0][i] != '0' && arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i]){
				return arr[0][i];
			}
	}
	if(arr[0][0] != '0' && arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]){ 		// check diagonal elements
		return arr[0][0];
	}
	if(arr[0][2] != '0' && arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]){		// check second diagonal elements
		return arr[0][2];
	}
	return '0';
}
int main(){
	char arr[3][3];			// to store the value of players choise
	
	cout<<endl;
	string playerName1, playerName2;
	consoleColour(2);		// To change the color to green
	cout<<"Enter First Player Name: ";
	consoleColour(7);	    // to change colour to regular white colour
	getline(cin, playerName1);		// to get the string with the space
	consoleColour(2);
	cout<<"Enter Second Player Name: ";
	consoleColour(7);
	getline(cin, playerName2);	
	consoleColour(3);
	cout<<"\n\nRules of the game: \n1. Enter place number where you want to insert your number\n2. Both the player will get "
	<<" their turn Alternate\n3. Enter Only valid position \n\n below is the Initial Places.\n\n\n";
	consoleColour(4);
	for(int i = 0; i < 3; i++){			// print the 3*3 matrix in this format.
		cout<<"\t";
		for(int j = i*3; j < i*3+3; j++){
			cout<<j+1;
			if(j != i*3+2){
				cout<<" | ";
			}
		}
		cout<<endl<<"\t";
		if(i != 2){
			for(int i = 0; i < 3; i++){
				cout<<"---";
			}
		}
		cout<<endl;
	}
label: 										// From here code again will starts if user want to play again.
	for(int i = 0; i < 3; i++){				// set initial value of array to '0'
		for(int j = 0; j < 3; j++){
			arr[i][j] = '0';
		}
	}
	cout<<"\n\n--------------------- Toss Time -----------------------\n\n";
	consoleColour(2);
	cout<<playerName1;
	consoleColour(5);
	cout<<" enter a number : for Head Press 0 / for Tail Press 1: ";
	consoleColour(7);
	int randomNumber;
	cin>>randomNumber;
	while(randomNumber != 0 && randomNumber != 1){
		consoleColour(4);
		cout<<"Please Enter 0 Or 1 Only !\n";
		consoleColour(2);
		cout<<playerName1;
		consoleColour(5);
		cout<<", Enter 0 or 1 : ";
		consoleColour(7);
		cin>>randomNumber;
	}
	cout<<endl;
	delayWithDash();
	cout<<" Coin tossed ";
	delayWithDash();
	cout<<"\n\n";
	int turn = rand() % 2;		// to generate a random value in 0 or 1
	if(turn == randomNumber){	// check & validate the user enties based on that we will deside who will start.
			cout<<endl;
			consoleColour(2);
			cout<<playerName1;
			cout<<" You Won the Toss and you will Go First !";
			cout<<endl<<endl;
			turn = 0;
	}else{
			cout<<endl;
			consoleColour(2);
			cout<<playerName1;
			consoleColour(4);
			cout<<" You lost the Toss and ";
			consoleColour(2);
			cout<<playerName2; 
			consoleColour(4);
			cout<<" will go first\n\n---------------------------------------------------------------\n\n";
			turn = 1;
	}
	consoleColour(7);
	while(true){				// infinite loop
		if(turn % 2 == 0){		// based on turn user will get their chance alternatevily
			bool flag = true;
			do{
			cout<<endl;
			consoleColour(2);
			cout<<playerName1;
			consoleColour(7);
			cout<<" Enter your choise: ";
			int temp;
			cin>>temp;		// User entered choise
			int i = 0, j = 0;
			if(temp > 9 || temp <= 0 ){		// if choise is >9 or <= 0 the give error value.
				consoleColour(4);
				cout<<"\n\nYour Choise is Wrong! Please select Value from 1-9 as displayed in the Box.";
				continue;
			}	
			if(temp <= 3){		// Now based on place value decide i and j value of the 2d array
				i = 0;
				j = temp % 3 == 0 ? 2 : (temp % 3)-1;
			}else if(temp <= 6){
				i = 1;
				j = temp % 3 == 0 ? 2 : (temp % 3)-1;
			}else{
				i = 2;
				j = temp % 3 == 0 ? 2 : (temp % 3)-1;
			}
			if(arr[i][j] == '0'){		// Place value 'X' for player 1
				arr[i][j] = 'X';		// After placing value break the current do while loop
				break;
			}else{						// if already value inserted then throug an error
				consoleColour(4);
				cout<<"\n\nEntered postion Already filled! Please try other.";
				continue;
			}	
			}while(flag); 	// check condition 
			turn++;
		}else{			// same goes for second user
			bool flag = false;
			do{
			cout<<endl;
			consoleColour(2);
			cout<<playerName2;
			consoleColour(7);
			cout<<" Enter your choise: ";
			int temp;
			cin>>temp;
			int i = 0, j = 0;
			if(temp > 9 || temp <= 0 ){
				consoleColour(4);
				cout<<"\n\nYour Choise is Wrong! Please select Value from 1-9 as displayed in the Box.";
				continue;
			}
			if(temp <= 3){
				i = 0;
				j = temp % 3 == 0 ? 2 : (temp % 3)-1;
			}else if(temp <= 6){
				i = 1;
				j = temp % 3 == 0 ? 2 : (temp % 3)-1;
			}else{
				i = 2;
				j = temp % 3 == 0 ? 2 : (temp % 3)-1;
			}
			if(arr[i][j] == '0'){
				arr[i][j] = 'O';
				break;
			}else{
				consoleColour(4);
				cout<<"\n\nEntered postion Already filled! Please try other.";
				continue;
			}	
			}while(true);
			turn--;
		}
		int draw = 0;		// Check if all position is filled up
		for(int i = 0; i < 3; i++){
			cout<<"\t";
			int k = 0;
		for(int j = i*3; j < i*3+3; j++){		// print 3*3 matrix after each iteration
			if(arr[i][k] != '0'){
				if(arr[i][k] == 'O'){
					consoleColour(4);
				}else{
					consoleColour(2);
				}
				draw++;
				cout<<arr[i][k];
				consoleColour(7);
			}else{
				consoleColour(5);
				cout<<j+1;	
				consoleColour(7);
			}
			k++;
			
			if(j != i*3+2){
				cout<<" | ";
			}
		}
			cout<<endl<<"\t";
		if(i != 2){
			for(int i = 0; i < 3; i++){
				cout<<"---";
			}
		}
			cout<<endl;
		}
		
		char ch = checkWinner(arr);			// Call function to check winner 
		if(ch != '0'){						// based on the return type decide who won.
			if(ch == 'X'){
				cout<<"\n\n";
				delayWithDash();
				consoleColour(2);
				cout<<"\nWe have the Winner!!";
				cout<<endl;
				consoleColour(7);
				delayWithDash();
				cout<<endl;
				consoleColour(2);
				cout<<playerName1;
				consoleColour(4);
				cout<<" You Won the Match!!!";
				cout<<endl;
				consoleColour(7);
				delayWithDash();
				break;
			}else{
				cout<<"\n\n";
				delayWithDash();
				consoleColour(2);
				cout<<"\nWe have the Winner!!";
				cout<<endl;
				consoleColour(7);
				delayWithDash();
				cout<<endl;
				consoleColour(2);
				cout<<playerName2;
				consoleColour(4);
				cout<<" You Won the Match!!!";
				cout<<endl;
				consoleColour(7);
				delayWithDash();
				break;
			}
		}
		if(draw == 9){			// If all pos is filled up and no one won then match draw.
			consoleColour(7);
			cout<<endl;
			delayWithDash();
			cout<<endl;
			consoleColour(4);
			cout<<"Match Draw";
			consoleColour(7);
			cout<<endl;
			delayWithDash();
			cout<<endl;
			break;
		}
	}
	int again;		// if user want to play again then start again from lable 
	cout<<"\n\n Want To Play Again ???\n Press 1 To play Again, else press any key to exit.";
	cin>>again;
	if(again == 1){
		goto label;		// from here
	}else{				// else break the code.
		consoleColour(2);
		cout<<"\n\nThanks for Playing...!\n\n";
	}
}

Thanks for Waching. You can find the code on given link in the discription section.


Thanks.

