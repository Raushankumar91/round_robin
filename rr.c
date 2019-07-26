#include<stdio.h>
#include<stdlib.h>
int t=0;
struct node
{
   int v;
   struct node *next;
}*root=NULL;
int main()
{
  //Initalizing values
 int pr_arr[]={2,0,4};//process arrival time
 int pr_exc[]={10,5,8};//process brust time
 int pr_x[100];
  
  //counting size
 int n=sizeof(pr_arr)/sizeof(pr_arr[0]);

 int queue[n+1],ua;
 printf("Enter the time quantum\n");
 scanf("%d",&ua);
 int i,j,k,u,p;
 //Sorting according to arrival time
for(i=0;i<n;i++)
 {
     pr_x[i]=pr_exc[i];
}
 for(i=0;i<n;i++)
 {
    queue[i]=i;
 }
 int waiting[n],completion[n];
 for(i=0;i<n;i++)
 {
    waiting[i]=-1;
 }
 for(i=0;i<n;i++)
 {
    for(j=i+1;j<n;j++)
    {
      if(pr_arr[i]>pr_arr[j])
      {
         u=queue[i];
         queue[i]=queue[j];
         queue[j]=u;
      }
    }
 }
 struct node *pa,*qa,*sa,*ia;
 for(i=0;i<n;i++)
 {
    pa=(struct node*)malloc(sizeof(struct node));
    pa->v=queue[i];
    pa->next!=NULL;
    if(root==NULL)
    {
       root=pa;
    }
    else
    {
        qa=root;
        while(qa->next!=NULL)
        {
            qa=qa->next;
        }
        qa->next=pa;
        qa=qa->next;
   }
 }
 qa->next=root;
 pa=root;
 int min,count=0;
 do
 {
   if(count==n)
   {
     count=0;
     min=pa->v;
     ia=pa;
     sa=pa;
     do
     {
       if(sa->v<min)
       {
           min=sa->v;
           ia=sa;
       }
       sa=sa->next;
     }while(sa!=pa);
     pa=sa;
     while(qa->next!=pa)
     {
         qa=qa->next;
     }
     t=pr_arr[pa->v];
     continue;
    }
   if(pr_arr[pa->v]<=t)
   {
     count=0;
     if(waiting[pa->v]==-1)
     {
        waiting[pa->v]=t-pr_arr[pa->v];
     }
     if(pr_exc[pa->v]>ua)
     {
        pr_exc[pa->v]=pr_exc[pa->v]-ua;
        t=t+ua;
        pa=pa->next;
        qa=qa->next;
     }
     else
     {
        t=t+pr_exc[pa->v];
        pr_exc[pa->v]=0;
        completion[pa->v]=t;
        if(pa!=qa)
        {
            qa->next=pa->next;
            pa=qa->next;
        }
        else
        {
            break;
        }
    }
  }
  else
   {
     count++;
     pa=pa->next;
     qa=qa->next;
   }
 }while(pa!=NULL);
 int turn[n];
 for(i=0;i<n;i++)
 {
     turn[i]=completion[i]-pr_arr[i];
 }
 for(i=0;i<n;i++)
 {
     //printf("Hello\n");
     waiting[i]=turn[i]-pr_x[i];
 }
 //printing values

   
 printf("\nThe wating time of each process is\n");
 for(i=0;i<n;i++)
 {
   printf("%d\t",waiting[i]);
 }
 printf("\n");
 printf("The turn around time is time of each process is\n");
 for(i=0;i<n;i++)
 {
   printf("%d\t",turn[i]);
 }
 printf("\n");
 printf("The completion time of each process is\n");
 for(i=0;i<n;i++)
 {
   printf("%d\t",completion[i]);
 }
 printf("\n");
}




















