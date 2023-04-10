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
        ll n,k;
        cin>>n>>k;
 
        if(k==n-1 && n==4){
            cout<<-1<<endl;
            continue;
        }
 
        for(ll i=0;i<n;i++) a[i]=0;
 
        if(k!=n-1 && k){
            cout<<k<<" "<<n-1<<endl;
            cout<<0<<" "<<n-1-k<<endl;
            a[0]=a[k]=a[n-1-k]=a[n-1]=1;
        }
        else if(k==n-1){
            cout<<n-1<<" "<<n-2<<endl;
            cout<<1<<" "<<n-3<<endl;
            cout<<0<<" "<<2<<endl;
            a[0]=a[1]=a[2]=a[n-1]=a[n-2]=a[n-3]=1;
        }
 
        ll d=n/2-1;
        for(ll i=0;i<n/2;i++){
            if(!a[d-i]) cout<<d-i<<" "<<d+i+1<<endl;
        }
    }
 
    return 0;
}