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
 
    read:
    while(t--){
        ll n;
        cin>>n;
 
        ll par[n+1],root;
        for(ll i=1;i<=n;i++){
            ll x;
            cin>>x;
            if(i==x) root=i;
            else par[i]=x;
        }
        ll ans[n+1],d[n+1];
        memset(ans,-1,sizeof(ans));
        ll a[n+1];
        for(ll i=1;i<=n;i++) cin>>a[i];
        if(a[1]!=root){
            cout<<-1<<endl;
            goto read;
        }
        ans[root]=0;
        d[root]=0;
        ll dis=0;
        for(ll i=2;i<=n;i++){
            if(ans[par[a[i]]]==-1){
                cout<<-1<<endl;
                goto read;
            }
            dis++;
            ans[a[i]]=dis-d[par[a[i]]];
            d[a[i]]=dis;
        }
        for(ll i=1;i<=n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
 
    return 0;
}