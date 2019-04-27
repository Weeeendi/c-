#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdio.h>
int main()
{
	int n;
	int flag;
	printf("please input the number of n!\n");
   scanf("%d%*c",&n);
   char b[50];
   while(n--)
   {
	   flag=1;
	   printf("please input the string %d!\n",n+1);
	   gets(b);
	   int len=strlen(b);
	   if(!((b[0]>='a'&&b[0]<='z')||(b[0]>='A'&&b[0]<='Z')||b[0]=='_'))
		  {  flag=0;
	   }
	   else{
	        for(int i=1;i<len;i++)
	      {
		   if(!((b[i]>='a'&&b[i]<='z')||(b[i]>='A'&&b[i]<='Z')||(b[i]=='_')||(b[i]>='0'&&b[i]<='9')))
			  { flag=0;
		       break;
		      }
	      }
	   }
	  if(flag)
		  printf("YES\n");
	  else
		  printf("NO\n");
   }
  return 0;
}