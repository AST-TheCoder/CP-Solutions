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
        ll taken=0,ans=0,i=2,mod=1000000007,lcm=1;
        while(taken<n){
            ll gcd=__gcd(lcm,i);
            lcm/=gcd;
            lcm*=i;
            ll x=(n-n/lcm-taken);
            ans+=(x*i)%mod;
            ans%=mod;
            taken+=x;
            i++;
        }
        cout<<ans<<endl;
    }
 
    return 0;
}