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
 
 stack<ll> q;
 ll n;
 cin>>n;
 ll a[n+1],b[n+1];
 vector<ll> id;
 id.pb(-1);
 
 for(ll i=1,x=0,y=0;i<=2*n;i++){
  char ch;
  cin>>ch;
  if(ch=='+'){
   x++;
   q.push(x);
   id.pb(i);
  }
  else{
   id.pb(-1);
   ll p;
   cin>>p;
   y++;
   a[y]=p;
   if(q.empty()){
    cout<<"NO"<<endl;
    return 0;
   }
   b[q.top()]=p;
   q.pop();
  }
 }
 
 min_heap p;
 for(ll i=1,x=0,y=0;i<=2*n;i++){
  if(id[i]!=-1){
   x++;
   p.push(b[x]);
  }
  else{
   y++;
   if(p.top()!=a[y]){
    cout<<"NO"<<endl;
    return 0;
   }
   p.pop();
  }
 }
 
 cout<<"YES"<<endl;
 for(ll i=1;i<=n;i++){
  cout<<b[i]<<" ";
 }
 
 return 0;
}