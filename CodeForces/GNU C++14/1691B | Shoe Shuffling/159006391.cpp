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
 
int main()
{   
    ll t,ii=0;
    cin>>t;
 
    read:
    while(t--){
        ll n;
        cin>>n;
 
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        ll c=0;
        vector<ll> ans;
        for(ll i=0;i<n;i++){
            if(!i || a[i]!=a[i-1]){
                if(i+1==n || a[i]!=a[i+1]){
                    cout<<-1<<endl;
                    goto read;
                }
                if(i) ans.pb(c);
                c=0;
            }
            c++;
        }
        ans.pb(c);
        for(ll i=0,l=0;i<ans.size();i++){
            ll temp=ans[i];
            cout<<l+ans[i]<<" ";
            for(ll j=1;j<ans[i];j++){
                cout<<l+j<<" ";
            }
            l+=temp;
        }
        cout<<endl;
    }
 
    return 0;
}