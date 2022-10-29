#include <stdio.h>
int main()
{
	int n,rnop,ts,gtime=0;
	
	printf("no of processes");
	scanf("%d",&n);
	rnop=n;
	int p[n],bt[n],wt[n],tat[n],i,remain[n];	
	int tottat=0,totwt=0;
	float avgtat,avgwt;
	printf("time slice: ");
	scanf("%d",&ts);
	printf("burst time: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&bt[i]);
		p[i]=i;
		remain[i]=bt[i];
	}
	for(i= 0;rnop!=0;i=(i+1)%n)
	{
		if((remain[i]<=ts)&&(remain[i]>0))
		{
			gtime+=remain[i];
			remain[i]=0;
			rnop--;
			tat[i]=gtime;
			wt[i]=tat[i]-bt[i];
			tottat+=tat[i];
			totwt+=wt[i];
		}
		else if(remain[i]>0){
			  gtime+=ts;
			  remain[i]-=ts;
		  }
	  }
	avgtat = (float)tottat/n;
	avgwt = (float)totwt/n;
	printf("process\tBT\tTAT\tWT\n");
	for(i=0;i<n;i++)
	{
		printf("%d \t %d \t %d \t %d \n",p[i],bt[i],tat[i],wt[i]);
	}
	printf("avg tat: %f \n",avgtat);
	printf("avg wt: %f \n",avgwt);
	
}
	
