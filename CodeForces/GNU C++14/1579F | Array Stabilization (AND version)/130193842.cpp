#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define Max 100000000000000
#define min_heap priority_queue <ll, vector<ll>, greater<ll> >
 
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
 
int main()
{
 
    ll t;
    scanf("%lli",&t);
 
    while(t--){
     ll n,d;
     cin>>n>>d;
     ll a[n+1];
     ll ans[n+1],mx=0;
     for(ll i=1;i<=n;i++){
      cin>>a[i];
      if(a[i]) ans[i]=Max;
      else ans[i]=0;
     }
     for(ll i=1;i<=n;i++){
      if(!a[i]){
       ll temp=0;
       for(ll id=i+d;;id+=d){
        temp++;
        if(id>n) id-=n;
        if(!a[id] || id==i || ans[id]<=temp) break;
        ans[id]=min(ans[id],temp);
       }
      }
     }
     for(ll i=1;i<=n;i++){
      if(a[i]==1 && ans[i]==Max){
       mx=-1;
       break;
      }
      mx=max(ans[i],mx);
     }
     cout<<mx<<endl;
    }
 
    return 0;
}