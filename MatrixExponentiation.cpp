#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
int parent[500005];
int size[500005];
 
int find_set(int v){
	if(parent[v]==v){
		return v;
	}
	else{
		parent[v]=find_set(parent[v]);
		return parent[v];
	}
}
void merge_set(int u,int v){
	u=find_set(u);
	v=find_set(v);
	if(u!=v){
		if(size[u]<size[v]){
			parent[u]=v;
			size[v]+=size[u];
		}
		else{
			parent[v]=u;
			size[u]+=size[v];
		}
	}
	
}
int32_t main(){
	IOS;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		parent[i]=i;
		size[i]=1;
	}
	for(int i=0;i<m;i++){
		int k;
		cin>>k;
		if(k>0){
			int first;
			cin>>first;
			for(int i=1;i<k;i++){
				int second;
				cin>>second;
				merge_set(first,second);
			}
		}
	}
	for(int i=1;i<=n;i++){
		int q=find_set(i);
		cout<<size[q]<<" ";
	}
	
 
	
	return 0;
}