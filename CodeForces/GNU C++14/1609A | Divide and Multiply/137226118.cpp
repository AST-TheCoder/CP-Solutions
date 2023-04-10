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
 
int main()
{   
 
    ll t;
    cin>>t;
 
    while(t--){
        ll n;
        cin>>n;
 
        ll a[n+1];
        for(ll i=1;i<=n;i++) cin>>a[i];
        //sort(a+1,a+n+1);
        ll ans=0,cnt=0;
        for(ll i=1;i<=n;i++){
            while(a[i]%2==0){
                a[i]/=2;
                cnt++;
            }
            ans+=a[i];
        }
        sort(a+1,a+n+1);
        ans-=a[n];
        a[n]*=pow(2,cnt);
        ans+=a[n];
        cout<<ans<<endl;
    }
 
    return 0;
}