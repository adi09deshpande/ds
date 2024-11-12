#include<stdio.h>
#include<string.h>
#define size 8

struct job
{
    int jobId;
    char jobName[20];
};

struct job queue[size];
int front=-1,rear=-1;


void enqueue(int x,char n[])
{
    if(rear==size-1)
    {
        printf("\nQueue Full !! Overflow Condition !!");
    }
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear].jobId=x;
        strcpy(queue[rear].jobName,n);
        printf("\nJob Id %d(%s) inserted in the queue !!",x,n);
    }
    else{
        rear++;
        queue[rear].jobId=x;
        strcpy(queue[rear].jobName,n);
        printf("\nJob Id %d(%s) inserted in the queue !!",x,n);
    }
}

void dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("\nQueue Empty !! Underflow Condition");
    }
    else if(front==rear)
    {
        printf("\nThe job Id %d(%s) is removed from the queue",queue[front].jobId,queue[front].jobName);
        front=rear=-1;
    }
    else{
        printf("\nThe job Id %d(%s) is removed from the queue",queue[front].jobId,queue[front].jobName);
        front++;
    }
}

void display()
{
    if(front==-1 && rear==-1)
    {
        printf("\nThe queue is Empty !!");
    }
    else
    {
        printf("\nThe Jobs in the queue are: ");
        for(int i=front;i<=rear;i++)
        {
            printf("Job Id: %d,Job Name: %s ",queue[i].jobId,queue[i].jobName);
        }
    }
}

void displayCount()
{
    int count=0;
    if(front==-1 && rear==-1)
    {
        printf("\nThe number of jobs in the queue are 0");
    }
    else{
        for(int i=front;i<=rear;i++)
        {
            count++;
        }
        printf("\nThe number of jobs in the queue are: %d",count);
    }
}

void search()
{
    int searchJobId;
    if(front==-1 && rear==-1)
    {
        printf("\nQueue has no jobs !!");
    }
    else
    {
        int found=0;
        printf("Enter the JobId to be searched: ");
        scanf("%d",&searchJobId);
        for(int i=front;i<=rear;i++)
        {
            if(queue[i].jobId==searchJobId)
            {
                printf("\nThe Job Id is found at position %d in the queue",i+1);
                found=1;
                break;
            }
        }
        if(!found)
        {
            printf("Job Id not found !!");
        }
    }
}
int main()
{
    int jobId;
    char jobName[20];
    int ch;
    do
    {
        printf("\n------------------QUEUE OPERATIONS--------------------\n");
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4.Count\n5.Search\n6.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the Job Id to be inserted: ");
                scanf("%d",&jobId);
                printf("Enter the Job Name to be inserted: ");
                scanf("%s",jobName);
                enqueue(jobId,jobName);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                displayCount();
                break;
            case 5:
                search();
                break;
            case 6:
                return 0;
        }
    } while(ch!=6);
    return 0;
}