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
 
int main()
{
 
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        ll a[n+1];
        memset(a,0,sizeof(a));
        for(ll i=0;i<m;i++){
            ll p,q,r;
            cin>>p>>q>>r;
            a[q]=1;
        }
        ll s;
        for(ll i=1;i<=n;i++){
            if(!a[i]){
                s=i;
                break;
            }
        }
        for(ll i=1;i<=n;i++){
            if(i==s) continue;
            cout<<s<<" "<<i<<endl;
        }
    }
 
    return 0;
}