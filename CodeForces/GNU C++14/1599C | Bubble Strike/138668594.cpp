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
#define min_heap priority_queue <pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> >
 
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
int main()
{   
 
    ll n;
    double p;
    cin>>n>>p;
    ll x=p*100000;
 
    ll t=2*n*(n-1)*(n-2);
 
    for(ll i=0;i<=n;i++){
        ll w=0;
        if(i>=1 && n-i>=2) w+=3*i*(n-i)*(n-i-1);
        if(i>=2 && n-i>=1) w+=6*i*(i-1)*(n-i);
        if(i>=3 && n-i>=0) w+=2*i*(i-1)*(i-2);
        ll chk=(w*100000)/t;
        //cout<<i<<" "<<w<<" "<<t<<" "<<x<<" "<<chk<<endl;
        if(chk>=x){
            cout<<i<<endl;
            return 0;
        }
    }
 
    return 0;
}