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
    read:
    while(t--){
        ll n,sum=0,ans=0;
        cin>>n;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        if((2*sum)%n){
            cout<<0<<endl;
            continue;
        }
        sum=(2*sum)/n;
        sort(a,a+n);
        for(ll i=0;i<n;i++){
            if(a[i]>sum) continue;
            ll x=sum-a[i];
            if(x<a[i]) continue;
            ll r=upper_bound(a,a+n,x)-a,l;
            if(a[i]==x) l=i+1;
            else l=lower_bound(a,a+n,x)-a;
            ans+=(r-l);
        }
        cout<<ans<<endl;
    }
 
    return 0;
}