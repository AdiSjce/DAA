#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int c=0;
void bSort(int *a,int n)
{
	for(int i = 0;i<n-1;i++)
	{
		int ex=0;
		for(int j=0;j<n-1-i;j++)
		{
			c++;
			if(a[j+1]<a[j])
			{
				ex++;
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
		if(!ex) break;
	}
}
void writeCount(int n,FILE *fp)
{
	fprintf(fp,"%d\t%d\n",n,c);
	c=0;
}
void writeArr(int *a,int n,FILE *fp)
{	
	fprintf(fp,"Array : \n");
	for(int i = 0;i<n;i++)
		fprintf(fp,"%d\t",a[i]);
	fprintf(fp,"\n");
}
void recordCount(int *a,int n,FILE *f,FILE *fp)
{
	writeArr(a,n,f);
	bSort(a,n);
	writeCount(n,fp);
}
void main()
{
	FILE *f=fopen("BSArrayInfo.txt","w");
	FILE *fc=fopen("BSBest.txt","w");
	int *a;srand(time(0));
	fprintf(f,"\t\tBest Case \n");
	for(int n=10;n<=100;n+=10)
	{
		a=(int *)malloc(n*sizeof(int));
		a[0]=rand()%100;
		for(int i=1;i<n;i++)
			a[i]=a[i-1]+rand()%10;
		recordCount(a,n,f,fc);
	}
	fclose(fc);
	fc=fopen("BSAvg.txt","w");
	fprintf(f,"\t\tAverage Case \n");
	for(int n=10;n<=100;n+=10)
	{
		a=(int *)malloc(n*sizeof(int));
		for(int i=0;i<n;i++)
			a[i]=rand()%10;
		recordCount(a,n,f,fc);
	}
	fclose(fc);
	fc=fopen("BSWorst.txt","w");
	fprintf(f,"\t\tWorst Case \n");
	for(int n=10;n<=100;n+=10)
	{
		a=(int *)malloc(n*sizeof(int));
		a[n-1]=rand()%100;
		for(int i=n-1;i>0;i--)
			a[i-1]=a[i]+rand()%10;
		recordCount(a,n,f,fc);
	}
	fclose(fc);
	fclose(f);
	FILE *fg = fopen("BSplot.gnu","w");
fprintf(fg,"set xlabel \"n\"\nset ylabel \"t\"\nplot \"BSBest.txt\" w l ti \"Best Case\", \"BSWorst.txt\" w l smooth bezier ti \"Worst Case\", \"BSAvg.txt\" w l ti \"Average Case\"\nset term png\nset output \"BSG.png\"\nreplot\nset term x11");
fclose(fg);
system("gnuplot \"BSplot.gnu\"");
system("eog BSG.png");
}
