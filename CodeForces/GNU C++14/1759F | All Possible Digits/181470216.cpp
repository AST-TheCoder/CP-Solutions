#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define all(x) x.begin(),x.end()
#define Max 10000000000000000
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;
 
int main()
{   
 
    ll t;;
    cin>>t;
 
    read:
    while(t--){
        
        ll n,p;
        cin>>n>>p;
 
        ll a[n];
        vector<ll> v;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            v.pb(a[i]);
        }
 
        sort(all(v));
        ll m=a[n-1]-1;
        for(ll i=n-1;i>=0;i--){
            if(v[i]==m) m--;
        }
 
        if(m!=-1){
            ll ans=p-a[n-1],i;
            a[n-1]=0;
            for(i=n-2;i>=0;i--){
                if(a[i]==p-1) a[i]=0;
                else{
                    a[i]++;
                    break;
                }
            }
            if(i==-1) v.pb(1);
            for(ll i=0;i<n;i++) v.pb(a[i]);
            sort(all(v));
            for(ll i=v.size()-1;i>=0;i--){
                if(v[i]==m) m--;
            }
            if(m!=-1) ans+=m;
            cout<<ans<<endl;
            continue;
        }
 
        m=p-1;
        for(ll i=n-1;i>=0;i--) if(v[i]==m) m--;
 
        ll ans=m-a[n-1];
        if(m==-1) ans=0;
        cout<<ans<<endl;
 
    }
 
    return 0;
}