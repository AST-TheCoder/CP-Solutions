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
    ll mod=1000000007;
 
    ll t,ii=0;
    cin>>t;
 
    read:
    while(t--){
        ll b,q,y,c,r,z,ans=0;
        cin>>b>>q>>y>>c>>r>>z;
        vector<ll> d;
        for(ll i=1;i*i<=r;i++){
            if(r%i==0){
                d.pb(i);
                if(i!=r/i) d.pb(r/i);
            }
        }
 
        ll u=b+q*(y-1);
        ll v=c+r*(z-1);
 
        if(b>c || u<v || r%q || (c-b)%q){
            cout<<0<<endl;
            continue;
        }
 
        ll c1=(c-b)/q;
        ll c2=(u-v)/q;
 
        for(ll i=0;i<d.size();i++){
            ll lcm=(q*d[i])/__gcd(q,d[i]);
            if(lcm!=r) continue;
            ll temp=lcm/q;
            if(temp>c1 || temp>c2){
                cout<<-1<<endl;
                goto read;
            }
            ll x=lcm/d[i];
            ans+=(x*x)%mod;
            ans%=mod;
        }
        cout<<ans<<endl;
    }
 
    return 0;
}