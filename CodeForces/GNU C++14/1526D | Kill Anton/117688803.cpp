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
 
string p[24],x="ANTO",s;
 
int main()
{   
    
    ll tt;
 
    ll id=0;
    for(ll i=0;i<4;i++){
        for(ll j=0;j<4;j++){
            for(ll k=0;k<4;k++){
                for(ll l=0;l<4;l++){
                    if(i==j || i==k || j==k || i==l || j==l || k==l) continue;
                    p[id]+=x[i];p[id]+=x[j];p[id]+=x[k];p[id]+=x[l];
                    //cout<<id<<" "<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<p[id]<<endl;
                    id++;
                }
            }
        }
    }
    cin>>tt;
 
    while(tt--){
        cin>>s;
        ll pm=-1,sw=-1;
        for(ll i=0;i<24;i++){
            ll cs=0;
            for(ll j=0,cnt=0;j<s.size();j++){
                if(s[j]==p[i][0]){
                    cs+=(j-cnt);
                    cnt++;
                }
            }
            for(ll j=0,cnt=0,c=0;j<s.size();j++){
                if(s[j]==p[i][1]){
                    cs+=(j-cnt-c);
                    cnt++;
                }
                if(s[j]==p[i][0]) c++;
            }
            for(ll j=0,cnt=0,c=0;j<s.size();j++){
                if(s[j]==p[i][2]){
                    cs+=(j-cnt-c);
                    cnt++;
                }
                if(s[j]==p[i][0] || s[j]==p[i][1]) c++;
            }
            for(ll j=0,cnt=0,c=0;j<s.size();j++){
                if(s[j]==p[i][3]){
                    cs+=(j-cnt-c);
                    cnt++;
                }
                if(s[j]==p[i][0] || s[j]==p[i][1] || s[j]==p[i][2]) c++;
            }
            if(cs>sw){
                pm=i;
                sw=cs;
            }
        }
        //cout<<sw<<endl;
        for(ll i=0;i<4;i++){
            ll c=count(all(s),p[pm][i]);
            while(c--) cout<<p[pm][i];
        }cout<<endl;
    }
 
    return 0;
}