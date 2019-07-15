#include<iostream>
#include<string>
using namespace std;

bool checkSubsequence(string a,string b,int n,int m){
	if(n==0){
		return true;
	}
	if(m==0){
		return false;
	}
	if(a[n-1]==b[m-1]){
		return checkSubsequence(a,b,n-1,m-1);
	}
	else{
		return checkSubsequence(a,b,n,m-1);
	}

}


void solve(){
	string p,s,t;
	cin>>s>>t>>p;
	int ss[26]={0};
	int tt[26]={0};
	int pp[26]={0};
	for(int i=0;i<s.length();i++){
		ss[s[i]-'a']++;
	}
	for(int i=0;i<p.length();i++){
		pp[p[i]-'a']++;
	}
	for(int i=0;i<t.length();i++){
		tt[t[i]-'a']++;
	}

	if(!checkSubsequence(s,t,s.length(),t.length())){
		cout<<"NO"<<endl;
		return ;
	}

	for(int i=0;i<26;i++){
		ss[i]=ss[i]+pp[i];
	}
	for(int i=0;i<26;i++){
		if(ss[i]<tt[i]){
			cout<<"NO"<<endl;
			return;
		}
	}
	cout<<"YES"<<endl;
	return ;
	



}

int main(){
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		solve();
	}


	return 0;
}
//http://codeforces.com/contest/1194/problem/C
