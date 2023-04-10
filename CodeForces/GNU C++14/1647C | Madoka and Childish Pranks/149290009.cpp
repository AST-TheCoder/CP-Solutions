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
    
    ll t;
    cin>>t;
 
    read:
    while(t--){
        ll n,m;
        cin>>n>>m;
        string s[n+2];
        for(ll i=1;i<=n;i++) cin>>s[i];
        for(ll i=0;i<=m+1;i++){
            s[0]+='0';
            s[n+1]+='0';
        }
        for(ll i=1;i<=n;i++){
            s[i]="0"+s[i]+"0";
        }
 
        if(s[1][1]=='1'){
            cout<<-1<<endl;
            continue;
        }
 
        vector<pair<pair<ll,ll>,pair<ll,ll>>> ans;
        for(ll i=n;i>=1;i--){
            for(ll j=m;j>=1;j--){
                if(i!=1){
                    if(s[i][j]=='1'){
                        ans.pb({{i-1,j},{i,j}});
                    }
                }
                else{
                    if(s[i][j]=='1'){
                        ans.pb({{i,j-1},{i,j}});
                    }
                }
            }
        }
        cout<<ans.size()<<endl;
        for(ll i=0;i<ans.size();i++){
            cout<<ans[i].first.first<<" "<<ans[i].first.second<<" "<<ans[i].second.first<<" "<<ans[i].second.second<<endl;
        }
    }
 
    return 0;
}