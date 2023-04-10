#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define all(x) x.begin(),x.end()
#define Max 10000000000000000
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;
 
int main()
{   
 
 ll n,x;
 cin>>n>>x;
 
 ll c[x+1];
 memset(c,0,sizeof(c));
 for(ll i=1;i<=n;i++){
  ll temp;
  cin>>temp;
  c[temp]++;
 }
 
 for(ll i=1;i<x;i++){
  if(c[i]%(i+1)){
   cout<<"No"<<endl;
   return 0;
  }
  c[i+1]+=c[i]/(i+1);
 }
 cout<<"Yes"<<endl;
 
 return 0;
}