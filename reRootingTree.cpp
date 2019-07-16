//http://codeforces.com/contest/1187/problem/E
#include<iostream>
#include<vector>
#define N 2*100001

using namespace std;

vector<int> adjList[N];
long long subtreeSize[N];
long long dp[N];
long long ans;

void calSize(int node,int parent){
	subtreeSize[node]=1;
	for(auto child: adjList[node]){
		if(child!=parent){
			calSize(child,node);
			subtreeSize[node]+=subtreeSize[child];
		}
	}
}

void calDp(int node,int parent){
	dp[node]=subtreeSize[node];
	for(auto child: adjList[node]){
		if(child!=parent){
			calDp(child,node);
			dp[node]+=dp[child];
		}
	}
}

void dfs(int node,int parent){
	ans=max(ans,dp[node]);
	for(auto child: adjList[node]){
		if(child!=parent){
			dp[node]-=dp[child];
			dp[node]-=subtreeSize[child];
			subtreeSize[node]-=subtreeSize[child];
			dp[child]+=dp[node];
			dp[child]+=subtreeSize[node];
			subtreeSize[child]+=subtreeSize[node];
			dfs(child,node);
			subtreeSize[child]-=subtreeSize[node];
			dp[child]-=subtreeSize[node];
			dp[child]-=dp[node];
			subtreeSize[node]+=subtreeSize[child];
			dp[node]+=dp[child];
			dp[node]+=subtreeSize[child];

		}
	}
}



int main(){
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		adjList[x].push_back(y);
		adjList[y].push_back(x);
	}
	ans=0;
	calSize(1,0);
	calDp(1,0);
	dfs(1,0);
	cout<<ans<<endl;



	return 0;
}