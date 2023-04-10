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
     ll n;
     scanf("%lli",&n);
     ll a[n];
     pair<ll,ll> p[n];
     for(ll i=0;i<n;i++){
      scanf("%lli",&p[i].first);
      p[i].second=i;
     }
     sort(p,p+n);
     ll x=0,v=p[0].first;
     for(ll i=0;i<n;i++){
      if(v!=p[i].first){
       x++;
       v=p[i].first;
      }
      a[p[i].second]=x;
     }
     ll ans=0;
     ordered_set<ll> s;
     ll cnt[n];
     memset(cnt,0,sizeof(cnt));
     for(ll i=0;i<n;i++){
      cnt[a[i]]++;
      s.insert(a[i]);
      ll id=s.order_of_key(a[i]);
      ll l=id,r=s.size()-id-cnt[a[i]];
      ans+=min(l,r);
     }
     
     printf("%lli\n",ans);
    }
 
    return 0;
}