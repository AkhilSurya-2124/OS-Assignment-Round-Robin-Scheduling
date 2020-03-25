#include<stdio.h>
int main()
{
	int et=0;
	int n,q;
	int over =0;//n is number of processes, et is executed time , q is time quantum
	printf("Enter number of processes: ");
	scanf("%d",&n);
	int a[n];
	int b[n];
	int process_turnaround[n];
	int process_wait[n];
	int i=0;
	int wait=0,turnaround=0;//wait is waiting time and turnaround is turnaround time
	int burst[n];
	for ( i=0;i<n;i++)
	{
		printf("Enter arrival time of process %d :\t",i+1);
		scanf("%d",&a[i]);
		printf("Enter burst time of process %d :\t",i+1);
		scanf("%d",&b[i]);
		burst[i]=b[i];//copying because we need to do furthur calculations
	}
	printf("Enter time quantum:\t");
	scanf("%d",&q);
	int rem;//remaining processes
	i=0;
	rem=n;
	printf("Order of executing :\n");
	while(rem>0)//loop until all the processes are executed
	{over=0;
	if (a[i]>et){
		i++;
		//printf("Executing %d now\n",i);
	}
	else{
		if (a[i]<=et && b[i]>0 && (b[i]-q)>0)
		{
			//printf("%d executed for %d now\n",i,q);
			et=q+et;
			b[i]=b[i]-q;
			//printf("CURRENT TIME  %d\n",et);
			printf("P[%d]\t",i+1);
		}
		else if (a[i]<=et && b[i]>0 && (b[i]-q)<=0)
		{
			//printf("%d executed for %d now\n",i,b[i]);
			et=et+b[i];
			b[i]=0;
			over =1;
			printf("P[%d]\t",i+1);
			//printf("current time: %d\n process %d is over",et,i);
		}
		if (b[i]==0 && over==1)
		{rem--;//decrease remaining processes by 1
			wait=wait+et-burst[i]-a[i];
			turnaround=turnaround+et-a[i];				
			//printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d\n", i, burst[i], et-burst[i]-a[i], et-a[i]);//turnound,wait
			process_wait[i]=et-burst[i]-a[i];
			process_turnaround[i]=process_wait[i]+burst[i];
			//printf("P[%d]\t",i+1);//for printing the order of process completion
		}
		if (i==n-1)
		{
			i=0;
		}
		else 
		{
			i++;
		}
		}
}
printf("\nProcess\t\tBurst Time\t\tWaiting Time\t\tTurnaround Time\n");

for (i=0;i<n;i++)
{
	printf("P[%d]\t\t   %d\t\t\t   %d\t\t\t     %d\n",i+1,burst[i],process_wait[i],process_turnaround[i]);
}
	float average_wait_time ;
	average_wait_time= wait*1.0/n;
    float average_turnaround_time ;
	average_turnaround_time= turnaround*1.0/n;
      printf("Average Waiting Time: %f\n", average_wait_time);
      printf("/nAvg Turnaround Time: %f", average_turnaround_time);
      return 0;
}
