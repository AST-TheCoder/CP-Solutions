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
     set<pair<ll,ll>> s;
     for(ll i=0;i<n;i++){
      pair<ll,ll> a;
      cin>>a.first;
      a.second=i+1;
      if(a.first) s.insert(a);
     }
     vector<pair<ll,ll>> ans;
     for(;s.size()>=2;){
      pair<ll,ll> mn=*s.begin();
      set<pair<ll,ll>>::iterator it=s.end();
      it--;
      pair<ll,ll> mx=*it;
      s.erase(s.begin());
      s.erase(it);
      mn.first--;
      mx.first--;
      ans.pb({mn.second,mx.second});
      if(mn.first) s.insert(mn);
      if(mx.first) s.insert(mx);
     }
     cout<<ans.size()<<endl;
     for(ll i=0;i<ans.size();i++) cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
 
    return 0;
}