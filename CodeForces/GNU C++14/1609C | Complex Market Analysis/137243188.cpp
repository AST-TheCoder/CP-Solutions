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
#define min_heap priority_queue <pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> >
 
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
bool chk[1000007];
 
int main()
{   
 
    chk[1]=1;
    for(ll i=2;i<1000007;i++){
        if(!chk[i]){
            for(ll j=2*i;j<1000007;j+=i)
                chk[j]=1;
        }
    }
 
    ll t;
    cin>>t;
 
    while(t--){
        ll n,k;
        cin>>n>>k;
 
        ll a[n];
        for(ll i=0;i<n;i++) cin>>a[i];
 
        ll x[n],y[n];
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
 
        for(ll i=0;i<n;i++){
            if(a[i]==1) x[i]++;
            if(i>=k && a[i-k]==1 && a[i]==1) x[i]+=x[i-k];
            //cout<<x[i]<<" ";
        }//cout<<endl;
        for(ll i=n-1;i>=0;i--){
            if(a[i]==1) y[i]++;
            if(i<n-k && a[i+k]==1 && a[i]==1) y[i]+=y[i+k];
        }
        ll ans=0;
        for(ll i=0;i<n;i++){
            //cout<<a[i]<<" "<<chk[a[i]]<<endl;
            //if(i>=k) cout<<x[i-k]<<endl;
            //if(i<n-k) cout<<y[i+k]<<endl;
            if(!chk[a[i]]){
                if(i>=k) ans+=x[i-k];
                if(i<n-k) ans+=y[i+k];
                if(i>=k && i<n-k) ans+=(x[i-k]*y[i+k]);
            }
        }
        cout<<ans<<endl;
    }
 
    return 0;
}