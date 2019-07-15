//http://codeforces.com/contest/780/problem/E
#include<iostream>
#include<vector>
#include<list>
#include<map>

using namespace std;

const int NN=2e5+5;

vector<int> ajdList[NN];
vector<int> euler;
int visited[NN];
void eulerPath(int&index,int node){
	euler.push_back(node+1);
	visited[node]=1;
	for(auto neighbour:ajdList[node]){
		if(!visited[neighbour]){
			eulerPath(index,neighbour);
			euler.push_back(node+1);
		}
	}

}



int main(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		x=x-1;
		y=y-1;
		ajdList[x].push_back(y);
		ajdList[y].push_back(x);
	}
	for(int i=0;i<n;i++){
		visited[i]=0;
	}
	int ind=0;
	int node=0;
	eulerPath(ind,node);
	
	
	int mm=(2*n+k-1)/k;
	int index=0;
	int x=euler.size();
	for(int i=0;i<k;i++){
		if(index!=x){
			int temp=min(mm,x-index);
			printf("%d ",temp);
			for(int j=0;j<temp;j++){
				printf("%d ",euler[index++]);
			
			}
			printf("\n");
		}
		else{
			cout<<"1 1"<<endl;
		}
	}




	return 0;
}