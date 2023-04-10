#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
 
int main()
{
 ll n,m,p,a=0,b=0,ans=0,i=0,j=0,k=0,l=0;
 vector<pair<ll,ll>> frst_likes,scnd_likes,both_likes,none_likes;
 cin>>n>>m>>p;
 
 for(ll i=1;i<=n;i++){
  ll t,x,y;
  cin>>t>>x>>y;
 
  if(x && y) both_likes.pb(mp(t,i));
  else if(x) frst_likes.pb(mp(t,i));
  else if(y) scnd_likes.pb(mp(t,i));
  else none_likes.pb(mp(t,i));
 }
 
 sort(all(both_likes));
 sort(all(frst_likes));
 sort(all(scnd_likes));
 sort(all(none_likes));
 
 for(i=0,j=0,k=0;a<p || b<p;){
  if(i==frst_likes.size() && j==scnd_likes.size() && k==both_likes.size()) break;
 
  if(a!=p && b!=p && k<both_likes.size()){
   if(i==frst_likes.size() || j==scnd_likes.size() || frst_likes[i].first+scnd_likes[j].first>both_likes[k].first){
    ans+=both_likes[k].first;
    k++;
   }
   else{
    ans+=(frst_likes[i].first+scnd_likes[j].first);
    i++,j++;
   }
 
   a++,b++;
  }
  else{
   while(a<p && i<frst_likes.size()){
    ans+=frst_likes[i].first;
    a++,i++;
   }
   while(b<p && j<scnd_likes.size()){
    ans+=scnd_likes[j].first;
    b++,j++;
   }
   break;
  }
 }
 
 if(a<p || b<p){
  printf("-1\n");
  return 0;
 }
 
 while(i+j+k>m && k<both_likes.size() && i && j){
  i--,j--;
  ans+=(both_likes[k].first-frst_likes[i].first-scnd_likes[j].first);
  k++;
 }
 
 if(i+j+k>m){
  printf("-1\n");
  return 0;
 }
 
 while(i+j+k+l<m){
  ll x=INT_MAX;
  if(i<frst_likes.size()) x=min(x,frst_likes[i].first);
  if(j<scnd_likes.size()) x=min(x,scnd_likes[j].first);
  if(k<both_likes.size()) x=min(x,both_likes[k].first);
  if(l<none_likes.size()) x=min(x,none_likes[l].first);
 
  ans+=x;
 
  if(k<both_likes.size() && both_likes[k].first==x) k++,a++,b++;
  else if(i<frst_likes.size() && frst_likes[i].first==x) i++,a++;
  else if(j<scnd_likes.size() && scnd_likes[j].first==x) j++,b++;
  else l++;
 }
 
 
 while(l<none_likes.size()){
  ll x=none_likes[l].first,id=-1;
  if(k && a>p && b>p && both_likes[k-1].first>=x) x=both_likes[k-1].first,id=1;
  if(i && a>p && frst_likes[i-1].first>=x) x=frst_likes[i-1].first,id=2;
  if(j && b>p && scnd_likes[j-1].first>=x) x=scnd_likes[j-1].first,id=3;
 
  if(id==-1) break;
  ans+=(none_likes[l].first-x);
  l++;
 
  if(id==1) k--,a--,b--;
  if(id==2) i--,a--;
  if(id==3) j--,b--;
 }
 
 while(i<frst_likes.size()){
  ll x=frst_likes[i].first,id=-1;
  if(k && b>p && both_likes[k-1].first>=x) x=both_likes[k-1].first,id=1;
  if(l && none_likes[l-1].first>=x) x=none_likes[l-1].first,id=2;
  if(j && b>p && scnd_likes[j-1].first>=x) x=scnd_likes[j-1].first,id=3;
 
  if(id==-1) break;
  ans+=(frst_likes[i].first-x);
  i++;a++;
 
  if(id==1) k--,a--,b--;
  if(id==2) l--;
  if(id==3) j--,b--;
 }
 
 while(j<scnd_likes.size()){
  ll x=scnd_likes[j].first,id=-1;
  if(k && a>p && both_likes[k-1].first>=x) x=both_likes[k-1].first,id=1;
  if(l && none_likes[l-1].first>=x) x=none_likes[l-1].first,id=2;
  if(i && a>p && frst_likes[i-1].first>=x) x=frst_likes[i-1].first,id=3;
 
  if(id==-1) break;
  ans+=(scnd_likes[j].first-x);
  j++;b++;
 
  if(id==1) k--,a--,b--;
  if(id==2) l--;
  if(id==3) i--,a--;
 }
 
 while(k<both_likes.size()){
  ll x=both_likes[k].first,id=-1;
  if(i && frst_likes[i-1].first>=x) x=frst_likes[i-1].first,id=1;
  if(l && none_likes[l-1].first>=x) x=none_likes[l-1].first,id=2;
  if(j && scnd_likes[j-1].first>=x) x=scnd_likes[j-1].first,id=3;
 
  if(id==-1) break;
  ans+=(both_likes[k].first-x);
  k++;a++;b++;
 
  if(id==1) i--,a--;
  if(id==2) l--;
  if(id==3) j--,b--;
 }
 
 cout<<ans<<endl;
 while(i--) cout<<frst_likes[i].second<<" ";
 while(j--) cout<<scnd_likes[j].second<<" ";
 while(k--) cout<<both_likes[k].second<<" ";
 while(l--) cout<<none_likes[l].second<<" ";
 
    return 0;
}