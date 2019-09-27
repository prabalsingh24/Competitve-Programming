//https://codeforces.com/contest/1187/problem/D
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
int a[300005];
int b[300005];
vector<int> pos[300005];
int n;
int tree[4*300005];
const int inf=1e9;
void build(int idx,int l,int r){
	
	if(l>r){
		return;
	}
	if(l==r){
		tree[idx]=a[l];
	}
	else{
		int mid=l+r;
		mid=mid/2;
		build(2*idx,l,mid);
		build(2*idx+1,mid+1,r);
		tree[idx]=min(tree[2*idx],tree[2*idx+1]);
	}
}
void update(int idx,int l, int r, int pos,int val){
	if(l>r){
		return;
	}
	if(l==r){
		tree[idx]=val;
		return ;
	}
	int mid=(l+r)/2;
	if(pos<=mid){
		update(2*idx,l,mid,pos,val);
		
	}
	else{
		update(2*idx+1,mid+1,r,pos,val);
	}
	tree[idx]=min(tree[2*idx],tree[2*idx+1]);
}
int query(int idx,int l,int r,int ql,int qr){

	if(l>qr or r<ql){
		return inf;
	}
	if(l==ql and r==qr){
		return tree[idx];
	}
	else{
		int mid=l+r;
		mid=mid/2;
		int first=query(2*idx,l,mid,ql,min(mid,qr));
		int second=query(2*idx+1,mid+1,r,max(ql,mid+1),qr);
		return min(first,second);
	}
}
void solve(){
	IOS;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		pos[i].clear();
	}
	for(int i=1;i<=n;i++){
		int temp;
		scanf("%lld",&temp);
		a[i]=temp;

		pos[a[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		int temp;
		scanf("%lld",&temp);
		b[i]=temp;
	}
	for(int i=1;i<=n;i++){
		reverse(pos[i].begin(),pos[i].end());
	}
	for(int i=0;i<=4*n;i++){
		tree[i]=inf;
	}
	build(1,1,n);
	
	for(int i=1;i<=n;i++){
		int number=b[i];
		if(pos[number].size()==0){
			printf("NO\n");	
			return ;
		}
		int idx=pos[number].back();
		
		int tt=query(1,1,n,1,idx);
		if(tt<number){
			printf("No\n");
			return;
		}
		else{
			pos[number].pop_back();
			update(1,1,n,idx,inf);
		}
	}
	printf("YES\n");



}
int32_t main(){
	
	int t;
	scanf("%lld",&t);
	for(int i=0;i<t;i++){
		solve();
	}	
	

	
	
	return 0;
}