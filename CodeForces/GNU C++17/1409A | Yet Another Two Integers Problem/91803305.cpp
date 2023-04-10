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
  ll a,b;
  cin>>a>>b;
 
  ll x=abs(a-b);
  cout<<x/10+(x%10!=0)<<endl;
 }
 
 return 0;
}