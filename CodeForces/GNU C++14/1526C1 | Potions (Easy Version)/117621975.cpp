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
    
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++) cin>>a[i];
 
    priority_queue<ll> q;
        
    ll ans=0;
    for(ll i=n-1;i>=0;i--){
        if(a[i]<0){
            q.push(a[i]);
            continue;
        }
        ans++;
        while(!q.empty() && a[i]+q.top()>=0){
            a[i]+=q.top();
            q.pop();
            ans++;
        }
        if(!q.empty()){
            ll x=q.top();
            q.pop();
            q.push(x+a[i]);
        }
    }
 
    cout<<ans<<endl;
 
    return 0;
}