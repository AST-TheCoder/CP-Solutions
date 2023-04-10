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
 
    ll t;
    cin>>t;
 
    while(t--){
        ll n;
        cin>>n;
 
        ll l=Max,c1,r=0,c2,prev=Max;
        for(ll i=0;i<n;i++){
            ll a,b,c;
            cin>>a>>b>>c;
 
            if(a<l){
                l=a;
                c1=c;
                prev=Max;
            }
            if(a==l) c1=min(c1,c);
 
            if(b>r){
                r=b;
                c2=c;
                prev=Max;
            }
            if(b==r) c2=min(c2,c);
            prev=min(prev,c1+c2);
            if(l==a && r==b) prev=min(prev,c);
            cout<<prev<<endl;
        }
    }
 
    return 0;
}