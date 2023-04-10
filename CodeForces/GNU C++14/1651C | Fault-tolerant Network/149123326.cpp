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
 
ll mark[2000001],a[1000001],chk[2000001];
 
int main()
{   
    
    ll t;
    scanf("%lli",&t);
 
    read:
    while(t--){
        ll n;
        cin>>n;
 
        ll a[n+1],b[n+1];
        for(ll i=1;i<=n;i++) cin>>a[i];
        for(ll i=1;i<=n;i++) cin>>b[i];
 
        ll x[4],y[4];
        x[1]=abs(a[1]-b[1]);
        y[1]=abs(a[n]-b[1]);
        x[2]=Max;
        y[2]=Max;
        for(ll i=2;i<n;i++){
            x[2]=min(x[2],abs(a[1]-b[i]));
            y[2]=min(y[2],abs(a[n]-b[i]));
        }
        x[3]=abs(a[1]-b[n]);
        y[3]=abs(a[n]-b[n]);
 
        ll p=Max,q=Max;
        for(ll i=1;i<=n;i++){
            p=min(p,abs(a[i]-b[1]));
            q=min(q,abs(a[i]-b[n]));
        }
 
        ll ans=Max;
        for(ll i=1;i<=3;i++){
            for(ll j=1;j<=3;j++){
                ll temp=x[i]+y[j];
                if(i!=1 && j!=1) temp+=p;
                if(i!=3 && j!=3) temp+=q;
                ans=min(ans,temp);
            }
        }
        cout<<ans<<endl;
    }
 
    return 0;
}