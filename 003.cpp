#include<stdio.h>
int main()
{
	int a[5][5],i,j,s1,y,p;
	for(j=0;j<5;j++)
	{
		for(i=0;i<5;i++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(j=0;j<5;j++)
	{
		p=0;
		s1=0;
		for(i=0;i<5;i++)
		{
			if(a[i][j]<a[s1][j])
				s1=i;
		}
		for(y=0;y<5;y++)
		{
			if(a[s1][j]<a[s1][y])
				break;
			if(y==4)
				printf("%d %d %d\n",j+1,s1+1,a[s1][j]);
		}  
	}
        printf("hello");
	return 0;
}
			   


