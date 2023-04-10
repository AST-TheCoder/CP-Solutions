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
 
 ll n;
 cin>>n;
 
 if(n==1){
  cout<<"! "<<1<<endl;
  return 0;
 }
 
 ll l=1,r=n;
 
 while(l<r){
  ll mi=(l+r)/2,mj=mi+1;
  ll a,b;
  cout<<"? "<<mi<<endl;
  cin>>a;
  cout<<"? "<<mj<<endl;
  cin>>b;
  if(a>b) l=mj;
  else r=mi;
 }
 
 cout<<"! "<<l<<endl;
 
 return 0;
}