#include <stdio.h>
int main()
{
	int n,j,temp;
	printf("no of processes");
	scanf("%d",&n);
	int p[n],bt[n],wt[n],tat[n],i,pri[n];
	int tottat=0,totwt=0;
	float avgtat,avgwt;
	for(i=0;i<n;i++)
	{
		printf("burst time: ");
		scanf("%d",&bt[i]);
		printf("priority: ");
		scanf("%d",&pri[i]);
		p[i]=i;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(pri[j]>pri[j+1])
			{
				temp=pri[j];
				pri[j]=pri[j+1];
				pri[j+1]=temp;
				temp=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=temp;
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
				}
		}
	}
	for(i=0;i<n;i++)
	{
		if(i==0)
			tat[i]=bt[i];
		else
			tat[i]=tat[i-1]+bt[i];
		tottat+=tat[i];
		wt[i]=tat[i]-bt[i];
		totwt+=wt[i];
	}
	avgtat = (float)tottat/n;
	avgwt = (float)totwt/n;
	printf("pri\tprocess\tBT\tTAT\tWT\n");
	for(i=0;i<n;i++)
	{
		printf("%d \t %d \t %d \t %d \t %d \n",pri[i],p[i],bt[i],tat[i],wt[i]);
	}
	printf("avg tat: %f \n",avgtat);
	printf("avg wt: %f \n",avgwt);
	
}
	

