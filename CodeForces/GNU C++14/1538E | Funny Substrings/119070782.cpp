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
 
map<string,pair<ll,string>> x;
 
string make_string(string v){
    string s="";
    for(ll i=0;i<3;i++){
        if(i<v.size()) s+=v[i];
        else s+="*";
    }
    for(ll i=((ll)v.size())-3;i<v.size();i++){
        if(i>=0) s+=v[i];
        else s+="*";
    }
    return s;
}
 
int main()
{
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        for(ll i=1;i<=n;i++){
            string v,op;
            cin>>v>>op;
            if(op==":="){
                string val;
                cin>>val;
                ll cnt=0;
                for(ll i=0;(ll)val.size()>=4 && i<((ll)val.size())-3;i++){
                    if(val[i]=='h' && val[i+1]=='a' && val[i+2]=='h' && val[i+3]=='a')
                        cnt++;
                }
                string s=make_string(val);
                x[v]={cnt,s};
            }
            else{
                string v1,v2;
                cin>>v1>>op>>v2;
                string val=x[v1].second+x[v2].second;
                ll cnt=x[v1].first+x[v2].first;
                for(ll i=3;i<6;i++){
                    if(val[i]=='h' && val[i+1]=='a' && val[i+2]=='h' && val[i+3]=='a')
                        cnt++;
                }  
                val="";
                string u=x[v1].second,q=x[v2].second;
                for(ll i=5;i>=0;i--){
                    if(u[i]=='*') break;
                    val+=u[i];
                }
                reverse(all(val));
                for(ll i=0;i<6;i++){
                    if(q[i]=='*') break;
                    val+=q[i];
                }
                string s=make_string(val);
                x[v]={cnt,s};
            }
            if(i==n)
                cout<<x[v].first<<endl;
        }
    }
 
    return 0;
}