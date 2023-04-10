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
 
 pair<pair<ll,ll>,ll> x[n+1];
 for(ll i=1;i<=n;i++){
  cin>>x[i].first.first>>x[i].first.second;
  x[i].second=i;
 }
 
 for(ll i=3;i<=n;i++){
  ll j=i-1;
  for(;j>1;j--){
   ll d1=(x[j-1].first.first-x[j].first.first)*(x[j-1].first.first-x[j].first.first)+(x[j-1].first.second-x[j].first.second)*(x[j-1].first.second-x[j].first.second);
   ll d2=(x[j+1].first.first-x[j].first.first)*(x[j+1].first.first-x[j].first.first)+(x[j+1].first.second-x[j].first.second)*(x[j+1].first.second-x[j].first.second);
   ll d3=(x[j-1].first.first-x[j+1].first.first)*(x[j-1].first.first-x[j+1].first.first)+(x[j-1].first.second-x[j+1].first.second)*(x[j-1].first.second-x[j+1].first.second);
   //cout<<d1<<" "<<d2<<" "<<(unsigned long long int)d1+d2<<" "<<d3<<endl;
   if((unsigned long long int)d1+d2>d3) break;
   swap(x[j],x[j+1]);
  }
 }
 
 for(ll i=1;i<=n;i++){
  cout<<x[i].second<<" ";
 }cout<<endl;
 
 return 0;
}