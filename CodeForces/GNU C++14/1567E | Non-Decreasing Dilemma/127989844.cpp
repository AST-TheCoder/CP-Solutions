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
 
ll a[200007],node[600007],lb[600007],rb[600007];
void build(ll n,ll l,ll r){
    if(l==r){
        node[n]=1;
        lb[n]=rb[n]=l;
        return;
    }
    ll lf=2*n,rt=2*n+1,m=(l+r)/2;
    build(lf,l,m);
    build(rt,m+1,r);
    node[n]=node[lf]+node[rt];
    if(a[m]<=a[m+1]){
        ll d1=m-rb[lf]+1,d2=lb[rt]-m;
        node[n]+=d1*d2;
        if(lb[lf]!=m) lb[n]=lb[lf];
        else lb[n]=lb[rt];
        if(rb[rt]!=m+1) rb[n]=rb[rt];
        else rb[n]=rb[lf];
    }
    else{
        lb[n]=lb[lf];
        rb[n]=rb[rt];
    }
    //cout<<l<<" "<<r<<" "<<node[n]<<" "<<lb[lf]<<" "<<rb[lf]<<" "<<lb[rt]<<" "<<rb[rt]<<" "<<lb[n]<<" "<<rb[n]<<endl;
}
void update(ll n,ll l,ll r,ll i,ll v){
    if(l>i || r<i) return;
    if(l==r){
        node[n]=1;
        a[i]=v;
        return;
    }
    ll lf=2*n,rt=2*n+1,m=(l+r)/2;
    update(lf,l,m,i,v);
    update(rt,m+1,r,i,v);
    node[n]=node[lf]+node[rt];
    if(a[m]<=a[m+1]){
        ll d1=m-rb[lf]+1,d2=lb[rt]-m;
        node[n]+=d1*d2;
        if(lb[lf]!=m) lb[n]=lb[lf];
        else lb[n]=lb[rt];
        if(rb[rt]!=m+1) rb[n]=rb[rt];
        else rb[n]=rb[lf];
    }
    else{
        lb[n]=lb[lf];
        rb[n]=rb[rt];
    }
    //cout<<l<<" "<<r<<" "<<node[n]<<" "<<lb[lf]<<" "<<rb[lf]<<" "<<lb[rt]<<" "<<rb[rt]<<" "<<lb[n]<<" "<<rb[n]<<endl;
}
pair<ll,pair<ll,ll>> query(ll n,ll l,ll r,ll i,ll j){
    if(l>j || r<i) return {0,{-1,-1}};
    if(l>=i && r<=j) return {node[n],{lb[n],rb[n]}};
    ll lf=2*n,rt=2*n+1,m=(l+r)/2;
    pair<ll,pair<ll,ll>> p=query(lf,l,m,i,j);
    pair<ll,pair<ll,ll>> q=query(rt,m+1,r,i,j);
    ll ans=p.first+q.first,qlb,qrb;
 
    if(p.first && q.first){
        if(a[m]<=a[m+1]){
            ll d1=m-p.second.second+1,d2=q.second.first-m;
            ans+=d1*d2;
            if(p.second.first!=m) qlb=p.second.first;
            else qlb=q.second.first;
            if(q.second.second!=m+1) qrb=q.second.second;
            else qrb=p.second.second;
        }
        else{
            qlb=p.second.first;
            qrb=q.second.second;
        }
    }
    if(!p.first){
        qlb=q.second.first;
        qrb=q.second.second;
    }
    if(!q.first){
        qlb=p.second.first;
        qrb=p.second.second;
    }
    //cout<<l<<" "<<r<<" "<<ans<<" "<<p.second.first<<" "<<p.second.second<<" "<<q.second.first<<" "<<q.second.second<<" "<<qlb<<" "<<qrb<<endl;
    return {ans,{qlb,qrb}};
}
 
int main()
{   
 
    ll n,q;
    cin>>n>>q;
 
    for(ll i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    
    while(q--){
        ll t;
        cin>>t;
        if(t-1){
            ll l,r;
            cin>>l>>r;
            pair<ll,pair<ll,ll>> ans=query(1,1,n,l,r);
            cout<<ans.first<<endl;
        }
        else{
            ll i,v;
            cin>>i>>v;
            update(1,1,n,i,v);
        }
    }
 
    return 0;
}