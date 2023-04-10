#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
int main()
{
 
 ll t;
 cin>>t;
 
 while(t--){
  ll n;
  cin>>n;
  string s;
  cin>>s;
 
  for(ll i=0;i<n;i++) cout<<s[n-1];cout<<endl;
 }
 
 return 0;
}