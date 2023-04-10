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
 
    read:
    while(t--){
        ll k,n,m;
        cin>>k>>n>>m;
        ll a[n],b[m];
        vector<ll> ans;
        for(ll i=0;i<n;i++) cin>>a[i];
        for(ll i=0;i<m;i++) cin>>b[i];
 
        for(ll i=0,j=0;i<n || j<m;){
            if(i==n){
                if(!b[j]){
                    ans.pb(b[j]);
                    k++;
                }
                else{
                    if(b[j]<=k) ans.pb(b[j]);
                    else{
                        cout<<-1<<endl;
                        goto read;
                    }
                }
                j++;
            }
            else if(j==m){
                if(!a[i]){
                    ans.pb(a[i]);
                    k++;
                }
                else{
                    if(a[i]<=k) ans.pb(a[i]);
                    else{
                        cout<<-1<<endl;
                        goto read;
                    }
                }
                i++;
            }
            else if(!a[i]){
                ans.pb(a[i]);
                k++;
                i++;
            }
            else if(!b[j]){
                ans.pb(b[j]);
                k++;
                j++;
            }
            else{
                if(a[i]<=k){
                    ans.pb(a[i]);
                    i++;
                }
                else if(b[j]<=k){
                    ans.pb(b[j]);
                    j++;
                }
                else{
                    cout<<-1<<endl;
                    goto read;
                }
            }
        }
        for(ll i=0;i<ans.size();i++) cout<<ans[i]<<" ";cout<<endl;
    }
 
    return 0;
}