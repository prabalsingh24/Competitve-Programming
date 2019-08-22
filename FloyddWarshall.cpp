//https://codeforces.com/contest/1204/problem/C
//FLYOD WARSHALL. distance[i][j] is distance between node i and j;
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
	int n;
	cin>>n;
	int graph[n][n];
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		for(int j=0;j<n;j++){
			graph[i][j]=s[j]-'0';
		}
	}
	int m;
	cin>>m;
	int a[m];
	//cout<<"abc"<<endl;
	for(int i=0;i<m;i++){
		int temp;
		cin>>temp;
		temp--;
		a[i]=temp;
	}
	int distance[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			distance[i][j]=1000000;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(graph[i][j]==1){
				distance[i][j]=1;
			}
			if(i==j){
				distance[i][j]=0;
			}
		}
	}
	//cout<<"HERE"<<endl;
	for(int k=0;k<n;k++){																		//FLOYDD WARSHALL
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				distance[i][j]=min(distance[i][j],distance[i][k]+distance[k][j]);
			}
		}
	}
	
	vector<int> ans;
	ans.push_back(a[0]);
	int cur=a[0];
	int end=a[m-1];
	
	for(int i=1;i<m-1;i++){
		cur=a[i];
		int start=ans.back();
//		cout<<cur<<endl;
		//cout<<cur<<endl;
		int flag=0;
		int j=i+1;
		int nn=a[j];
		int temp=distance[start][nn];
		int temp2=distance[start][cur]+distance[cur][nn];
		if(temp2!=temp){
			flag++;
		}
		
		if(flag!=0){
			ans.push_back(cur);
		}
	}
	ans.push_back(a[m-1]);
	cout<<ans.size()<<endl;
	for(int i:ans){
		cout<<i+1<<" ";
	}


	return 0;
}