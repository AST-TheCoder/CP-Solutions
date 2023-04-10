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
    scanf("%lli",&t);
 
    read:
    while(t--){
        ll n,k;
        cin>>n>>k;
 
        ll a[n],ans=Max;
        for(ll i=0;i<n;i++) cin>>a[i];
 
        for(ll i=max(1LL,a[n-1]/k);i<=a[n-1];i++){
            ll x=Max,y=0;
            for(ll j=0;j<n;j++){
                ll c=a[j]/i;
                if(!c) c++;
                if(c>k) c=k;
 
                ll v=a[j]/c;
                if(v>i && c<k){
                    c++;
                    v=a[j]/c;
                }
                x=min(x,v);
                y=max(y,v);
            }
            //cout<<x<<" "<<y<<endl;
            ans=min(ans,y-x);
        }
        cout<<ans<<endl;
    }
 
    return 0;
}