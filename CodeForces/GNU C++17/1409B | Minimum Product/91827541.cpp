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
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
int main()
{
 ll t;
 cin>>t;
 
 while(t--){
  ll a,b,x,y,n;
  cin>>a>>b>>x>>y>>n;
 
  ll d1=a-x,d2=b-y,p,q;
 
 
  if(d1>n){
   p=(x+d1-n)*b;
  }
  else{
   p=x*(y+d2-min(d2,n-d1));
  }
 
  if(d2>n){
   q=a*(y+d2-n);
  }
  else{
   q=(x+d1-min(d1,n-d2))*y;
  }
 
  cout<<min(p,q)<<endl;
 }
 
 return 0;
}