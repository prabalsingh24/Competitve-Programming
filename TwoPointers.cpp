//http://codeforces.com/contest/676/problem/C
#include<iostream>
#include<string>
using namespace std;


int main(){
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;

	int leftPointer=0,rightPointer=0;
	int longestString=0;
	int currentString=0;
	int charChanged=0;
	
	while(rightPointer<n){
		if(s[rightPointer]=='a' and rightPointer<n){
			rightPointer++;
			currentString++;
		}
		else if(s[rightPointer]=='b'){
			if(charChanged<k){
				rightPointer++;
				currentString++;
				charChanged++;
			}
			else{
				while(s[leftPointer]=='a'){
					leftPointer++;
					currentString--;
				}
				leftPointer++;
				currentString--;
				charChanged--;
				
			}
		}
		longestString=max(longestString,currentString);
	}
	leftPointer=0,rightPointer=0;
	currentString=0;
	charChanged=0;
	while(rightPointer<n){
		if(s[rightPointer]=='b' and rightPointer<n){
			rightPointer++;
			currentString++;
		}
		else if(s[rightPointer]=='a'){
			if(charChanged<k){
				rightPointer++;
				currentString++;
				charChanged++;
			}
			else{
				while(s[leftPointer]=='b'){
					leftPointer++;
					currentString--;
				}
				leftPointer++;
				currentString--;
				charChanged--;
			}
		}

		longestString=max(longestString,currentString);
	}
	
	cout<<longestString<<endl;	


	return 0;
}