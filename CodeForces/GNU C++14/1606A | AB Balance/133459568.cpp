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
 
    while(t--){
        string s;
        cin>>s;
        ll a=0,b=0;
        for(ll i=0;i<s.size()-1;i++){
            if(s[i]=='a' && s[i+1]=='b') a++;
            if(s[i]=='b' && s[i+1]=='a') b++;
        }
        if(a==b) cout<<s<<endl;
        else{
            if(s[0]=='a') s[0]='b';
            else s[0]='a';
            cout<<s<<endl;
        }
    }
 
    return 0;
}