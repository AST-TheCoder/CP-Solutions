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
        ll n,m;
        cin>>n;
 
        ll x=0,y=0;
        for(ll i=0;i<n;i++){
            ll v;
            cin>>v;
            x=max(x,v);
        }
        cin>>m;
        for(ll i=0;i<m;i++){
            ll v;
            cin>>v;
            y=max(y,v);
        }
 
        if(x>y){
            cout<<"Alice\nAlice"<<endl;
        }
        if(x==y){
            cout<<"Alice\nBob"<<endl;
        }
        if(x<y){
            cout<<"Bob\nBob"<<endl;
        }
    }
 
    return 0;
}