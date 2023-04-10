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
 
ll v[5000],d[5000];
 
int main()
{   
    ll t;
    cin>>t;
 
    read:
    while(t--){
        ll n;
        cin>>n;
 
        ll a[n];
        for(ll i=0;i<n;i++) cin>>a[i];
 
        for(ll i=0;i<n;i++){
            ll c=0;
            for(ll j=n-1;j>i;j--){
                v[j]+=c;
                if(a[j]<a[i]) c++;
            }
            d[i]=c;
        }
 
        ll ans=0;
        for(ll i=0;i<n;i++){
            ll c=d[i];
            for(ll j=i+1;j<n;j++){
                if(a[j]<a[i]) c--;
                v[j]-=c;
                if(a[j]>a[i]) ans+=v[j];
            }
        }
        for(ll i=0;i<n;i++){
            v[i]=d[i]=0;
        }
        cout<<ans<<endl;
    }
 
    return 0;
}