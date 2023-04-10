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
    scanf("%lli",&t);
 
    while(t--){
        ll n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        ll p=0,q=0,u=0,v=0,r=1,c=1;
        for(ll i=0,x=0,y=0;i<s.size();i++){
            if(s[i]=='U'){
                x++;
                p=max(p,x);
                if(p+q<n)
                    r=p+1;
            }
            if(s[i]=='D'){
                x--;
                q=max(q,-x);
                if(p+q<n)
                    r=p+1;
            }
            if(s[i]=='L'){
                y--;
                u=max(u,-y);
                if(u+v<m)
                    c=u+1;
            }
            if(s[i]=='R'){
                y++;
                v=max(v,y);
                if(u+v<m)
                    c=u+1;
            }
        }
        cout<<r<<" "<<c<<endl;
    }
 
    return 0;
}