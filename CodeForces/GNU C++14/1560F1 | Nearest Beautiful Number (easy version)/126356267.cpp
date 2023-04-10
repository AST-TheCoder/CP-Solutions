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
 
ll d[10];
string furnish(string s,ll id){
    for(ll i=id;i<s.size();i++) s[i]='0';
    for(ll i=id-1;i>=0;i--){
        if(s[i]!='9'){
            s[i]++;
            break;
        }
        s[i]='0';
        if(!i){
            s="1"+s;
            break;
        }
    }
    return s;
}
 
int main()
{   
    
    ll t;
    cin>>t;
 
    read:
    while(t--){
        string s;
        ll k;
        cin>>s>>k;
 
        while(1){
            up:
            //cout<<s<<endl;
            memset(d,0,sizeof(d));
            ll c=0;
            for(ll i=0;i<s.size();i++){
                if(!d[s[i]-'0']){
                    if(c==k){
                        ll ok=-1;
                        for(ll j=s[i]-'0';j<=9;j++){
                            if(d[j]){
                                ok=j;
                                break;
                            }
                        }
                        if(ok!=-1){
                            s[i]=(char)(ok+'0');
                            for(ll j=0;j<=9;j++){
                                if(d[j]){
                                    ok=j;
                                    break;
                                }
                            }
                            for(ll j=i+1;j<s.size();j++){
                                s[j]=(char)(ok+'0');
                            }
                            cout<<s<<endl;
                            goto read;
                        }
                        s=furnish(s,i);
                        goto up;
                    }
                    else{
                        c++;
                        d[s[i]-'0']=1;
                    }
                }
            }
            break;
        }
        cout<<s<<endl;
    }
 
    return 0;
}