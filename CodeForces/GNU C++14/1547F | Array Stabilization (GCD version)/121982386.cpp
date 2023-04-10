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
 
ll a[400007],node[800007];
void build(ll n,ll i,ll j){
    if(i==j){
        node[n]=a[i];
        return;
    }
    ll lf=2*n,rt=2*n+1,md=(i+j)/2;
    build(lf,i,md);
    build(rt,md+1,j);
    node[n]=__gcd(node[lf],node[rt]);
    return;
}
 
ll query(ll n,ll i,ll j,ll l,ll r){
    if(l>j || r<i) return 0;
    if(i>=l && j<=r){
        return node[n];
    }
    ll lf=2*n,rt=2*n+1,md=(i+j)/2;
    ll x=query(lf,i,md,l,r);
    ll y=query(rt,md+1,j,l,r);
    return __gcd(x,y);
}
 
int main()
{
 
    ll t;
    cin>>t;
 
    read:
    while(t--){
        ll n,gcd=0;
        cin>>n;
 
        for(ll i=1;i<=n;i++){
            cin>>a[i];
            a[i+n]=a[i];
            gcd=__gcd(a[i],gcd);
        }
        for(ll i=1;i<=4*n;i++) node[i]=0;
        build(1,1,2*n);
        ll ans=0;
        for(ll i=1,j=1;i<=n;){
            if(query(1,1,2*n,i,j)!=gcd) j++;
            else{
                ans=max(ans,j-i);
                i++;
            }
            if(i>j) j=i;
        }
        cout<<ans<<endl;
    }
 
    return 0;
}