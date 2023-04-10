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
    
    ll t;
    cin>>t;
 
    read:
    while(t--){
        ll n,x;
        cin>>n>>x;
 
        ll a[n+5],mx=0,mn=INT_MAX,ans=0;
        for(ll i=1;i<=n;i++){
            cin>>a[i];
            mx=max(mx,a[i]);
            mn=min(mn,a[i]);
            if(i>1) ans+=(abs(a[i]-a[i-1]));
        }
        
        if(mn>1){
            ll val=INT_MAX;
            for(ll i=1;i<n;i++){
                val=min(val,2*(min(a[i],a[i+1])-1));
            }
            if(a[1]-1<val) val=a[1]-1;
            if(a[n]-1<val) val=a[n]-1;
            ans+=val;
        }
        if(mx<x){
            ll val=INT_MAX;
            for(ll i=1;i<n;i++){
                val=min(val,2*(x-max(a[i],a[i+1])));
            }
            if(x-a[1]<val) val=x-a[1];
            if(x-a[n]<val) val=x-a[n];
            ans+=val;
        }
        cout<<ans<<endl;
    }
 
    return 0;
}