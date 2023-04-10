#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
 
string s;
 
ll solve(ll l,ll r,char x){
 
 if(l==r) return s[l]!=x;
 
 ll cnt1=0;
 for(ll i=l;i<=(l+r)/2;i++) if(s[i]!=x) cnt1++;
 ll u=solve((l+r)/2+1,r,x+1);
 
 ll cnt2=0;
 for(ll i=(l+r)/2+1;i<=r;i++) if(s[i]!=x) cnt2++;
 ll v=solve(l,(l+r)/2,x+1);
 
 return min(u+cnt1,v+cnt2);
}
 
int main()
{
 ll t;
 cin>>t;
 
 while(t--){
  ll n,x,y;
  cin>>n>>s;
 
  cout<<solve(0,n-1,'a')<<endl;
 }
 
 return 0;
}