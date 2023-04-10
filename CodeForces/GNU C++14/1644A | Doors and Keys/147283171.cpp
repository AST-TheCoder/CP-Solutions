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
 
        ll r=0,g=0,b=0;
        for(ll i=0;i<s.size();i++){
            if(s[i]=='r') r++;
            if(s[i]=='g') g++;
            if(s[i]=='b') b++;
            if(s[i]=='R'){
                if(!r){
                    cout<<"NO"<<endl;
                    goto read;
                }
                r--;
            }if(s[i]=='G'){
                if(!g){
                    cout<<"NO"<<endl;
                    goto read;
                }
                g--;
            }if(s[i]=='B'){
                if(!b){
                    cout<<"NO"<<endl;
                    goto read;
                }
                b--;
            }
        }
        cout<<"YES"<<endl;
    }
 
    return 0;
}