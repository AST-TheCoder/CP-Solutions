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
 scanf("%lli",&t);
 
 read:
 while(t--){
  ll n,l,r;
  cin>>n>>l>>r;
 
  ll ans=abs(l-r)/2;
  ll a[n+1],c[n];
  vector<ll> p,q;
  memset(a,0,sizeof(a));
  for(ll i=0;i<n;i++) cin>>c[i];
  if(l>=r){
   ll cnt=0;
   for(ll i=0;i<l;i++) a[c[i]]++;
   for(ll i=l;i<n;i++) a[c[i]]--;
   for(ll i=0;i<l;i++){
    if(a[c[i]]>=2 && cnt<ans){
     q.pb(c[i]);
     a[c[i]]-=2;
     cnt++;
    }
    else p.pb(c[i]);
   }
   for(ll i=l;i<n;i++) q.pb(c[i]);
  }
  else{
   ll cnt=0;
   for(ll i=l;i<n;i++) a[c[i]]++;
   for(ll i=0;i<l;i++) a[c[i]]--;
   for(ll i=l;i<n;i++){
    if(a[c[i]]>=2 && cnt<ans){
     p.pb(c[i]);
     a[c[i]]-=2;
     cnt++;
    }
    else q.pb(c[i]);
   }
   for(ll i=0;i<l;i++) p.pb(c[i]);
  }
  //cout<<p.size()<<" "<<q.size()<<endl;
  ll cnt=0;
  memset(a,0,sizeof(a));
  for(ll i=0;i<p.size();i++){
   a[p[i]]++;
  }
  for(ll i=0;i<q.size();i++){
   if(a[q[i]]){
    cnt++;
    a[q[i]]--;
   }
  }
  ans+=(n/2-cnt);
  cout<<ans<<endl;
 }
 
    return 0;
}