#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll unsigned long long int
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
        ll a[3][n+1];
        for(ll i=1;i<=2;i++){
            for(ll j=1;j<=n;j++) cin>>a[i][j];
        }
        pair<ll,ll> b[3][n+1];
        ll s=0,e=1,ans;
 
        for(ll i=n;i>=1;i--){
            if(i==1){
                ans=max(e+1,a[2][1]+1);
            }
            if(i==n){
                s=a[1][n]+1;
                e=a[1][n]+2;
                if(e<=a[2][n]){
                    e=a[2][n]+1;
                    s=e-1;
                }
                b[1][n]={s,e};
                continue;
            }
            if(a[1][i]+1<s) s--;
            else{
                ll d=a[1][i]-s+2;
                s=a[1][i]+1;
                e+=d;
            }
            if(a[2][i]+1<=e+1) e++;
            else{
                ll d=a[2][i]-e;
                e=a[2][i]+1;
                s+=d;
            }
            b[1][i]={s,e};
        }
 
        for(ll i=n;i>=1;i--){
            if(i==n){
                s=a[2][n]+1;
                e=a[2][n]+2;
                if(e<=a[1][n]){
                    e=a[1][n]+1;
                    s=e-1;
                }
                b[2][n]={s,e};
                continue;
            }
            if(a[2][i]+1<s) s--;
            else{
                ll d=a[2][i]-s+2;
                s=a[2][i]+1;
                e+=d;
            }
            if(a[1][i]+1<=e+1) e++;
            else{
                ll d=a[1][i]-e;
                e=a[1][i]+1;
                s+=d;
            }
            b[2][i]={s,e};
        }
 
        for(ll i=2,j=1,chk=a[2][1]+1;j<n;j++){
            if(b[i][j+1].first>chk) ans=min(ans,b[i][j+1].second);
            else ans=min(ans,chk+(n-j)*2);
 
            chk=max(chk+1,a[i][j+1]+1);
            if(i==1) i=2;
            else i=1;
 
            chk=max(chk+1,a[i][j+1]+1);
        }
        cout<<ans<<endl;
    }
 
    return 0;
}