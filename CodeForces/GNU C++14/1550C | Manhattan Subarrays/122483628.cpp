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
        ll n;
        cin>>n;
        ll ans=0;
        ll a[n+1];
        for(ll i=1;i<=n;i++){
            cin>>a[i];
        }
        for(ll i=1,j=1;i<=n;){
            if(j>n){
                ans+=(j-i);
                i++;
                continue;
            }
            
            ll ok=0;
            if(j-i+1>4) ok=1;
            if(j-i+1==3){
                if(a[i]<=a[i+1] && a[i+1]<=a[i+2]) ok=1;
                if(a[i]>=a[i+1] && a[i+1]>=a[i+2]) ok=1;
            }
            if(j-i+1==4){
                if(a[j-1]<=a[j] && a[j-2]<=a[j-1]) ok=1;
                if(a[j-1]<=a[j] && a[j-3]<=a[j-1]) ok=1;
                if(a[j-2]<=a[j] && a[j-3]<=a[j-2]) ok=1;
                if(a[j-1]>=a[j] && a[j-2]>=a[j-1]) ok=1;
                if(a[j-1]>=a[j] && a[j-3]>=a[j-1]) ok=1;
                if(a[j-2]>=a[j] && a[j-3]>=a[j-2]) ok=1;
            }
 
 
            if(ok){
                ans+=(j-i);
                i++;
            }
            else j++;
        }
        cout<<ans<<endl;
    }
    return 0;
}