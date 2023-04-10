#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
 
int par[200007];
int p[200007];
int t[200007],endx[200007];
queue<int> srt[200007];
 
int find_par(int x){
 if(par[x]==x) return x;
 return par[x]=find_par(par[x]);
}
 
int find_p(int x){
 if(p[x]==x) return x;
 return p[x]=find_p(p[x]);
}
 
int main()
{
 
 int n,m,ans=0;
 scanf("%d %d",&n,&m);
 
 for(int i=1;i<=n;i++){
  scanf("%d",&t[i]);
  par[i]=i;
  endx[i]=i;
  p[i]=i;
 }
 
 srt[t[1]].push(1LL);
 int chk=1;
 for(int i=2;i<=n;i++){
  if(t[i]==t[i-1]){
   par[i]=i-1;
  }
  else{
   ans++;
   srt[t[i]].push(i);
   endx[chk]=i-1;
   chk=i;
  }
 }endx[chk]=n;
 
 while(m--){
  printf("%d\n",ans);
  if(!m) break;
 
  int id_a,id_b;
  scanf("%d %d",&id_a,&id_b);
 
  id_a=find_p(id_a);
  id_b=find_p(id_b);
 
  if(srt[id_a].size()<srt[id_b].size()){
   swap(id_a,id_b);
   p[id_b]=id_a;
  }
 
  while(!srt[id_b].empty()){
   int start=srt[id_b].front();
   srt[id_b].pop();
   int parent=find_par(start),ok=0;
   t[parent]=id_a;
   if(parent>1){
    int parent1=find_par(parent-1);
    if(t[parent1]==id_a){
     par[parent]=parent1,ans--;
     endx[parent1]=endx[parent];
     parent=parent1;
     ok=1;
    }
   }
 
   if(endx[parent]<n){
    int parent1=find_par(endx[parent]+1);
    if(t[parent1]==id_a){
     par[parent1]=parent,ans--;
     endx[parent]=endx[parent1];
     ok=1;
    }
   }
 
   if(!ok) srt[id_a].push(parent);
  }
 }
 
    return 0;
}