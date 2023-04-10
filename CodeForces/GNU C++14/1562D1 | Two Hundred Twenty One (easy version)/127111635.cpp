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
        ll n,q;
        cin>>n>>q;
        string s;
        cin>>s;
        ll c[n+1];
        c[0]=0;
        for(ll i=0,p=0;i<n;i++){
            if(i%2){
                if(s[i]=='+') s[i]='-';
                else s[i]='+';
            }
            if(s[i]=='+') p++;
            else p--;
            c[i+1]=p;
        }
        while(q--){
            ll l,r;
            cin>>l>>r;
            ll d=abs(c[r]-c[l-1]);
            if(d==0) cout<<0<<endl;
            else if(d%2) cout<<1<<endl;
            else cout<<2<<endl;
        }
    }
 
    return 0;
}