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
 
        ll n=s.size();
        for(ll i=0;i<s.size();i++){
            if((i==0 || s[i-1]!=s[i]) && (i==n-1 || s[i+1]!=s[i])){
                cout<<"NO"<<endl;
                goto read;
            }
        }
        cout<<"YES"<<endl;
    }
 
    return 0;
}