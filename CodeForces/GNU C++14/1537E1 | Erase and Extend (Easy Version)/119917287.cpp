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
 
    ll n,p;
    cin>>n>>p;
    string s;
    cin>>s;
    s+=('z'+1);
 
    ll z[s.size()];
    z[0]=0;
 
    for(ll i=1,j=1,k=0;i<s.size();){
        if(i==j && s[0]!=s[i]) z[i]=0,i++,j++;
        else if(s[i]!=s[k]){
            ll len=i-j;
            z[j]=len;
            j++;
            k=0;
            while(k+1<len){
                k++;
                if(j+z[k]>=i) break;
                z[j]=z[k];
                j++;
            }
            k=z[k];
        }
        else k++,i++;
    }
    ll id=0;
    string ans="";
    for(ll i=0;i<n;i++){
        if(s[i+1+z[i+1]]>s[z[i+1]]) break;
        id=i+1+z[i+1];
        i=id-1;
    }
    for(ll i=0;ans.size()!=p;i++){
        if(i>id) i=0;
        ans+=s[i];
    }
    cout<<ans<<endl;
    return 0;
}