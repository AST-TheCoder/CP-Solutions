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
    
    ll t,ii=0;
    cin>>t;
 
    while(t--){
        ll n;
        string s;
        cin>>n>>s;
 
        ll i,m=0;
        for(i=0;i<n;){
            if(s[i]=='(' && s[i+1]==')') i+=2,m++;
            else if(s[i]==s[i+1]) i+=2,m++;
            else{
                ll ok=0;
                for(ll j=i+1;j<n;j++){
                    if(s[j]==')'){
                        ok=1;
                        i=j+1;
                        m++;
                        break;
                    }
                }
                if(!ok) break;
            }
        }
        cout<<m<<" "<<n-i<<endl;
    }
 
    return 0;
}