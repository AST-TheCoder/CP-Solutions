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
  ll u,v;
  cin>>u>>v;
  if(u>v){
   cout<<"NO"<<endl;
   continue;
  }
  ll ok=0,p=1;
  queue<ll> q;
 
  ll x=u,k=0;
  while(x){
   if(!(x%2)) q.push(k);
   k++;
   x/=2;
  }
  while(k<64){
   q.push(k);
   k++;
  }
 
  for(ll j=0;j<=30;j++){
   if((u&(1<<j))<(v&(1<<j))){
    ok=1;
    break;
   }
   //cout<<j<<" "<<u<<" "<<(u&(1<<j))<<" "<<(v&(1<<j))<<endl;
   if((u&(1<<j))!=(v&(1<<j))){
    u-=p;
    k=0;
    while(k<=j){
     k=q.front();
     q.pop();
    }
    u|=(1<<k);
   }
   p*=2;
  }
  if(!ok) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
 }
 
 return 0;
}