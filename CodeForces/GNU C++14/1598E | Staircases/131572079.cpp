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
 
ll a[1005][1005];
ll v[1005][1005][2],ans,cell;
 
int main()
{
 
    ll n,m,q;
    cin>>n>>m>>q;
    cell=n*m;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            if(j-1) v[i][j][1]=v[i][j-1][0]+1;
            if(i-1) v[i][j][0]=v[i-1][j][1]+1;
            ans+=v[i][j][0]+v[i][j][1];
        }
    }
    while(q--){
        ll x,y;
        cin>>x>>y;
        if(!a[x][y]){
            a[x][y]=1;
            cell--;
            for(ll i=x,j=y,p=0,q=0;i<=n && j<=m;i++,j++){
                if(j+1<=m){
                    if(a[i][j+1]) p=1;
                    if(!p){
                        v[i][j+1][1]-=(v[x][y][0]+1);
                        ans-=(v[x][y][0]+1);
                    }
                }
                if(i+1<=n){
                    if(a[i+1][j]) q=1;
                    if(!q){
                        v[i+1][j][0]-=(v[x][y][1]+1);
                        ans-=(v[x][y][1]+1);
                    }
                }
                if(i+1<=n && j+1<=m){
                    if(a[i+1][j+1]) p=1,q=1;
                    if(!p){
                        v[i+1][j+1][0]-=(v[x][y][0]+1);
                        ans-=(v[x][y][0]+1);
                    }
                    if(!q){
                        v[i+1][j+1][1]-=(v[x][y][1]+1);
                        ans-=(v[x][y][1]+1);
                    }
                }
            }
            ans-=(v[x][y][1]+v[x][y][0]);
            v[x][y][0]=v[x][y][1]=0;
        }
        else{
            a[x][y]=0;
            if(x-1 && !a[x-1][y]) v[x][y][0]=v[x-1][y][1]+1;
            if(y-1 && !a[x][y-1]) v[x][y][1]=v[x][y-1][0]+1;
            cell++;
            for(ll i=x,j=y,p=0,q=0;i<=n && j<=m;i++,j++){
                if(j+1<=m){
                    if(a[i][j+1]) p=1;
                    if(!p){
                        v[i][j+1][1]+=(v[x][y][0]+1);
                        ans+=(v[x][y][0]+1);
                    }
                }
                if(i+1<=n){
                    if(a[i+1][j]) q=1;
                    if(!q){
                        v[i+1][j][0]+=(v[x][y][1]+1);
                        ans+=(v[x][y][1]+1);
                    }
                }
                if(i+1<=n && j+1<=m){
                    if(a[i+1][j+1]) p=1,q=1;
                    if(!p){
                        v[i+1][j+1][0]+=(v[x][y][0]+1);
                        ans+=(v[x][y][0]+1);
                    }
                    if(!q){
                        v[i+1][j+1][1]+=(v[x][y][1]+1);
                        ans+=(v[x][y][1]+1);
                    }
                }
            }
            ans+=(v[x][y][1]+v[x][y][0]);
        }
        //for(ll i=1;i<=n;i++)
        cout<<ans+cell<<endl;
    }
 
    return 0;
}