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
 
    ll c[121];
    c[0]=0;
    for(ll p=1;p<120;p++){
        c[p]=Max;
        for(ll i=0;i<=20;i++){
            for(ll j=0;j<=15;j++){
                for(ll k=0;k<=12;k++){
                    if(6*i+8*j+10*k>=p)
                        c[p]=min(c[p],15*i+20*j+25*k);
                }
            }
        }
        //cout<<p<<" "<<c[p]<<endl;
    }
 
    ll t;
    cin>>t;
 
    while(t--){
        ll n;
        cin>>n;
        ll x=n/120,y=n%120;
        if(n<5) cout<<15<<endl;
        else cout<<(ll)((n+1)/2)*5<<endl;
    }
 
    return 0;
}