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
 
    while(t--){
        string s;
        cin>>s;
        ll cnt[200];
        memset(cnt,0,sizeof(cnt));
 
        for(ll i=0;i<s.size();i++){
            cnt[s[i]]++;
        }
 
        for(ll i=0;i<s.size();i++){
            if(cnt[s[i]]>1) cnt[s[i]]--;
            else{
                for(ll j=i;j<s.size();j++){
                    cout<<s[j];
                }cout<<endl;
                break;
            }
        }
    }
 
    return 0;
}