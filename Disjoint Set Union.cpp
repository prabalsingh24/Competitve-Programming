//https://codeforces.com/contest/1213/problem/G
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
int parent[200005];
int size[200005];

void make_set(int v){
	parent[v]=v;
	size[v]=1;
	return;
}
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
	if(v!=u){
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
	vector<pair<int,pair<int,int>>>edge;
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n-1;i++){
		int u,v,w;
		cin>>u>>v>>w;
		edge.push_back(make_pair(w,make_pair(u,v)));
	}
	for(int i=0;i<200005;i++){
		parent[i]=i;
		size[i]=1;
	}
	sort(edge.begin(),edge.end());
	int idx=0;
	int ans=0;
	vector<pair<int,int>> query;
	for(int i=0;i<q;i++){
		int t;
		cin>>t;
		query.push_back(make_pair(t,i));
	}
	vector<int> answer(q);
	
	sort(query.begin(),query.end());
	for(int i=0;i<q;i++){
		int t;
		t=query[i].first;
		int flag=0;
		while(flag==0 and idx<n-1){
			if(edge[idx].first>t){
				flag++;
			}
			else{
				int a=edge[idx].second.first;
				int b=edge[idx].second.second;
				int t1=find_set(a);
				int t2=find_set(b);
				int add=size[t1]*size[t2];
				merge_set(a,b);
				ans+=add;
				idx++;
			}
		}
		answer[query[i].second]=ans;
	}
	for(auto it:answer){
		cout<<it<<" ";
	}
	


	
	return 0;
}
