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
 
ll a[1000007];
 
int main()
{   
    
    ll n,c;
    cin>>n>>c;
 
    for(ll i=0;i<n;i++){
        ll p,q,r;
        cin>>p>>q>>r;
        a[p]=max(a[p],q*r);
    }
 
 
    for(ll i=1;i<=c;i++){
        for(ll j=i,k=1;j<=c;j+=i,k++){
            a[j]=max(a[j],k*a[i]);
        }
    }
 
    //for(ll i=1;i<=c;i++) cout<<a[i]<<endl;
    vector<pair<ll,ll>> x;
    for(ll i=1,v=0;i<=c;i++){
        if(a[i]<=v) continue;
        v=a[i];
        x.pb({v,i});
    }
 
    ll q;
    cin>>q;
 
    vector<ll> ans;
    while(q--){
        ll d,h;
        cin>>d>>h;
        d*=h;
        pair<ll,ll> p={d,c+1};
        ll id=upper_bound(all(x),p)-x.begin();
        if(id<x.size()) cout<<x[id].second<<endl;
        else cout<<-1<<endl;
    }
 
    return 0;
}