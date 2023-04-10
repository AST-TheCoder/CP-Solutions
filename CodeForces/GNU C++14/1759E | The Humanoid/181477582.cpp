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
 
ll n,h,a[200007];
 
ll solve(ll p,ll q,ll r){
    ll cnt=0,x=h,v=0;
    for(ll i=1;i<=n;i++){
        if(a[i]<x){
            x+=a[i]/2;
            cnt++;
            continue;
        }
        if(v==0) x*=p;
        if(v==1) x*=q;
        if(v==2) x*=r;
        if(v==3) break;
        v++;
        i--;
    }
    return cnt;
}
 
int main()
{   
 
    ll t;;
    cin>>t;
 
    read:
    while(t--){
        
        cin>>n>>h;
 
        for(ll i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+n+1);
 
        ll ans=max(max(solve(2,2,3),solve(2,3,2)),solve(3,2,2));
        cout<<ans<<endl;
 
    }
 
    return 0;
}