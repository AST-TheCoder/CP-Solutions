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
        ll a[n+1],b[n+1],c[n+1];
        for(ll i=1;i<=n;i++){
            cin>>a[i];
            c[i]=0;
        }
        for(ll i=1;i<=n;i++){
            ll x;
            cin>>x;
            b[a[i]]=x;
        }
        ll ans=1;
        for(ll i=1;i<=n;i++){
            if(!c[i]){
                ans*=2;
                ans%=1000000007;
                c[i]=1;
                ll j=b[i];
                while(i!=j){
                    c[j]=1;
                    j=b[j];
                }
            }
        }
        cout<<ans<<endl;
    }
 
    return 0;
}