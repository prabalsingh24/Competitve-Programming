//http://codeforces.com/contest/1187/problem/C
//creating another sequence b[n] such that b[i]=a[i+1]-a[i];
//if a[i] is non decreasing, then b[i]>=0;
#include<iostream>
#include<vector>
using namespace std;


int main(){
	int n,m;
	cin>>n>>m;
	vector<int> ll,rr;
	int b[n];
	for(int i=0;i<n;i++){
		b[i]=-1;
	}
	int temp=0;
	int l,r;		
	for(int i=0;i<m;i++){
		cin>>temp>>l>>r;
		l--;
		r--;
		if(temp==1){
			for(int i=l;i<r;i++){
				b[i]=0;
			}
		}
		else{
			ll.push_back(l);
			rr.push_back(r);
		}
	}
	int a[n];
	a[0]=n;
	for(int i=1;i<n;i++){
		a[i]=a[i-1]+b[i-1];
	}
	int flag=0;

	for(int i=0;i<ll.size();i++){
		int aa=ll[i],bb=rr[i];
		for(int j=aa;j<bb;j++){
			if(a[j]>a[j+1]){
				flag++;
				
			}
		}
		if(flag==0){
			cout<<"NO"<<endl;
			return 0;
		}
		flag=0;
	}
	cout<<"YES"<<endl;
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}


	return 0;
}