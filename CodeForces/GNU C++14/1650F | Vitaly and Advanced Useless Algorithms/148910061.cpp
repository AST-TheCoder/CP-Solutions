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
 
ll mark[2000001],a[1000001],chk[2000001];
 
int main()
{   
    
    ll t;
    scanf("%lli",&t);
 
    read:
    while(t--){
        ll n,m;
        cin>>n>>m;
 
        pair<ll,ll> a[n+1];
        for(ll i=1;i<=n;i++){
            cin>>a[i].first;
            a[i].second=i;
        }
 
        vector<pair<ll,pair<ll,ll>>> p[n+1];
        for(ll i=1;i<=m;i++){
            ll e,t,c;
            cin>>e>>t>>c;
 
            p[e].pb({i,{t,c}});
        }
 
        vector<ll> ans[n+1],fin_ans;
        ll sum=0;
        sort(a+1,a+n+1);
        for(ll i=1;i<=n;i++){
            ll dp[p[i].size()+1][101];
            for(ll j=0;j<=p[i].size();j++){
                for(ll k=0;k<=100;k++){
                    if(!k) dp[j][k]=0;
                    else dp[j][k]=Max;
                }
            }
            for(ll j=0;j<p[i].size();j++){
                for(ll k=1;k<=100;k++){
                    if(k<=p[i][j].second.second) dp[j+1][k]=min(dp[j][k],p[i][j].second.first);
                    else dp[j+1][k]=min(dp[j][k],dp[j][k-p[i][j].second.second]+p[i][j].second.first);
                }
            }
            if(dp[p[i].size()][100]==Max){
                cout<<-1<<endl;
                goto read;
            }
            //cout<<dp[p[i].size()][100]<<endl;
            ans[i].pb(dp[p[i].size()][100]);
            for(ll j=p[i].size(),k=100;j>0 && k>0;j--){
                //cout<<j<<" "<<k<<" "<<dp[j][k]<<endl;
                if(dp[j][k]==dp[j-1][k]) continue;
                else{
                    ans[i].pb(p[i][j-1].first);
                    k-=p[i][j-1].second.second;
                }
            }
        }
        for(ll i=1;i<=n;i++){
            ll id=a[i].second;
            sum+=ans[id][0];
            if(sum>a[i].first){
                cout<<-1<<endl;
                goto read;
            }
 
            for(ll j=1;j<ans[id].size();j++)
                fin_ans.pb(ans[id][j]);
        }
        cout<<fin_ans.size()<<endl;
        for(ll i=0;i<fin_ans.size();i++) cout<<fin_ans[i]<<" ";
        cout<<endl;
    }
 
    return 0;
}