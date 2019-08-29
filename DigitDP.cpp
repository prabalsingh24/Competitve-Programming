#include<iostream>
#include<string>
using namespace std;
string s;
int n;

void count(int sz,int f,long long &ans){
	if(sz>=n){
		return ;
	}
	int limit;
	if(f==0){
		limit=s[sz]-'0';
	}														//DIGIT DP
	else{
		limit=2;
	}
	int number=0;
	for(int digit=0;digit<=1 and digit<=limit;digit++){
		number++;
		if(digit>=limit){
			count(sz+1,0,ans);
		}
		else{
			count(sz+1,1,ans);
		}
	}
	ans=ans*number;
}

int main(){
	cin>>s;
	n=s.length();
	int dp[n];
	int sz=0;
	int f=0;
	long long ans=1;
	count(sz,f,ans);
	cout<<ans<<endl;
	return 0;
}