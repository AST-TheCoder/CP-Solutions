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
    ll t,ii=0;
    cin>>t;
 
    read:
    while(t--){
        
        ll n;
        cin>>n;
 
        ll a[n+1];
        for(ll i=1;i<=n;i++) cin>>a[i];
 
        sort(a+1,a+n+1);
 
        if(n%2 || a[1]==a[n/2+1] || a[n/2]==a[n]){
            cout<<"NO"<<endl;
            continue;
        }
        for(ll i=2;i<=n/2;i++){
            if(a[i]==a[i+n/2-1]){
                cout<<"NO"<<endl;
                goto read;
            }
        }
        cout<<"YES"<<endl;
        ll ans[n+1];
        for(ll i=1;i<=n;i+=2) ans[i]=a[(i+1)/2];
        for(ll i=2;i<=n;i+=2) ans[i]=a[(i+n)/2];
        for(ll i=1;i<=n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
 
    return 0;
}