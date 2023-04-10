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
 
 
ll d[2007][2007],c[2007][2007],dp[2007],n;
 
ll solve(ll u){
    if(u>=n) return 0;
    if(dp[u]!=-1) return dp[u];
    dp[u]=Max;
    for(ll i=u;i<=n;i++){
        if(i==u && u<=2) continue;
        dp[u]=min(dp[u],c[u][i]+solve(i+1));
    }
    return dp[u];
}
 
int main()
{   
 
    ll t;
    cin>>t;
 
    read:
    while(t--){
        ll n,m;
        cin>>n>>m;
 
        pair<ll,ll> a[n];
        ll s1=0,s2=0,m1=0,m2=0,x,y,h1=0,h2=0;
 
        for(ll i=0;i<n;i++){
            cin>>a[i].first>>a[i].second;
            s1+=a[i].first;
            m1+=min(m,a[i].first);
            if(a[i].first<m) h2+=m-a[i].first;
            s2+=a[i].second;
            m2+=min(m,a[i].second);
            if(a[i].second<m) h1+=m-a[i].second;
        }
        
        if(s1>=s2){
            x=min(s1-s2+(n*m-s1+s2+1)/2,min(n*m,m1));
            y=max(h2,min(n*m-x,m2));
            x=n*m-y;
        }
        else{
            y=min(s2-s1+(n*m-s2+s1+1)/2,min(n*m,m2));
            x=max(h1,min(n*m-y,m1));
            y=n*m-x;
        }
        cout<<abs(s1-x-s2+y)<<endl;
        x-=h1;
        for(ll i=0;i<n;i++){
            ll ans=0;
            if(a[i].second<m) ans=m-a[i].second;
            ll temp=min(x,min(m-ans,a[i].first-ans));
            ans+=temp;
            x-=temp;
            cout<<ans<<" "<<m-ans<<endl;
        }
    }    
 
    return 0;
}