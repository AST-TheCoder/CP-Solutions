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
        ll n,x;
        cin>>n>>x;
 
        ll a[n+1];
        for(ll i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+n+1);
 
        ll ans=0,s=0;
        for(ll i=1;i<=n;i++){
            if(s+a[i]>x){
                ans=i-1;
                break;
            }
            s+=a[i];
            if(i==n) ans=n;
        }
        s+=ans;
        for(ll i=ans,k=1;i>=1;i--){
            //cout<<i<<" "<<s<<endl;
            if(s>x){
                s-=(a[i]+k);
            }
            else{
                ll d=(x-s)/i+1;
                ans+=(d*i);
                s+=d*i;
                k+=d;
                s-=(a[i]+k);
            }
        }
        cout<<ans<<endl;
    }
 
    return 0;
}