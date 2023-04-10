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
 
        ll a[3][n+1],s[n+1];
        s[0]=0;
        for(ll i=1;i<=2;i++){
            for(ll j=1;j<=n;j++){
                cin>>a[i][j];
                if(i==2) s[j]=s[j-1]+a[i][j];
            }
        }
        ll ans=Max,c=0;
        for(ll i=n;i>=1;i--){
            ans=min(ans,max(s[i-1],c));
            c+=a[1][i];
        }
        cout<<ans<<endl;
    }
 
    return 0;
}