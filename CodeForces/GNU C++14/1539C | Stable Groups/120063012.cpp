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
 
    ll n,k,x;
    cin>>n>>k>>x;
    ll a[n];
    for(ll i=0;i<n;i++) cin>>a[i];
 
    sort(a,a+n);
    vector<ll> v;
    for(ll i=1;i<n;i++){
        if(a[i]-a[i-1]>x) v.pb(a[i]-a[i-1]);
    }
 
    sort(all(v));
    ll len=v.size();
    for(ll i=0;i<v.size();i++){
        ll c=v[i]/x-(v[i]%x==0);
        if(c<=k){
            len--;
            k-=c;
        }
        else break;
    }
 
    cout<<len+1<<endl;
 
    return 0;
}