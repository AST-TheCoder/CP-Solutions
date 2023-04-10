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
 
    read:
    while(t--){
        ll n;
        cin>>n;
 
        string s;
        cin>>s;
 
        vector<ll> p;
        for(ll i=0;i<n;i++) p.pb(i+1);
 
        if(count(all(s),'1')==0 || count(all(s),'1')%2 || (n%2 && count(all(s),'0')==0)){
            cout<<"NO"<<endl;
            continue;
        }
 
        ll c=count(all(s),'0');
        if(!c){
            cout<<"YES"<<endl;
            cout<<1<<" "<<2<<endl;
            for(ll i=2;i<=n;i+=2){
                ll u=i;
                ll v=i+1;
                if(v<=n) cout<<u<<" "<<v<<endl;
                v++;
                if(v<=n) cout<<u<<" "<<v<<endl;
            }
            continue;
        }
        
        ll st=0;
        for(ll i=0;i<s.size();i++){
            if(s[i]=='0' && s[s.size()-1]=='1') break;
            s+=s[i];
            p.pb(p[i]);
            st++;
        }
        cout<<"YES"<<endl;
        
        vector<pair<ll,ll>> ans;
        vector<ll> seg;
        for(ll i=st+1,c=1;i<s.size();i++){
            if(s[i]!=s[i-1]){
                if(s[i]=='0') seg.pb(c);
                c=1;
            }
            else c++;
            if(i+1==s.size()) seg.pb(c);
        }
        n=s.size();
        vector<ll> chk;
        chk.pb(st);
        //cout<<s<<" "<<st<<endl;
        for(ll i=st+1,j=0,zp=st;i<n;i++){
            if(s[i]=='0'){
                ans.pb({p[i],p[i-1]});
                zp++;
            }
            else{
                if(seg[j]%2){
                    ans.pb({p[i],p[i-1]});
                    zp++;
                    seg[j]--;
                    while(seg[j]--){
                        i++;
                        ans.pb({p[zp],p[i]});
                    }
                    zp=i+1;
                    if(zp<n) chk.pb(zp);
                    j++;
                    i++;
                }
                else{
                    ans.pb({p[i],p[i-1]});
                    zp++;
                    seg[j]--;
                    while(seg[j]--){
                        i++;
                        ans.pb({p[zp],p[i]});
                    }
                    if(i+1<n) ans.pb({p[zp],p[i+1]});
                    else{
                        ans[ans.size()-1].first=p[chk[chk.size()-1]];
                        swap(chk[0],chk[chk.size()-1]);
                    }
                    zp=i+1;
                    i++;
                    j++;
                }
            }
        }
        for(ll i=1;i<chk.size();i++) ans.pb({p[chk[0]],p[chk[i]]});
        for(ll i=0;i<ans.size();i++) cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
 
    return 0;
}