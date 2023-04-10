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
        ll s,n,x=0;
        cin>>s>>n;
        vector<ll> ans;
        ll p=10;
        while(s){
            if(ans.size()+1==n){
                ans.pb(s);
                break;
            }
            if(s%p==0) p*=10;
            else{
                s-=p/10;
                ans.pb(p/10);
            }
        }
        if(ans.size()<n){
            while(ans.size()!=n){
                sort(all(ans));
                for(ll i=0;i<ans.size();i++){
                    if(ans[i]>1){
                        ll x=ans[i],p=10,q=1;
                        while((x/q)>=10) q*=10;
                        ans.erase(ans.begin()+i);
                        q=x/10;
                        while(p){
                            if(ans.size()+1==n){
                                ans.pb(x);
                                goto read;
                            }
                            ans.pb(q);
                            p--;
                            x-=q;
                        }
                        break;
                    }
                }
            }
        }
        read:
        for(ll i=0;i<n;i++) cout<<ans[i]<<" ";cout<<endl;
    }
 
    return 0;
}