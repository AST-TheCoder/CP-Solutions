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
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        vector<ll> v;
        for(ll i=0;i<n;i++){
            while(a[i]!=1 && v.size()){
                if(v[v.size()-1]==a[i]-1){
                    v.erase(v.begin()+(v.size()-1));
                    break;
                }
                v.erase(v.begin()+(v.size()-1));
            }
            v.pb(a[i]);
            cout<<v[0];
            for(ll i=1;i<v.size();i++) cout<<"."<<v[i];
            cout<<endl;
        }
    }
 
    return 0;
}