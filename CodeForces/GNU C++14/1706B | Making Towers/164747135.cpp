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
 
ll n,k,l,m;
 
int main()
{   
    
    ll t;
    scanf("%lli",&t);
 
    read:
    while(t--){
        ll n;
        cin>>n;
 
        vector<ll> c[n+1];
        for(ll i=1;i<=n;i++){
            ll x;
            cin>>x;
 
            c[x].pb(i);
        }
 
        for(ll i=1;i<=n;i++){
            if(c[i].size()==0){
                cout<<0<<" ";
                continue;
            }
 
            ll ans=1,p=c[i][0]%2;
            for(ll j=1;j<c[i].size();j++){
                if(c[i][j]%2!=p){
                    ans++;
                    p=(p==0);
                }
            }
            cout<<ans<<" ";
        }cout<<endl;
    }
 
    return 0;
}