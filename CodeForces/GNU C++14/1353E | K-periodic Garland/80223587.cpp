#include<bits/stdc++.h>
using namespace std;
 
char s[1000001];
int n,k,dp[1000001][2][2];
 
int solve(int idx,int state,int ok)
{
 if(idx+k>n) return 0;
 
 if(dp[idx][state][ok]!=-1) return dp[idx][state][ok];
 
 int x=INT_MAX,y=INT_MAX;
 if(ok){
  x=solve(idx+k,1,1);
  if(s[idx+k-1]!='1') x++;
 }
 if(state || !ok) y=solve(idx+k,0,0);
 else y=solve(idx+k,0,1);
 if(s[idx+k-1]!='0') y++;
 
 return dp[idx][state][ok]=min(x,y);
 
}
 
int main()
{
 int t;
 scanf("%d",&t);
 while(t--){
  scanf("%d %d %s",&n,&k,s);
 
  for(int i=1;i<=n;i++){
   dp[i][1][1]=-1;
   dp[i][1][0]=-1;
   dp[i][0][1]=-1;
   dp[i][0][0]=-1;
  }
 
  int x[n+1],ans=INT_MAX,l=0;
  for(int i=n;i>=1;i--){
   if(i<=n-k) x[i]=x[i+k];
   else x[i]=0;
 
   if(s[i-1]=='1') x[i]++,l++;
  }
 
  for(int i=1;i<=k;i++){
   int p=solve(i,1,1);
   if(s[i-1]!='1') p++;
 
   int q=solve(i,0,1);
   if(s[i-1]!='0') q++;
 
   ans=min(ans,min(p,q)+l-x[i]);
  }
 
  printf("%d\n",ans);
 }
}