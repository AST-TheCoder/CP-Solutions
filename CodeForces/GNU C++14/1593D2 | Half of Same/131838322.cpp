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
 
ll d[2000001];
int main()
{
 
    ll t;
    cin>>t;
    read:
    while(t--){
        ll n,ok=1,ans=0;
        cin>>n;
 
        ll a[n];
        for(ll i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
        for(ll i=0;i<=n/2;i++){
            for(ll j=0;j<=2000000;j++) d[j]=0;
            if(count(a,a+n,a[i])>=n/2){
                cout<<-1<<endl;
                goto read;
            }
            ll c=1;
            for(ll j=i+1;j<n;j++){
                ll x=a[j]-a[i];
                for(ll k=1;k*k<=x;k++){
                    if(x%k==0){
                        if(x/k!=k) d[x/k]++;
                        d[k]++;
                    }
                }
                if(!x) c++;
            }
            for(ll j=0;j<=2000000;j++) if(d[j]+c>=n/2) ans=max(ans,j);
        }
        cout<<ans<<endl;
/*        
6
500 1000
600 1100
1500 2100
*/
        
    }
 
    return 0;
}