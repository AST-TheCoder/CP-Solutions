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
 
void p(ll n,ll m,char x,char y){
    x=x-'a'+'A';
    y=y-'a'+'A';
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if((i+j)%2) cout<<y;
            else cout<<x;
        }cout<<endl;
    }
}
 
int main()
{
    ll t;
    cin>>t;
 
    read:
    while(t--){
        ll n,m;
        cin>>n>>m;
        string s[n];
        vector<ll> r,w;
        for(ll i=0;i<n;i++){
            cin>>s[i];
            for(ll j=0;j<m;j++){
                if(s[i][j]=='R') r.pb(i+j);
                if(s[i][j]=='W') w.pb(i+j);
            }
        }
        for(ll i=1;i<r.size();i++){
            if(r[i]%2!=r[i-1]%2){
                cout<<"NO"<<endl;
                goto read;
            }
        }
 
        for(ll i=1;i<w.size();i++){
            if(w[i]%2!=w[i-1]%2){
                cout<<"NO"<<endl;
                goto read;
            }
        }
 
        if(r.size() && w.size() && r[0]%2==w[0]%2){
            cout<<"NO"<<endl;
            goto read;
        }
        cout<<"YES"<<endl;
        if(w.size()){
            if(w[0]%2) p(n,m,'r','w');
            else p(n,m,'w','r');
        }
        else if(r.size()){
            if(r[0]%2) p(n,m,'w','r');
            else p(n,m,'r','w');
        }
        else p(n,m,'r','w');
    }
 
    return 0;
}