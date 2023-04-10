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
 
ll a[100000];
 
int main()
{   
 
    ll t;
    cin>>t;
 
    while(t--){
        ll n,x,y;
        cin>>n>>x>>y;
 
        ll a[n],c=0;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            if(a[i]%2) c++;
        }
 
        if(c%2){
            if(y%2){
                if(x%2) cout<<"Bob"<<endl;
                else cout<<"Alice"<<endl;
            }
            else{
                if(x%2) cout<<"Alice"<<endl;
                else cout<<"Bob"<<endl;
            }
        }
        else{
            if(y%2){
                if(x%2) cout<<"Alice"<<endl;
                else cout<<"Bob"<<endl;
            }
            else{
                if(x%2) cout<<"Bob"<<endl;
                else cout<<"Alice"<<endl;
            }
        }
    }
 
    return 0;
}