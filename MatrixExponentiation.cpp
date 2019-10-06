#include<bits/stdc++.h> 

using namespace std; 

const long long mod=1000000007;
vector< vector<long long> > matrix_multi(vector< vector<long long> > a, vector< vector<long long > > b, long long m){
  vector< vector<long long > > ans(m+1,vector<long long> (m+1));
  for(long long i=1;i<=m;i++){
    for(long long j=1;j<=m;j++){
      ans[i][j]=0;                                                      //fuction to multiply two matrix
    }
  }
  for(long long i =1;i<=m;i++){
    for(long long j=1;j<=m;j++){
      for(long long k=1;k<=m;k++){
        ans[i][j]=(ans[i][j]+ a[i][k]*b[k][j])%mod;
        
      }
    }
  }
  return ans;

}



vector< vector<long long> > matrix_pow(vector< vector<long long > > T, long long p, long long m){
                                                                               // function to find the power of matrix
  if(p==1) return T;
  if(p%2==1) return matrix_multi(matrix_pow(T,p-1,m),T,m);
  vector< vector<long long > > x=matrix_pow(T,p/2,m);
  if(p%2==0) return matrix_multi(x,x,m);
}

int main() {   
    long long n;
    long long m;
    cin>>n>>m;
    if(n<m){
      cout<<"1";
      return 0;
    }
    long long k=m;
    vector< long long> f1(m+1);
    for(long long i=1;i<m;i++){
      f1[i]=1;
    }
    f1[m]=2;
    vector< vector<long long > >T(m+1,vector<long long>(m+1));
    for(long long i=1;i<=m;i++){
      for(long long j=1;j<=m;j++){                              
        T[i][j]=0;
      }
    }
    for(long long i=1;i<m;i++){                             //Fn=(T^n-1)*f1
      T[i][i+1]=1;
    }
    T[m][1]=1;
    T[m][m]=1;
    
    long long p=n-1;
    T=matrix_pow(T,n-1,m);
    long long ans=0;
    for(long long i=1;i<=m;i++){
      ans=(ans+T[1][i]*f1[i])%mod;
    }
    cout<<ans;

    return 0; 
}