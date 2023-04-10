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
 
    read:
    while(t--){
        ll n;
        cin>>n;
 
        ll a[n+1],ans[n+1],s=0;
        for(ll i=1;i<=n;i++){
            cin>>a[i];
            s+=a[i];
        }
        ll x=s/((n*(n+1))/2);
        if(s%((n*(n+1))/2) || (x+a[n]-a[1])<=0 || (x+a[n]-a[1])%n){
            cout<<"NO"<<endl;
            continue;
        }
        ans[1]=(x+a[n]-a[1])/n;
        ll p=ans[1];
        for(ll i=2;i<=n;i++){
            if((x+a[i-1]-a[i])<=0 || (x+a[i-1]-a[i])%n){
                cout<<"NO"<<endl;
                goto read;
            }
            ans[i]=(x+a[i-1]-a[i])/n;
            p+=ans[i];
        }
        if(p!=x){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        for(ll i=1;i<=n;i++) cout<<ans[i]<<" ";cout<<endl;
    }
 
    return 0;
}