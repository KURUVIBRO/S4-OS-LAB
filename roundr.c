#include<stdio.h>
int p[25][7],n,time=0,q=1,c=0;
void exe(int pid)
	{
		if(p[pid][1]>q)
			{
				time+=q;
				p[pid][1]-=q;
				//printf(" qBurst: %d, C exe: %d ",p[pid][1],c);
			}
		else
			{
				time+=p[pid][1];
				p[pid][1]=0;
				p[pid][5]=1;
				c++;
				p[pid][2]=time;
				p[pid][3]=p[pid][2]-p[pid][0];
				p[pid][4]=p[pid][3]-p[pid][6];
			}
		
		printf("\n Process:%d\n",pid+1);
	}
void roundr()
	{
		int flag;
		while(c<n)
			{
				flag=0;
				for(int i=0;i<n;i++)
					{
						if(p[i][0]<=time && p[i][5]==0)
							{
								
								flag=1;
								exe(i);
								
							}						
					}
				if(flag==0)
					time++;
			}
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
int main()
	{printf("RoRo");
		printf("Enter the no. of Processes: ");
		scanf("%d",&n);
		
		for(int i=0;i<n;i++)
			{
				printf("Enter the Arrival Time & Burst Time of P%d: ",i+1);
				scanf("%d",&p[i][0]);
				scanf("%d",&p[i][1]);
				p[i][5]=0;
				p[i][6]=p[i][1];
			}
		
		
		
		/*p[0][0]=8;
		p[0][1]=5;
		burst[0]=p[0][1];
		p[1][0]=1;
		p[1][1]=7;
		burst[1]=p[1][1];
		p[2][0]=1;
		p[2][1]=8;
		burst[2]=p[2][1];*/
		roundr();
		printf("Avg TAT: %f,  Avg WT: %f",avg_cal(6),avg_cal(4));
		
	}
