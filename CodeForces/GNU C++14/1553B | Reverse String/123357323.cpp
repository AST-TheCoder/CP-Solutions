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
    
    ll tc;
    cin>>tc;
    
    read:
    while(tc--){
        string s,t;
        cin>>s>>t;
        
        for(ll i=0;i<s.size();i++){
            for(ll j=0,k=i;j<t.size() && k<s.size();j++,k++){
                if(t[j]==s[k]){
                    ll l,m;
                    for(l=j+1,m=k-1;l<t.size() && m>=0;l++,m--){
                        if(t[l]!=s[m]) break;
                    }
                    if(l==t.size()){
                        cout<<"YES"<<endl;
                        goto read;
                    }
                }
                else break;
            }
        }
 
        cout<<"NO"<<endl;
        
    }
 
    return 0;
}