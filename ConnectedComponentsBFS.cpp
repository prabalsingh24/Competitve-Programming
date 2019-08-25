//https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050edb/0000000000170721
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void solve(int ttt){
	vector<int> graph[100005];
	int visited[100005];
	for(int i=0;i<=100005;i++){
		visited[i]=0;
	}
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v ;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	vector<int> ans;
	for(int i=1;i<=n;i++){
		if(visited[i]==0){
			int number=0;
			queue<int> q;
			q.push(i);
			visited[i]=1;
			number++;
			while(!q.empty()){
				int node=q.front();				
				for(int qq=0;qq<graph[node].size();qq++){
					int j=graph[node][qq];
					if(visited[j]==0 and j!=node){
						q.push(j);
						visited[j]=1;
						number++;
					}
				}
				q.pop();
			}
			ans.push_back(number);
		}
	}
	int remaining=0;
	int components=0;
	
	long long red=ans.size()-1;
	long long sugarcontent=red*2;
	long long black=0;
	for(int i=0;i<ans.size();i++){
		black=black+ans[i]-1;
	}
	sugarcontent+=black;

//	cout<<components<<endl;
	cout<<"Case #"<<ttt<<": "<<sugarcontent<<endl;

	return ;
}

int main(){
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		solve(i);
	}

	return 0;
}