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
 
  ll d1=a-x,d2=b-y;
 
  ll p=(x+max(d1-n,0LL))*(b-min(d2,max(n-d1,0LL)));
  ll q=(a-min(d1,max(n-d2,0LL)))*(y+max(d2-n,0LL));
 
  cout<<min(p,q)<<endl;
 }
 
 return 0;
}