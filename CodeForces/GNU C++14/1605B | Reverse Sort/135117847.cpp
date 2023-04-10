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
        ll n;
        cin>>n;
        string s;
        cin>>s;
 
        vector<ll> ans;
 
        for(ll i=0,j=n-1;i<j;){
            if(s[j]=='1') j--;
            else{
                while(i<j){
                    if(s[i]=='1') break;
                    i++;
                }
                if(i<j){
                    ans.pb(i);
                    ans.pb(j);
                    i++;j--;
                }
            }
        }
        if((ll)ans.size()==0) cout<<0<<endl;
        else{
            cout<<1<<endl;
            sort(all(ans));
            cout<<ans.size();
            for(ll i=0;i<ans.size();i++) cout<<" "<<ans[i]+1;
            cout<<endl;
        }
    }
 
    return 0;
}