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
  ll p,a,b,c;
  cin>>p>>a>>b>>c;
 
  ll x=p%a;
  if(x) a=a-x;
  else a=0;
 
  x=p%b;
  if(x) b=b-x;
  else b=0;
 
  x=p%c;
  if(x) c=c-x;
  else c=0;
  cout<<min(a,min(b,c))<<endl; 
 }
 
 return 0;
}