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
        ll n,m;
        cin>>n>>m;
 
        ll a[n][m];
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
 
        pair<ll,ll> ans[n];
        ll x=-1,y=-1;
        for(ll i=0;i<n;i++){
            ans[i]={-1,-1};
            pair<ll,ll> temp[m];
            for(ll j=m-1,v=Max,pos=m;j>=0;j--){
                if(a[i][j]<v){
                    v=a[i][j];
                    pos=j;
                }
                temp[j]={v,pos};
            }
            for(ll j=0;j<m;j++){
                if(temp[j].first<a[i][j]){
                    ans[i]={j,temp[j].second};
                    x=j,y=temp[j].second;
                    swap(a[i][j],a[i][temp[j].second]);
                    break;
                }
            }
            for(ll j=1;j<m;j++){
                if(a[i][j]<a[i][j-1]){
                    cout<<-1<<endl;
                    goto read;
                }
            }
        }
        if(x==-1){
            cout<<1<<" "<<1<<endl;
            continue;
        }
 
        for(ll i=0;i<n;i++){
            if(ans[i].first==-1){
                if(a[i][x]!=a[i][y]){
                    cout<<-1<<endl;
                    goto read;
                }
                ans[i].first=x;
                ans[i].second=y;
            }
            if(ans[i].first!=x || ans[i].second!=y){
                cout<<-1<<endl;
                goto read;
            }
        }
        cout<<x+1<<" "<<y+1<<endl;
    }
 
    return 0;
}