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
        ll chk=0;
        cin>>s>>t;
        for(ll i=0,j=0,p=0;i<s.size() && j<t.size();i++){
            if(i%2!=p) continue;
            if(s[i]==t[j]){
                j++;
                p^=1;
            }
            if(j==t.size()){
                if(((ll)s.size()-i-1)%2==0) chk=1;
                break;
            }
        }
 
        for(ll i=0,j=0,p=1;i<s.size() && j<t.size();i++){
            if(i%2!=p) continue;
            if(s[i]==t[j]){
                j++;
                p^=1;
            }
            if(j==t.size()){
                if(((ll)s.size()-i-1)%2==0) chk=1;
                break;
            }
        }
 
        if(chk) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
 
    return 0;
}