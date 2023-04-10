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
 
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;
 
int main()
{   
    ll t;
    cin>>t;
 
    read:
    while(t--){
        ll n;
        cin>>n;
 
        vector<ll> v;
        for(ll i=0;i<n;i++){
            ll x;
            cin>>x;
 
            if(v.size() && v[v.size()-1]==x) continue;
            v.pb(x);
        }
 
        for(ll i=1,ok=0;i<v.size()-1;i++){
            if(v[i]>v[i-1] && v[i]>v[i+1]){
                if(!ok) ok=1;
                else{
                    cout<<"NO"<<endl;
                    goto read;
                }
            }
            if(v[i]<v[i-1] && v[i]<v[i+1]){
                cout<<"NO"<<endl;
                goto read;
            }
        }
        cout<<"YES"<<endl;
    }
 
    return 0;
}