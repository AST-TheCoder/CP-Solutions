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
 
ll a[100007],node[400007];
 
void build(ll n,ll l,ll r){
    if(l==r){
        node[n]=a[l];
        return;
    }
    build(2*n,l,(l+r)/2);
    build(2*n+1,(l+r)/2+1,r);
    node[n]=min(node[2*n],node[2*n+1]);
}
 
void update(ll n,ll l,ll r,ll idx,ll val){
    if(idx<l || idx>r) return;
    if(l==r){
        a[l]=val;
        node[n]=a[l];
        return;
    }
    update(2*n,l,(l+r)/2,idx,val);
    update(2*n+1,(l+r)/2+1,r,idx,val);
    node[n]=min(node[2*n],node[2*n+1]);
}
 
ll query_left(ll n,ll l,ll r,ll i,ll j){
    if(i>r || j<l) return Max;
    if(l>=i && r<=j) return node[n];
 
    return min(query_left(2*n,l,(l+r)/2,i,j),query_left(2*n+1,(l+r)/2+1,r,i,j));
}
 
int main()
{   
    ll t,ii=0;
    cin>>t;
 
    read:
    while(t--){
        ll n,m;
        cin>>n>>m;
 
        for(ll i=0;i<=4*n;i++){
            node[i]=Max;
        }
 
        for(ll i=1;i<=n;i++) cin>>a[i];
 
        build(1,1,n);
        set<ll> s;
        for(ll i=1,val=Max;i<=n;i++){
            if(a[i]<val){
                s.insert(i);
                val=a[i];
            }
        }
        while(m--){
            ll idx,val;
            cin>>idx>>val;
            ll left_min=Max;
            if(idx!=1) left_min=query_left(1,1,n,1,idx-1);
            if(left_min>a[idx]-val){
                set<ll>::iterator it=s.lower_bound(idx);
                while(it!=s.end() && a[*it]>=a[idx]-val){
                    ll temp=*it;
                    it++;
                    s.erase(temp);
                }
                s.insert(idx);
            }
            update(1,1,n,idx,a[idx]-val);
            cout<<s.size()<<" ";
        }
        cout<<endl;
    }
 
    return 0;
}