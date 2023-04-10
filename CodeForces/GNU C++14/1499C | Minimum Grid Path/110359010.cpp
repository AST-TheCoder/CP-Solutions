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
 
 int t;
 scanf("%lli",&t);
 
 while(t--){
  ll n;
  cin>>n;
  ll ans=0,a[n],c[n];
  memset(c,0,sizeof(c));
  for(ll i=0;i<n;i++){
   cin>>a[i];
  }
  ll x=0,y=1;
  c[x]=n,c[y]=n;
  ans=(a[x]*c[x])+(a[y]*c[y]);
  ll p=ans;
  for(ll i=2;i<n;i++){
   if(!(i%2)){
    if(a[i]<a[x]){
     c[i]=c[x]-1;
     p-=(c[i]*a[x]);
     p+=(c[i]*a[i]);
     c[x]=1;
     x=i;
    }
    else{
     c[x]--;
     c[i]=1;
     p-=a[x];
     p+=a[i];
    }
   }
   else{
    if(a[i]<a[y]){
     c[i]=c[y]-1;
     p-=(c[i]*a[y]);
     p+=(c[i]*a[i]);
     c[y]=1;
     y=i;
    }
    else{
     c[y]--;
     c[i]=1;
     p-=a[y];
     p+=a[i];
    }
   }
   ans=min(ans,p);
  }
  cout<<ans<<endl;
 }
 
 
 return 0;
}