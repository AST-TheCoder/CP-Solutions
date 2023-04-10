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
    cin>>t;
 
    while(t--){
     ll n;
     cin>>n;
     pair<ll,ll> a[n+1];
     for(ll i=1;i<=n;i++){
      cin>>a[i].first;
      a[i].second=i;
     }
     sort(a+1,a+n+1);
     vector<pair<pair<ll,ll>,ll>> ans;
     for(ll i=1;i<=n;i++){
      if(a[i].second!=i){
       ll d=a[i].second-i;
       for(ll j=i;j<=n;j++){
        a[j].second-=d;
        if(a[j].second<i) a[j].second+=(n-i+1);
       }
       ans.pb({{i,n},d});
      }
     }
     cout<<ans.size()<<endl;
     for(ll i=0;i<ans.size();i++) cout<<ans[i].first.first<<" "<<ans[i].first.second<<" "<<ans[i].second<<endl;
    }
 
    return 0;
}