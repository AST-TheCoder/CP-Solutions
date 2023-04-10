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
 
ll a[200007],node[400007];
 
 
ll gcd(ll a,ll b){
    if(b>a) swap(a,b);
    if(!b) return a;
    if(a%b==0) return b;
    return gcd(b,a%b);
}
 
void build(ll n,ll l,ll r){
    //cout<<n<<endl;
    if(l==r){
        node[n]=a[l];
        return;
    }
    build(2*n,l,(l+r)/2);
    build(2*n+1,(l+r)/2+1,r);
    node[n]=gcd(node[2*n],node[2*n+1]);
}
 
ll query(ll n,ll l,ll r,ll i,ll j){
    //cout<<n<<endl;
    if(l>j || r<i) return 0;
    if(l>=i && r<=j) return node[n];
    return gcd(query(2*n,l,(l+r)/2,i,j),query(2*n+1,(l+r)/2+1,r,i,j));
}
 
int main()
{   
 
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll p,q;
        cin>>p;
        if(n==1){
            cout<<1<<endl;
            continue;
        }
        for(ll i=1;i<n;i++){
            cin>>q;
            a[i]=abs(p-q);
            p=q;
        }
        //for(ll i=1;i<n;i++) cout<<a[i]<<" ";cout<<endl;
        n--;
        build(1,1,n);
        ll ans=0;
        for(ll i=1,j=1;i<=n;){
            //cout<<j<<" "<<i<<" "<<query(1,1,n,j,i)<<endl;
            if(query(1,1,n,j,i)==1) j++;
            else{
                ans=max(ans,i-j+1);
                i++;
            }
            if(j>i) i=j;
        }
        cout<<ans+1<<endl;
        for(ll i=1;i<=n;i++) a[i]=0;
        for(ll i=1;i<=2*n;i++) node[i]=0;
    }
 
    return 0;
}