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
 
    ll x=1;
    ll c[10];
    for(ll i=0;i<10;i++){
        c[i]=x;
        x*=10;
    }
 
    while(t--){
        ll n,k;
 
        cin>>n>>k;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
            a[i]=c[a[i]];
        }
        ll ans=0;
        for(ll i=0;i<n-1;i++){
            ll cnt=a[i+1]/a[i]-1;
            if(cnt<=k){
                k-=cnt;
                ans+=a[i]*cnt;
            }
            else{
                ans+=(a[i]*(k+1));
                k=-1;
                break;
            }
        }
        ans+=(a[n-1]*(k+1));
        cout<<ans<<endl;
 
    }
 
    return 0;
}