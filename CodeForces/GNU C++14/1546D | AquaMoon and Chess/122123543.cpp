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
 
ll mod=998244353;
 
ll modinverse(ll n,ll p){
    if(p==0) return 1;
    if(p%2) return (n*modinverse(n,p-1))%mod;
    ll x=modinverse(n,p/2);
    return (x*x)%mod;
}
 
int main()
{
    ll fact[100007];
    fact[0]=1;
    for(ll i=1;i<100007;i++){
        fact[i]=fact[i-1]*i;
        fact[i]%=mod;
    }
    ll t;
    cin>>t;
 
    read:
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll x=0,y=0;
        for(ll i=0;i<s.size();i++){
            if(i+1<s.size() && s[i]=='1' && s[i+1]=='1') x++,i++;
            else if(s[i]=='1') y++;
        }
        n-=(x+y);
        ll ans=(fact[n]*modinverse(fact[n-x],mod-2))%mod;
        ans=(ans*modinverse(fact[x],mod-2))%mod;
        cout<<ans<<endl;
    }
 
    return 0;
}