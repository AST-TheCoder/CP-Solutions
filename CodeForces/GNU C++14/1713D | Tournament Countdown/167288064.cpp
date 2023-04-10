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
 
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;
 
int main()
{   
    ll t;
    cin>>t;
 
    read:
    while(t--){
        ll n,p=1;
        cin>>n;
        for(ll i=1;i<=n;i++) p*=2;
 
        vector<ll> lev[25];
        for(ll i=0;i<25;i++) lev[i].pb(0);
 
        for(ll i=1;i<=p;i++){
            lev[1].pb(i);
        }
 
        for(ll i=1;;i+=2){
            if(lev[i].size()==2){
                cout<<"! "<<lev[i][1]<<endl;
                goto read;
            }
            if(lev[i].size()==3){
                ll pos;
                cout<<"? "<<lev[i][1]<<" "<<lev[i][2]<<endl;
                cin>>pos;
                if(pos==1) lev[i+1].pb(lev[i][1]);
                else lev[i+1].pb(lev[i][2]);
                i--;
                continue;
            }
            for(ll j=1;j<lev[i].size();j+=4){
                ll pos;
                cout<<"? "<<lev[i][j]<<" "<<lev[i][j+2]<<endl;
                cin>>pos;
 
                if(!pos){
                    cout<<"? "<<lev[i][j+1]<<" "<<lev[i][j+3]<<endl;
                    cin>>pos;
                    if(pos==1) lev[i+2].pb(lev[i][j+1]);
                    else lev[i+2].pb(lev[i][j+3]);
                }
                else if(pos==1){
                    cout<<"? "<<lev[i][j]<<" "<<lev[i][j+3]<<endl;
                    cin>>pos;
                    if(pos==1) lev[i+2].pb(lev[i][j]);
                    else lev[i+2].pb(lev[i][j+3]);
                }
                else{
                    cout<<"? "<<lev[i][j+1]<<" "<<lev[i][j+2]<<endl;
                    cin>>pos;
                    if(pos==1) lev[i+2].pb(lev[i][j+1]);
                    else lev[i+2].pb(lev[i][j+2]);
                }
            }
            lev[i].clear();
        }
    }
 
    return 0;
}