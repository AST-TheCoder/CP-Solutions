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
        ll n;
        cin>>n;
 
        ll a[n+1],b[n+1];
        for(ll i=1;i<=n;i++) cin>>a[i];
        for(ll i=1;i<=n;i++) cin>>b[i];
        a[0]=a[1]-b[1]-1;
 
        ll ans=0;
        for(ll i=n;i>0;i--){
            ll p=a[i]-b[i]+1,j;
            for(j=i;j>0;j--){
                if(a[j]>=p){
                    p=min(a[j]-b[j]+1,p);
                }
                else break;
            }
            ll x=a[i]-p+1;
            ans+=(x*(x+1))/2;
            i=j+1;
        }
        cout<<ans<<endl;
    }
 
    return 0;
}