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
        ll n,q;
        cin>>n>>q;
 
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        if(q>n){
            for(ll i=1;i<=n;i++) cout<<1;
            cout<<endl;
            continue;
        }
        ll c[q+1];
        memset(c,0,sizeof(c));
        ll idx;
        for(ll i=n-1,s=1;i>=0;i--){
            idx=i;
            if(i){
                if(a[i-1]>s) s++;
            }
            if(s>q) break;
        }
        for(ll i=0;i<n;i++){
            if(i>=idx) cout<<1;
            else if(a[i]<=q) cout<<1;
            else cout<<0;
        }
        cout<<endl;
    }
 
    return 0;
}