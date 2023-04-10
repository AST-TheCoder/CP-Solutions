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
 
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;
 
int main()
{  
 
    ll n,m;
    cin>>n>>m;
 
    ll a[n+1];
    a[0]=0;
    ll ans=0;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=a[i-1]){
            ans+=i*(n-i+1);
        }
        else ans+=n-i+1;
    }
 
    while(m--){
        ll id,v;
        cin>>id>>v;
 
        if(a[id]!=a[id-1]) ans-=id*(n-id+1);
        else ans-=n-id+1;
 
        if(id+1<=n){
            if(a[id+1]!=a[id]) ans-=(id+1)*(n-id);
            else ans-=n-id;
        }
 
        a[id]=v;
        if(a[id]!=a[id-1]) ans+=id*(n-id+1);
        else ans+=n-id+1;
        if(id+1<=n){
            if(a[id+1]!=a[id]) ans+=(id+1)*(n-id);
            else ans+=n-id;
        }
        cout<<ans<<endl;
    }
 
    return 0;
}