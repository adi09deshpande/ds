#include<stdio.h>
#define size 8

int queue[size]; //char queue[size][20]; in case of strings
int front=-1,rear=-1;


void enqueue(int x) //char x[] in case of strings
{
    if(rear==size-1)
    {
        printf("\nQueue Full !! Overflow Condition !!");
    }
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=x; //strcpy(queue[rear],x); in case of strings
        printf("\nJob Id %d inserted in the queue !!",x);
    }
    else{
        rear++;
        queue[rear]=x; //strcpy(queue[rear],x); in case of strings
        printf("\nJob Id %d inserted in the queue !!",x);
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
        printf("\nThe job Id %d is removed from the queue",queue[front]);
        front=rear=-1;
    }
    else{
        printf("\nThe job Id %d is removed from the queue",queue[front]);
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
            printf("%d ",queue[i]);
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
            if(queue[i]==searchJobId)
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
                enqueue(jobId);
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