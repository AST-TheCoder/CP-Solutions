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
 
 read:
 while(t--){
  ll n,m;
  cin>>n>>m;
  pair<ll,ll> p[m+1];
  for(ll i=1;i<=m;i++){
   ll x,y;
   cin>>x>>y;
   p[i]={y,x};
  }
  sort(p+1,p+m+1);
  ll ok=0;
  for(ll i=1;i<=m;i++){
   if(!ok && i<m && p[i].first==p[i+1].first){
    i++;
    continue;
   }
   if(ok && i<m && p[i].first==p[i+1].first){
    cout<<"NO"<<endl;
    goto read;
   }
   if(!ok){
    ok=1;
    continue;
   }
   if((p[i].second!=p[i-1].second && !((p[i].first-p[i-1].first)%2)) || 
    p[i].second==p[i-1].second && (p[i].first-p[i-1].first)%2){
    ok=0;
    continue;
   }
   cout<<"NO"<<endl;
   goto read;
  }
  if(!ok) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
 }
 
 return 0;
}