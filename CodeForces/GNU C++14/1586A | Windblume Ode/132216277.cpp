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
        ll a[n],s=0;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            s+=a[i];
        }
        ll ok=0;
        if(s%2){
            for(ll i=2;i*i<=s;i++){
                if(s%i==0){
                    ok=1;
                    break;
                }
            }
        }
        if(!(s%2) || ok){
            cout<<n<<endl;
            for(ll i=0;i<n;i++) cout<<i+1<<" ";
            cout<<endl;
        }
        else{
            cout<<n-1<<endl;
            for(ll i=0;i<n;i++){
                if(a[i]%2){
                    if(ok) cout<<i+1<<" ";
                    else ok=1;
                }
                else cout<<i+1<<" ";
            }cout<<endl;
        }
    }
 
    return 0;
}