#include<stdio.h>
int p[25][6],time=0,n,tat,twt;
int exe(int pid)
	{
		time+=p[pid][1];
		p[pid][2]=time;
		p[pid][3]=p[pid][2]-p[pid][0];
		p[pid][4]=p[pid][3]-p[pid][1];
		
		p[pid][1]=0;
		
		
		printf("\n Process: %d\n",pid+1);
		
	}
float avg_cal(int j)
	{
		int i=0;
		float s=0;
		while(i<n)
			{
				s=s+p[i][j];
				
				i++;
			}
			return s/n;
	}
void fcfs()
	{
		int c=0;
		while(c<n)
			{
				int a_low=10000,low;
				for(int i=0;i<n;i++)
					{
						
						if(p[i][0]<=time && p[i][5]!=1 && p[i][0]<a_low)
							{
								low=i;
								a_low=p[i][0];		
							}
					}
					if(a_low!=10000)
						{
							exe(low);
							c++;
							p[low][5]=1;
							
							continue;	
						}
					time++;			
				
			}
	}
int main()
	{printf("FCFS");
		printf("Enter the no. of Processes: ");
		scanf("%d",&n);
		
		for(int i=0;i<n;i++)
			{
				printf("Enter the Arrival Time & Burst Time of P%d: ",i+1);
				scanf("%d",&p[i][0]);
				scanf("%d",&p[i][1]);
				p[i][5]=0;
				
			}
		
		fcfs();
		
		printf("Avg TAT: %f,  Avg WT: %f",avg_cal(3),avg_cal(4));
		
	
	
	}
