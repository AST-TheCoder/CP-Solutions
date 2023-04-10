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
 
ll a[200007],node[800007];
 
void build(ll n,ll l,ll r){
    if(l==r){
        node[n]=a[l];
        return;
    }
 
    build(2*n,l,(l+r)/2);
    build(2*n+1,(l+r)/2+1,r);
    node[n]=max(node[2*n],node[2*n+1]);
}
 
ll query(ll n,ll l,ll r,ll i,ll j){
    if(j<i) return 0;
    if(i>r || j<l) return 0;
    if(l>=i && r<=j) return node[n];
 
    return max(query(2*n,l,(l+r)/2,i,j),query(2*n+1,(l+r)/2+1,r,i,j));
}
 
int main()
{   
    
    ll n,m;
    scanf("%lli %lli",&n,&m);
 
    for(ll i=1;i<=m;i++) scanf("%lli",&a[i]);
    build(1,1,m);
 
    ll q;
    scanf("%lli",&q);
 
    while(q--){
        ll x,y,u,v,k;
        scanf("%lli %lli %lli %lli %lli",&x,&y,&u,&v,&k);
 
        ll ok=0;
        if(abs(x-u)%k || abs(y-v)%k) ok=1;
        ll val;
        if(y<v) val=query(1,1,m,y+1,v-1);
        else val=query(1,1,m,v+1,y-1);
        if(val>=x){
            ll d=(val-x)/k;
            val=(d+1)*k+x;
            if(val>n) ok=1;
        }
 
        if(ok) printf("NO\n");
        else printf("YES\n");
    }
 
    return 0;
}