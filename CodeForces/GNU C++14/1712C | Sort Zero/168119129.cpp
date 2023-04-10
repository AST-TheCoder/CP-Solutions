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
 
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;
 
int main()
{   
    
    ll t;
    cin>>t;
 
    while(t--){
        ll n,ans=0;
        cin>>n;
        vector<ll> a,cnt[n+1];
        for(ll i=0;i<n;i++){
            ll x;
            cin>>x;
 
            if(a.size() && a[a.size()-1]==x) continue;
            cnt[x].pb(a.size());
            a.pb(x);
        }
 
        for(ll i=1;i<=n;i++){
            if(cnt[i].size()>1){
                ans++;
                for(ll j=0;j<cnt[i].size();j++){
                    ll id=cnt[i][j];
                    a[id]=0;
                }
            }
        }
 
        for(ll i=a.size()-1,v=Max;i>=0;i--){
            if(a[i]>v){
                ans++;
                a[i]=0;
            }
            v=min(v,a[i]);
        }
 
        cout<<ans<<endl;
    }
 
    return 0;
}