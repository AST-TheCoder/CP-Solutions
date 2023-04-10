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
    ll t,ii=0;
    cin>>t;
 
    read:
    while(t--){
        ll n;
        cin>>n;
 
        ll ans[n+1],a[n+1];
        for(ll i=1;i<=n;i++){
            cin>>a[i];
            ans[i]=i;
        }
 
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
 
        for(ll i=1;i<=n;i++){
            if(a[i]==ans[i]){
                if(i==n) swap(ans[i],ans[i-1]);
                else swap(ans[i],ans[i+1]);
            }
        }
 
        for(ll i=1;i<=n;i++) cout<<ans[i]<<" ";cout<<endl;
    }
 
    return 0;
}