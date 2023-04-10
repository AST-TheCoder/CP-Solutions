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
 
/*
1
10 3 36
2789190681
*/
 
ll n,a,b,dp[41][41][41][81],path[41][41][41][81];
string s;
void solve(ll i,ll x,ll y,ll d){
    if(i==s.size()){
        if(x || y || abs(d-40)==s.size()) dp[i][x][y][abs(d)]=Max;
        else dp[i][x][y][abs(d)]=abs(d-40);
        return;
    }
    if(dp[i][x][y][abs(d)]!=-1) return;
    ll c1=(10*x+(ll)(s[i]-'0'))%a;
    ll c2=(10*y+(ll)(s[i]-'0'))%b;
    solve(i+1,c1,y,d+1);
    solve(i+1,x,c2,d-1);
    if(dp[i+1][c1][y][abs(d+1)]<=dp[i+1][x][c2][abs(d-1)]){
        dp[i][x][y][abs(d)]=dp[i+1][c1][y][abs(d+1)];
        path[i][x][y][abs(d)]=1;
    }
    else{
        dp[i][x][y][abs(d)]=dp[i+1][x][c2][abs(d-1)];
        path[i][x][y][abs(d)]=2;
    }
    //cout<<i<<" "<<x<<" "<<y<<" "<<d<<" "<<dp[i][x][y][abs(d)]<<" "<<path[i][x][y][abs(d)]<<endl;
}
void print_path(ll i,ll x,ll y,ll d){
    if(i==s.size()) return;
    if(path[i][x][y][abs(d)]==1){
        cout<<"R";
        ll c=(10*x+(ll)(s[i]-'0'))%a;
        print_path(i+1,c,y,d+1);
    }
    else{
        cout<<"B";
        ll c=(10*y+(ll)(s[i]-'0'))%b;
        print_path(i+1,x,c,d-1);
    }
 
}
 
int main()
{
 
    ll t;
    cin>>t;
    read:
    while(t--){
        cin>>n>>a>>b;
        cin>>s;
        memset(dp,-1,sizeof(dp));
        memset(path,-1,sizeof(path));
        solve(0,0,0,40);
        if(dp[0][0][0][40]==Max) cout<<-1<<endl;
        else{
            print_path(0,0,0,40);
            cout<<endl;
        }
    }
 
    return 0;
}