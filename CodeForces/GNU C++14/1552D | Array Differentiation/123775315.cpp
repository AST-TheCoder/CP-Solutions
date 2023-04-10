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
 
    int t;
    cin>>t;
 
    read:
    while(t--){
        ll n;
        cin>>n;
 
        ll a[n];
        for(ll i=0;i<n;i++) cin>>a[i];
 
        vector<ll> v;
        for(ll i=0;i<pow(2,n);i++){
            ll s=0;
            for(ll j=0;j<n;j++){
                if(i&(1<<j))
                    s+=a[j];
            }
            v.pb(s);
            //cout<<s<<endl;
        }
        for(ll i=0;i<v.size();i++){
            for(ll j=i+1;j<v.size();j++){
                if(!(i&j) && v[i]==v[j]){
                    cout<<"YES"<<endl;
                    goto read;
                }
            }
        }
 
        cout<<"NO"<<endl;
    }
 
    return 0;
}