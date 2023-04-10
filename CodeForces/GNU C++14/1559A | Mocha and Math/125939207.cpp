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
        ll n;
        cin>>n;
        ll a[n+1];
        ll c[40];
        memset(c,0,sizeof(c));
        for(ll i=1;i<=n;i++){
            cin>>a[i];
            for(ll j=0;j<40;j++){
                if(a[i]%2) c[j]++;
                a[i]/=2;
            }
        }
        ll ans=0;
        for(ll j=0;j<40;j++){
            if(c[j]==n) ans+=pow(2,j);
        }
        cout<<ans<<endl;
    }
 
    return 0;
}