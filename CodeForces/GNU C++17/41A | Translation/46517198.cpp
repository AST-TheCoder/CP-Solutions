#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    char A[105],B[105],C[105];
    int i,l,j=0;
    scanf("%s",&A);
    scanf("%s",&B);
    l=strlen(B);
    for(i=l-1;i>=0;i--)
    {
 
 
        C[j]=B[i];
        j++;
 
 
    }
    C[l]='\0';
    if(strcmp(A,C)==0)
    {
        printf("YES");
    }
   else printf("NO");
return 0;
}