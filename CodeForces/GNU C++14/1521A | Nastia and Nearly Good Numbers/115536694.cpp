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
  ll a,b;
  cin>>a>>b;
  if(b!=1){
   cout<<"YES"<<endl;
   if(b!=2) cout<<a<<" "<<a*(b-1)<<" "<<a*b<<endl;
   else cout<<a<<" "<<3*a<<" "<<2*a*b<<endl;
  }
  else cout<<"NO"<<endl;
 }
 
    return 0;
}