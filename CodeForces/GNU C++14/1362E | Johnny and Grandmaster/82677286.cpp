#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
 
ll cnt[1000007],temp_cnt[1000007],c[1000007];
 
ll bigmod(ll x,ll p)
{
 if(p==0) return 1;
 if(p==1) return x%mod;
 if(p%2) return (x*bigmod(x,p-1))%mod;
 else{
  ll v=bigmod(x,p/2);
  return (v*v)%mod;
 }
}
 
int main()
{
 
 ll t;
 scanf("%lld",&t);
 
 while(t--){
  ll n,p;
  scanf("%lld %lld",&n,&p);
  set<ll> x;
  for(ll i=1;i<=n;i++){
   ll q;
   scanf("%lld",&q);
   temp_cnt[q]++;
   x.insert(q);
  }
  if(p==1){
   if(n%2) printf("1\n");
   else printf("0\n");
   for(set<ll>::iterator it=x.begin();it!=x.end();it++) temp_cnt[*it]=0;
   continue;
  }
 
  for(set<ll>::iterator it=x.begin();it!=x.end();it++){
   cnt[*it]+=temp_cnt[*it];
   cnt[*it+1]+=(cnt[*it]/p);
   c[*it]=cnt[*it]-temp_cnt[*it];
   cnt[*it]%=p;
   if(cnt[*it+1]) x.insert(*it+1);
  }
 
  ll ok=0,ans=0;
  for(set<ll>::reverse_iterator it=x.rbegin();it!=x.rend();it++){
   c[*it]=min(cnt[*it],c[*it]);
   if(c[*it]){
    cnt[*it-1]+=(c[*it]*p);
    cnt[*it]-=c[*it];
    if(cnt[*it]%2){
     cnt[*it]++;
     cnt[*it-1]-=p;
    }
   }
   if(cnt[*it]%2==0 && !ok){
    temp_cnt[*it]=0;
    cnt[*it]=0;
    c[*it]=0;
    continue;
   }
   else if(!ok){
    ok=1;
    ans=bigmod(p,*it);
   }
   else ans=(ans-((cnt[*it]*bigmod(p,*it))%mod)+mod)%mod;
   c[*it]=0;
   cnt[*it]=0;
   temp_cnt[*it]=0;
  }
 
  printf("%lld\n",ans);
 }
 
 return 0;
}