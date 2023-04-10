#include<bits/stdc++.h>
using namespace std;
 
int main()
{
 int t;
 cin>>t;
 while(t--){
  int n,m;
  cin>>n>>m;
 
  long long int a[n+1][m+1],dp[n+1][m+1],ans=-1;
 
  for(int i=1;i<=n;i++){
   for(int j=1;j<=m;j++){
    cin>>a[i][j];
   }
  }
 
  for(int p=1;p<=n;p++){
   for(int q=1;q<=m;q++){
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++){
     for(int j=1;j<=m;j++){
      if(i<p && j>q) continue;
      if(i>p && j<q) continue;
  
      if(a[i][j]>=a[p][q]-p+i-q+j){
       dp[i][j]=a[i][j]-a[p][q]+p-i+q-j;
      }
     }
    }
 
    for(int i=1;i<=n;i++){
     for(int j=1;j<=m;j++){
      if(dp[i][j]==-1) continue;
      if(i==1 && j==1) continue;
 
      long long int x=dp[i-1][j],y=dp[i][j-1];
      if(x==-1 && y==-1){
       dp[i][j]=-1;
       continue;
      }
      else if(x==-1) dp[i][j]+=y;
      else if(y==-1) dp[i][j]+=x;
      else dp[i][j]+=min(x,y);
     }
    }
 
    if(dp[n][m]!=-1){
     if(ans==-1) ans=dp[n][m];
     else ans=min(dp[n][m],ans);
    }
   }
  }
 
  cout<<ans<<endl;
 }
}