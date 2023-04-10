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
        if(n%2){
            ll id=0,s=a[1]+a[2];
            if(a[1]+a[2]==0) id=1,s=a[0]+a[2];
            if(a[0]+a[2]==0 && id==1) id=2,s=a[0]+a[1];
            for(ll i=0;i<3;i++){
                if(i==id) cout<<-s<<" ";
                else cout<<a[id]<<" ";
            }
            for(ll i=3;i<n;i+=2){
                cout<<a[i+1]<<" "<<-a[i]<<" ";
            }
            cout<<endl;
        }
        else{
            for(ll i=0;i<n;i+=2){
                cout<<a[i+1]<<" "<<-a[i]<<" ";
 
            }
            cout<<endl;
        }
    }
 
    return 0;
}