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
 
        ll a[n+1];
        for(ll i=1;i<=n;i++) cin>>a[i];
 
        ll temp=0,s=0;
        for(ll i=2;i<n;i++){
            temp+=a[i]%2;
            s+=a[i];
        }
        if(temp==n-2 && (s==temp || n==3)){
            cout<<-1<<endl;
            continue;
        }
 
        ll ans=temp+(s-temp)/2;
        cout<<ans<<endl;
    }
 
    return 0;
}