//https://codeforces.com/contest/348/problem/A
#include<iostream>
using namespace std;
int main(){
	long long n;
	cin>>n;
	long long a[n];
	long long sum=0;
	long long maxx=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
		maxx=max(a[i],maxx);
	}
	long long s=0;
	long long e=1000000000000;
	long long ans=e;
	int flag=0;
	while(s<=e and flag==0){
		long long mid=s+e;
		mid=mid/2;
		long long abc=n-1;
		abc=abc*mid;
												//Binary Search
		if(abc>=sum and mid>=maxx){
			ans=mid;
			e=mid-1;
		}
		else{
			s=mid+1;
		}

	}
	cout<<ans<<endl;
	return 0;
}