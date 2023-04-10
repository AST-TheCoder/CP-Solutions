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
#define min_heap priority_queue <pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> >
 
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
 
int main()
{   
 
    ll t;
    cin>>t;
 
    while(t--){
        ll n;
        cin>>n;
 
        ll a[n];
        for(ll i=0;i<n;i++) cin>>a[i];
        string s;
        cin>>s;
 
        vector<pair<ll,ll>> x,y;
        for(ll i=0;i<n;i++){
            if(s[i]=='1') x.pb({a[i],i});
            else y.pb({a[i],i});
        }
 
        sort(all(x),greater<pair<ll,ll>>());
        sort(all(y),greater<pair<ll,ll>>());
 
        ll ans[n],cnt=n;
        for(ll i=0;i<x.size();i++){
            ans[x[i].second]=cnt--;
        }
        for(ll i=0;i<y.size();i++){
            ans[y[i].second]=cnt--;
        }
        for(ll i=0;i<n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
 
    return 0;
}