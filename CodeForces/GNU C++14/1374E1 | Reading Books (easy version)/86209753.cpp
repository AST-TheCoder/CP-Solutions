#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define all(x) x.begin(),x.end()
 
int main()
{
 ll n,p,a=0,b=0,ans=0;
 vector<ll> frst_likes,scnd_likes,both_likes;
 scanf("%lli %lli",&n,&p);
 
 for(ll i=1;i<=n;i++){
  ll t,x,y;
  scanf("%lli %lli %lli",&t,&x,&y);
 
  if(x && y) both_likes.pb(t);
  else if(x) frst_likes.pb(t);
  else if(y) scnd_likes.pb(t);
 }
 
 sort(all(both_likes));
 sort(all(frst_likes));
 sort(all(scnd_likes));
 
 for(ll i=0,j=0,k=0;a<p || b<p;){
 
  if(i==frst_likes.size() && j==scnd_likes.size() && k==both_likes.size()) break;
 
  if(a!=p && b!=p && k<both_likes.size()){
   if(i==frst_likes.size() || j==scnd_likes.size() || frst_likes[i]+scnd_likes[j]>=both_likes[k]){
    ans+=both_likes[k];
    k++;
   }
   else{
    ans+=(frst_likes[i]+scnd_likes[j]);
    i++,j++;
   }
   a++,b++;
  }
  else{
   while(a<p && i<frst_likes.size()){
    ans+=frst_likes[i];
    a++,i++;
   }
   while(b<p && j<scnd_likes.size()){
    ans+=scnd_likes[j];
    b++,j++;
   }
   break;
  }
 }
 
 if(a<p || b<p) printf("-1\n");
 else printf("%lli\n",ans);
 
    return 0;
}