#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
 
pair<ll,ll> x[4];
ll upd(ll out){
 ll id;
 cout.flush();
 cout<<out<<endl;
 cin>>id;
 for(ll i=1;i<=3;i++){
  if(x[i].second==id) x[i].first+=out;
 }
 sort(x+1,x+4);
 return id;
}
 
int main()
{
 ll id;
 
 for(ll i=1;i<=3;i++){
  cin>>x[i].first;
  x[i].second=i;
 }
 
 cout.flush();
 cout<<"First"<<endl;
 
 sort(x+1,x+4);
 while(1){
  ll dif_1=x[2].first-x[1].first;
  ll dif_2=x[3].first-x[2].first;
 
  if(dif_1==dif_2) break;
  else if(dif_1<dif_2) id=upd(dif_1+dif_2);
  else id=upd(dif_1-dif_2);
  if(!id) return 0;
 }
 
 ll dif=x[2].first-x[1].first;
 
 id=upd(dif);
 if(!id) return 0;
 
 id=upd(5*dif);
 if(!id) return 0;
 
 dif=x[2].first-x[1].first;
 id=upd(dif);
 if(!id) return 0;
 
    return 0;
}