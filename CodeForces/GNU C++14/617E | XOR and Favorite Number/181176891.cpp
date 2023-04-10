#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define all(x) x.begin(),x.end()
#define Max 10000000000000000
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;
 
ll cntp[2000007],cnts[2000007],a[100007],pre[100007],suf[100007];
 
int main()
{   
 
    ll n,m,k;
    cin>>n>>m>>k;
    for(ll i=1;i<=n;i++) cin>>a[i];
    pre[1]=a[1];
    for(ll i=2;i<=n;i++){
        pre[i]=a[i]^pre[i-1];
    }
    suf[n]=a[n];
    for(ll i=n-1;i>=1;i--){
        suf[i]=a[i]^suf[i+1];
    }
 
    ll ans[m+1];
    vector<pair<pair<ll,ll>,ll>> q;
    for(ll i=1;i<=m;i++){
        ll l,r;
        cin>>l>>r;
        q.pb({{l,r},i});
    }
 
    sort(all(q));
    ll d=sqrt(n)+1;
 
    priority_queue<pair<pair<ll,ll>,ll>> p;
    for(ll i=0,j=1;i<m;i++){
        if(q[i].first.first<=j*d){
            p.push({{q[i].first.second,q[i].first.first},q[i].second});
            continue;
        }
        ll c=0;
        while(!p.empty()){
            pair<pair<ll,ll>,ll> temp=p.top();
            p.pop();
            c++;
            q[i-c]={{temp.first.second,temp.first.first},temp.second};
        }
        p.push({{q[i].first.second,q[i].first.first},q[i].second});
        j++;
    }
    ll c=0;
    while(!p.empty()){
        pair<pair<ll,ll>,ll> temp=p.top();
        p.pop();
        c++;
        q[m-c]={{temp.first.second,temp.first.first},temp.second};
    }
 
    
 
    ll s=q[0].first.first,e=q[0].first.first,temp=0;
    cntp[pre[e]]++;
    cnts[suf[s]]++;
    if(k==a[s]) temp=1;
 
    for(ll i=0;i<m;i++){
        while(s>q[i].first.first){
            s--;
            if((pre[s-1]^pre[e])==k) temp++;
            temp+=cnts[suf[s]^k];
            cnts[suf[s]]++;
            cntp[pre[s]]++;
        }
        while(s<q[i].first.first){
            cnts[suf[s]]--;
            cntp[pre[s]]--;
            temp-=cnts[suf[s]^k];
            if((pre[s-1]^pre[e])==k) temp--;
            s++;
        }
        while(e<q[i].first.second){
            e++;
            temp+=cntp[pre[e]^k];
            cntp[pre[e]]++;
            cnts[suf[e]]++;
            if((pre[s-1]^pre[e])==k) temp++;
        }
        while(e>q[i].first.second){
            cntp[pre[e]]--;
            cnts[suf[e]]--;
            temp-=cntp[pre[e]^k];
            if((pre[s-1]^pre[e])==k) temp--;
            e--;
        }
        ans[q[i].second]=temp;
    }
 
    for(ll i=1;i<=m;i++) cout<<ans[i]<<endl;
 
    return 0;
}