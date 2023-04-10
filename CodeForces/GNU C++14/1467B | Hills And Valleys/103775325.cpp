#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define Max 10000000000000000
#define min_heap priority_queue <ll, vector<ll>, greater<ll> >
 
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
int main()
{ 
 
 ll t;
 cin>>t;
 
 while(t--){
  ll n,s=0;
  cin>>n;
  ll chk[n+1],a[n+1];
  for(ll i=1;i<=n;i++){
   cin>>a[i];
   chk[i]=0;
  }
  for(ll i=2;i<n;i++){
   if((a[i]>a[i-1] && a[i]>a[i+1]) || (a[i]<a[i-1] && a[i]<a[i+1])){
    chk[i]=1;
    s++;
   }
  }
 
  ll o=0;
  for(ll i=2;i<n;i++){
   ll x=chk[i-1],y=chk[i+1];
   if(chk[i]) x++,y++;
   if(i+1<n && ((a[i+1]>a[i-1] && a[i+2]<a[i+1]) || (a[i+1]<a[i-1] && a[i+2]>a[i+1]))){
    if(!chk[i+1]) x--;
   }
   else x+=chk[i+1];
   if(i-1>1 && ((a[i-1]>a[i+1] && a[i-2]<a[i-1]) || (a[i-1]<a[i+1] && a[i-2]>a[i-1]))){
    if(!chk[i-1]) y--;
   }
   else y+=chk[i-1];
   o=max(o,max(x,y));
  }
  
  cout<<s-o<<endl;
 }
 return 0;
}