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
    scanf("%lli",&t);
 
    read:
    while(t--){
        ll n,z=0,zz=0;
        scanf("%lli",&n);
        set<ll> s;
        for(ll i=0;i<n;i++){
            ll x;
            scanf("%lli",&x);
            if(!x) z++;
            else{
                ll sz=s.size();
                s.insert(x);
                if(sz==s.size()) zz++;
            }
        }
        if(z==n) s.insert(0);
        for(;;){
            if(s.size()==1){
                if(zz && !z) s.insert(0);
                printf("%lli\n",(*s.begin()));
                goto read;
            }
            set<ll> temp;
            if(z){
                temp.insert(*s.begin());
                z--;
            }
            z+=zz;
            zz=0;
            ll c=0,v;
            for(auto x: s){
                if(!c){
                    v=x;
                    c=1;
                }
                else{
                    ll sz=temp.size();
                    temp.insert(x-v);
                    if(sz==temp.size()) zz++;
                    v=x;
                }
                //cout<<x<<" ";
            }//cout<<endl;
            s=temp;
        }
    }
 
    return 0;
}