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
  ll n,k;
  cin>>n>>k;
  ll a[n];
  for(ll i=0;i<n;i++) cin>>a[i];
  ll sum=a[0],s=a[0];
  for(ll i=1;i<n;i++){
   sum+=a[i];
   if(a[i]*100LL>k*s) s=(a[i]*100LL)/k+((a[i]*100)%k!=0);
   s+=a[i];
   //cout<<sum<<" "<<s<<endl;
  }
  cout<<s-sum<<endl;
 }
 
 return 0;
}