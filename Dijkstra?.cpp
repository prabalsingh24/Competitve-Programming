//https://codeforces.com/contest/20/problem/C
//https://codeforces.com/problemset/problem/449/B
#include<iostream>
#include<set>
#include<vector>
using namespace std;
vector<pair<long long,long long> > ajdList[100005];
set<pair<long long,long long>> s;
long long d[100005];
long long inf=1000000000000;
int p[100005];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		d[i]=inf;
		p[i]=-1;
	}
	for(int i=0;i<m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		ajdList[u].push_back(make_pair(v,w));
		ajdList[v].push_back(make_pair(u,w));
	}
	d[1]=0;
	s.insert(make_pair(0,1));
	while(!s.empty()){
		//cout<<"here  ";			
		auto t=*(s.begin());
		int currNode=t.second;						// Dijkstra's algorithm
		//cout<<currNode<<endl;
		for(auto j:ajdList[currNode]){
			long long nextNode=j.first;
			if(d[nextNode]>d[currNode]+j.second and nextNode!=currNode){
				if(s.find(make_pair(d[nextNode],nextNode))!=s.end()){
					s.erase(s.find(make_pair(d[nextNode],nextNode)));
				}
				d[nextNode]=d[currNode]+j.second;
				s.insert(make_pair(d[nextNode],nextNode));
				p[nextNode]=currNode;
			}
		}
		s.erase(s.begin());
	}
	vector<int> ans;
	if(d[n]!=inf){
		int currNode=n;
		while(currNode!=1){
			ans.push_back(currNode);
			currNode=p[currNode];
		}
	}
	else{
		cout<<"-1"<<endl;
		return 0;
	}
	cout<<1<<" ";
	for(int i=ans.size()-1;i>=0;i--){
		cout<<ans[i]<<" ";
	}






	return 0;
}
