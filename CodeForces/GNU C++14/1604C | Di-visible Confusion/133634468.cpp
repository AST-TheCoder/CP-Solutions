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
        ll n;
        cin>>n;
        ll a[n+1],mx=0;
        for(ll i=1;i<=n;i++){
            cin>>a[i];
            mx=max(mx,a[i]);
        }
        ll lcm=1;
        for(ll i=1;i<=n;i++){
            lcm=(lcm*(i+1))/__gcd(lcm,i+1);
            if(lcm>mx) break;
            if(a[i]%lcm==0){
                cout<<"NO"<<endl;
                goto read;
            }
        }
        cout<<"YES"<<endl;
    }
 
    return 0;
}