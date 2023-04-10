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
     for(ll i=0;i<n-1;i++){
      if(a[i]<=k){
       a[n-1]+=a[i];
       k-=a[i];
       a[i]=0;
      }
      else{
       a[i]-=k;
       a[n-1]+=k;
       k=0;
      }
     }
     for(ll i=0;i<n;i++) cout<<a[i]<<" ";
      cout<<endl;
    }
 
 return 0;
}