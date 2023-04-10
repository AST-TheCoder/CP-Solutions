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
 
    read:
    while(t--){
        string s;
        cin>>s;
        
        ll x[200],sz=0;
        memset(x,0,sizeof(x));
        string p;
        for(ll i=s.size()-1;i>=0;i--){
            if(!x[s[i]]) p+=s[i];
            x[s[i]]=1;
        }
        reverse(all(p));
        memset(x,0,sizeof(x));
        for(ll i=0;i<p.size();i++){
            ll c=count(all(s),p[i]);
            if(c%(i+1)){
                cout<<-1<<endl;
                goto read;
            }
            x[p[i]]=c/(i+1);
            sz+=x[p[i]];
        }
        string ans;
        for(ll i=0;i<s.size() && sz;i++,sz--){
            if(!x[s[i]]){
                cout<<-1<<endl;
                goto read;
            }
            x[s[i]]--;
            ans+=s[i];
        }
        string temp=ans,chk;
        for(ll i=0;i<p.size();i++){
            chk+=temp;
            string tmp;
            for(ll j=0;j<temp.size();j++){
                if(temp[j]==p[i]) continue;
                tmp+=temp[j];
            }
            temp=tmp;
        }
        if(chk!=s){
            cout<<-1<<endl;
            goto read;
        }
        cout<<ans<<" "<<p<<endl;
    }
 
    return 0;
}