#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
 
int main()
{
 
 ll t;
 cin>>t;
 
 read:
 while(t--){
  ll n,ans=0;
  cin>>n;
  ll a[n+1];
  for(ll i=1;i<=n;i++) cin>>a[i];
  sort(a+1,a+n+1);
 
  for(ll sum=1;sum<=100;sum++){
   ll cnt=0;
   for(ll i=1,j=n;i<j;){
    if(a[i]+a[j]>sum) j--;
    else if(a[i]+a[j]<sum) i++;
    else{
     cnt++;
     i++,j--;
    }
   }
   ans=max(ans,cnt);
  }
 
  cout<<ans<<endl;
 }
 
 return 0;
}