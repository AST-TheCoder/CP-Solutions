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
    
 
    ll n,m,s=1;
    cin>>n>>m;
    ll a[n+1];
    a[1]=1;
    for(ll i=2;i<=n;i++){
        a[i]=s;
        ll sq=sqrt(i);
        for(ll j=1;j<=sq;j++){
            ll l=i/j,r=i/(j+1);
            ll d=l-r;
            a[i]+=(d*a[j]);
            a[i]%=m;
            if(j!=1 && i/j!=j){
                a[i]+=a[i/j];
                a[i]%=m;
            }
        }
        s+=a[i];
        s%=m;
    }
    //for(ll i=1;i<=n;i++) cout<<a[i]<<" ";cout<<endl;
    cout<<a[n]<<endl;
 
    return 0;
}