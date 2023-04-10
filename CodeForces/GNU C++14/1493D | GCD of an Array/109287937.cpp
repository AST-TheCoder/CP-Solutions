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
 
bool c[200007];
multiset<ll> s[200007];
ll mod=1000000007;
 
int main()
{ 
 
 vector<ll> p;
 for(ll i=2;i<200007;i++){
  if(!c[i]){
   p.pb(i);
   for(ll j=i;j<200007;j+=i) c[j]=1;
  }
 }
 
 ll n,q,ans=1;
 cin>>n>>q;
 
 set<pair<ll,ll>> v[n];
 
 for(ll i=0;i<n;i++){
  v[i].insert({1,0});
  ll x;
  cin>>x;
  for(ll j=0;p[j]*p[j]<=x;j++){
   if(!(x%p[j])){
    ll k=0;
    while(!(x%p[j])){
     k++;
     x/=p[j];
    }
    v[i].insert({p[j],k});
    s[p[j]].insert(k);
    if(s[p[j]].size()==n){
     ll f=*s[p[j]].begin();
     ans*=pow(p[j],f);
    }
   }
  }
  if(x!=1){
   v[i].insert({x,1});
   s[x].insert({1});
   if(s[x].size()==n){
    ll f=*s[x].begin();
    ans*=pow(x,f);
   }
  }
 }
 while(q--){
  ll id,x;
  cin>>id>>x;
  id--;
  for(ll j=0;p[j]*p[j]<=x;j++){
   if(!(x%p[j])){
    ll k=0;
    while(!(x%p[j])){
     k++;
     x/=p[j];
    }
    set<pair<ll,ll>>::iterator it=v[id].upper_bound({p[j],0});
    pair<ll,ll> u=*it;
    //if(it!=v[id].end()) cout<<u.first<<" "<<u.second<<endl;
    if(it!=v[id].end() && u.first==p[j]){
     v[id].erase(it);
     v[id].insert({p[j],(u.second)+k});
     ll ck;
     if(s[p[j]].size()==n) ck=*s[p[j]].begin();
     s[p[j]].erase(s[u.first].find(u.second));
     s[p[j]].insert((u.second)+k);
     if(s[p[j]].size()==n){
      ck=(*s[p[j]].begin())-ck;
      ans*=pow(p[j],ck);
      ans%=mod;
     }
    }
    else{
     v[id].insert({p[j],k});
     s[p[j]].insert(k);
     if(s[p[j]].size()==n){
      ll f=*s[p[j]].begin();
      ans*=pow(p[j],f);
      ans%=mod;
     }
    }
   }
  }
  if(x!=1){
   set<pair<ll,ll>>::iterator it=v[id].upper_bound({x,0});
   pair<ll,ll> u=*it;
   //if(it!=v[id].end()) cout<<u.first<<" "<<u.second<<endl;
   if(it!=v[id].end() && u.first==x){
    v[id].erase(it);
    v[id].insert({x,(u.second)+1});
    ll ck;
    if(s[x].size()==n) ck=*s[x].begin();
    s[x].erase(s[u.first].find(u.second));
    s[x].insert((u.second)+1);
    if(s[x].size()==n){
     ck=(*s[x].begin())-ck;
     ans*=pow(x,ck);
     ans%=mod;
    }
   }
   else{
    v[id].insert({x,1});
    s[x].insert(1);
    if(s[x].size()==n){
     ll f=*s[x].begin();
     ans*=pow(x,f);
     ans%=mod;
    }
   }
  }
 
  cout<<ans<<endl;
 }
 
 return 0;
}