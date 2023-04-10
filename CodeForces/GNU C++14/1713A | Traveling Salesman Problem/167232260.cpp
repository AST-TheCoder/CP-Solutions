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
 
    while(t--){
        ll n;
        cin>>n;
 
        ll x=-Max,y=Max,a=-Max,b=Max;
        for(ll i=1;i<=n;i++){
            ll p,q;
            cin>>p>>q;
 
            x=max(x,p);
            y=min(y,p);
 
            a=max(a,q);
            b=min(b,q);
        }
 
        if(a<0) a=0;
        if(b>0) b=0;
        if(x<0) x=0;
        if(y>0) y=0;
 
        cout<<2*(abs(x)+abs(y)+abs(a)+abs(b))<<endl;
    }
 
    return 0;
}