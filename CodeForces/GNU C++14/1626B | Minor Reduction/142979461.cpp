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
        string s;
        cin>>s;
 
        for(ll i=s.size()-2;i>=0;i--){
            ll x=(int)(s[i]-'0');
            ll y=(int)(s[i+1]-'0');
            if(x+y>9){
                x+=y;
                y=x%10;
                x/=10;
                s[i]=(char)(x+'0');
                s[i+1]=(char)(y+'0');
                cout<<s<<endl;
                goto read;
            }
        }
 
        ll x=(int)(s[0]-'0')+(int)(s[1]-'0');
        cout<<x;
        for(ll i=2;i<s.size();i++) cout<<s[i];
        cout<<endl;
    }
 
    return 0;
}