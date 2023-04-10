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
 
    read:
    while(t--){
        ll n;
        cin>>n;
 
        ll a[n];
        queue<ll> q[n+1];
        for(ll i=0;i<n;i++){
            cin>>a[i];
            q[a[i]].push(i);
        }
        vector<ll> ans;
        ll id=0;
 
        while(id<n){
            if(!q[0].size()){
                for(;id<n;id++) ans.pb(0);
                continue;
            }
            ll pos=q[0].front();
            for(ll i=1;i<=n;i++){
                if(q[i].size()) pos=max(pos,q[i].front());
                else{
                    ans.pb(i);
                    break;
                }
            }
            for(;id<=pos;id++){
                q[a[id]].pop();
            }
        }
        cout<<ans.size()<<endl;
        for(ll i=0;i<ans.size();i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
 
    return 0;
}