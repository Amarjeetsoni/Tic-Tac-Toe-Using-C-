// Number Pridiction Game
// Full Video Link in the discription Section
#include<bits/stdc++.h>		// to include all Lib
using namespace std;
int main(){
	int number;		// to get Max limit of Number
	cout<<"Enter Maximum Limit of Number: ";
	cin>>number;
	
	int randVal = (rand())%number;  // to generate a random Number
	
	int count = 0;
	int pridictionVal;
	cout<<"Enter Your Pridiction: ";
	cin>>pridictionVal;
	count++;	// First Guess
	while(pridictionVal != randVal){
		// Now check if pridiction value is greater than Actual Value
		if(pridictionVal > randVal){
			cout<<"\nYou have choosed a Greater Value, Please choose some smaller Value!!";
		}else{
			cout<<"\nYou have choosen a Smaller Value, Please choose Some greater Value!!";
		}
		count++;
		cout<<"\nEnter "<<count<<" Prediction: ";
		cin>>pridictionVal;
	}
	
	cout<<"\nYou Guess the Number "<<randVal<<" correctly in "<<count<<" Attempts!!";
	
	cout<<"\nThanks!!!";
}
