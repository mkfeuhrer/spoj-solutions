//spoj solutions/GIRLSNBS
//Mohit Khare Mnnit
#include<stdio.h>
int main()
{
	int g,b;
	while(scanf("%d %d",&g,&b))
	{
		int ans=0;
		if((g==-1)&&(b==-1))
		break;
		if(g>b)
		{
		if(g%(b+1)==0)
			ans=g/(b+1);
		else ans=(g/(b+1))+1;
		printf("%d\n",ans);
		}
		if(g<b)
		{
		if(b%(g+1)==0)
			ans=b/(g+1);
		else ans=(b/(g+1))+1;
		printf("%d\n",ans);
		}
		if(b==g && b!=0) printf("1\n");
		if(b==0 && g==0)
		printf("0\n");
		
	}
}
