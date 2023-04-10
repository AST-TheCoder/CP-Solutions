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
 
        //for(ll i=0;i<=n+1;i++) cout<<s[i]<<endl;
 
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=m;j++){
                if(s[i][j]=='0') continue;
                if(s[i-1][j]=='1' && s[i][j-1]=='1' && s[i-1][j-1]=='0'){
                    cout<<"NO"<<endl;
                    goto read;
                }
                if(s[i-1][j]=='1' && s[i][j+1]=='1' && s[i-1][j+1]=='0'){
                    cout<<"NO"<<endl;
                    goto read;
                }
                if(s[i+1][j]=='1' && s[i][j-1]=='1' && s[i+1][j-1]=='0'){
                    cout<<"NO"<<endl;
                    goto read;
                }
                if(s[i+1][j]=='1' && s[i][j+1]=='1' && s[i+1][j+1]=='0'){
                    cout<<"NO"<<endl;
                    goto read;
                }
                
            }
        }
        cout<<"YES"<<endl;
    }
 
    return 0;
}