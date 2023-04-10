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
  ll n,k;
  cin>>n>>k;
  string s;
  cin>>s;
  if(n%k){
   cout<<-1<<endl;
   continue;
  }
 
  ll cnt[s.size()][26];
  memset(cnt,0,sizeof(cnt));
 
  for(ll i=0;i<n;i++){
   if(i==0){
    cnt[i][s[i]-'a']=(1%k);
    continue;
   }
   for(ll j=0;j<26;j++){
    cnt[i][j]=cnt[i-1][j];
   }
   cnt[i][s[i]-'a']=(cnt[i][s[i]-'a']+1)%k;
  }
 
  ll ok=0;
  for(ll i=0;i<26;i++){
   if(cnt[n-1][i]) ok=1;
  }
  if(!ok){
   cout<<s<<endl;
   continue;
  }
  for(ll i=n-1;i>=0;i--){
   ll need=0;
   for(ll j=0;j<26;j++) if(cnt[i][j]) need+=(k-cnt[i][j]);
   for(char c=s[i]+1;c<='z';c++){
    ll space=need;
    if(cnt[i][c-'a']) space-=(k-cnt[i][c-'a']);
    if(cnt[i][s[i]-'a']) space-=(k-cnt[i][s[i]-'a']);
    ll x=(cnt[i][c-'a']+1)%k;
    if(x) space+=(k-x);
    ll y;
    if(cnt[i][s[i]-'a']) y=cnt[i][s[i]-'a']-1;
    else y=k-1;
    if(y) space+=(k-y);
    //cout<<i<<" "<<c<<" "<<x<<" "<<y<<" "<<space<<" "<<need<<endl;
    if(space<n-i){
     cnt[i][c-'a']=x;
     cnt[i][s[i]-'a']=y;
     s[i]=c;
     ll ok=(n-i-space-1);
     ll id=i;
     for(ll j=0;j<ok;j++){
      i++;
      s[i]='a';
     }
     c='a';
     for(i++;i<n;i++){
      while(!(cnt[id][c-'a']%k)) c++;
      s[i]=c;
      cnt[id][c-'a']++;
     }
     cout<<s<<endl;
     goto read;
    }
   }
  }
 
 }
 
 return 0;
}