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
 scanf("%lli",&t);
 
 while(t--){
  ll n,k;
  scanf("%lli %lli",&n,&k);
 
  ll a[n];
  for(ll i=0;i<n;i++){
   scanf("%lli",&a[i]);
  }
  while(k){
   ll i;
   for(i=0;i<n-1;i++){
    if(a[i]<a[i+1]){
     a[i]++;
     break;
    }
   }
   if(i==n-1){
    printf("-1\n");
    break;
   }
   k--;
   if(k==0){
    printf("%lli\n",i+1);
    break;
   }
  }
 }
 
 return 0;
}