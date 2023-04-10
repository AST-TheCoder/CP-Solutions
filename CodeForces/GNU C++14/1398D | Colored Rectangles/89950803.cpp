#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
 
ll r[207],g[207],b[207];
ll R,G,B,dp[201][201][201];
 
ll solve(ll i,ll j,ll k){
 //cout<<i<<" "<<j<<" "<<k<<endl;
 if(!(i|j) || !(j|k) || !(i|k)) return 0;
 if(dp[i][j][k]) return dp[i][j][k];
 ll x=0,y=0,z=0;
 if(i && j) x=(r[i]*g[j])+solve(i-1,j-1,k);
 if(j && k) y=(g[j]*b[k])+solve(i,j-1,k-1);
 if(i && k) z=(r[i]*b[k])+solve(i-1,j,k-1);
 return dp[i][j][k]=max(x,max(y,z));
}
 
int main()
{
 
 cin>>R>>G>>B;
 
 for(ll i=1;i<=R;i++) cin>>r[i];
 for(ll j=1;j<=G;j++) cin>>g[j];
 for(ll k=1;k<=B;k++) cin>>b[k];
 
 sort(r+1,r+R+1);
 sort(g+1,g+G+1);
 sort(b+1,b+B+1);
 
 cout<<solve(R,G,B)<<endl;
 
 return 0;
}