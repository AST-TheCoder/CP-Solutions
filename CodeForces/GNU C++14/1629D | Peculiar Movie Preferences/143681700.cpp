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
    cin>>t;
 
    read:
    while(t--){
        ll n;
        cin>>n;
 
        string s[n];
        pair<string,ll> p[n];
        for(ll i=0;i<n;i++){
            cin>>s[i];
            p[i].first=s[i];
            p[i].second=i;
        }
 
        for(ll i=0;i<n;i++){
            if(s[i].size()==1){
                cout<<"YES"<<endl;
                goto read;
            }
            if(s[i].size()==2 && s[i][0]==s[i][1]){
                cout<<"YES"<<endl;
                goto read;
            }
            if(s[i].size()==3 && s[i][0]==s[i][2]){
                cout<<"YES"<<endl;
                goto read;
            }
        }
        sort(s,s+n);
        sort(p,p+n);
 
        for(ll i=0;i<n;i++){
            string temp=s[i];
            reverse(all(temp));
            ll idx=lower_bound(s,s+n,temp)-s;
            if(idx<n && s[idx]==temp){
                cout<<"YES"<<endl;
                goto read;
            }
        }
        
        for(ll i=0;i<n;i++){
            if(s[i].size()==2) continue;
            string t1,t2;
            t1+=s[i][2];
            t1+=s[i][1];
 
            t2+=s[i][1];
            t2+=s[i][0];
 
            ll idx=lower_bound(s,s+n,t1)-s;
            if(idx<n && s[idx]==t1 && p[idx].second<p[i].second){
                cout<<"YES"<<endl;
                goto read;
            }
            
            idx=upper_bound(s,s+n,t2)-s;
            idx--;
            if(idx>=0 && s[idx]==t2 && p[idx].second>p[i].second){
                cout<<"YES"<<endl;
                goto read;
            }
        }
        cout<<"NO"<<endl;
    }
 
    return 0;
}