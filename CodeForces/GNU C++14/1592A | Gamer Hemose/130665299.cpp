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
        ll n,h;
        cin>>n>>h;
        ll a[n];
        for(ll i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n,greater<ll>());
        ll s=a[0]+a[1];
        ll ans=(h/s)*2;
        h%=s;
        if(h>0){
            h-=a[0];
            ans++;
        }
        if(h>0){
            h-=a[1];
            ans++;
        }
        cout<<ans<<endl;
    }
 
    return 0;
}