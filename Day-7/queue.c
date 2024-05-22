#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int Q[MAX],rear=-1,front=-1,i;

void inqueue()
{
    int val;
   // printf("Ente a Value:");
    scanf("%d",&val);
    if(rear==MAX-1)
        printf(" Queue is Epty\n");
    rear++;
    Q[rear]=val;
    if(front==-1)
        front=rear=0;
}

void dequeue(){
    int temp;
    if(front==-1)
        printf("Queue is Epty");
    else{
        temp = Q[front];
        front++;
        if(front==rear)
            front=rear=-1;
    }
    printf("%d",temp);
    printf("\n");
}

void display(){
    if(front==-1)
        printf("Queue is Epty");
    for(i=front;i<=rear;i++)
        printf("%d ",Q[i]);
    printf("\n");
}

void getfront(){
    printf("%d",Q[front]);
}
void getrear(){
    printf("%d",Q[rear]);
}
void isempty(){
    if(front==-1)
        printf("Queue is Empty");
}
void isfull(){
    if(Q[rear==MAX-1])
        printf("Queue is Full");
}


void main(){
    int ch;
    while(1){
       // printf("\n Main Menu \n 1.EnQueue \n 2.DeQueue \n 3.Display \n 4.Exit \n\n Enter an option:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1: inqueue();  break;
        case 2: dequeue();  break;
        case 3: display();  break;
        case 4: getfront(); break;
        case 5: getrear();  break;
        case 6: 
             isempty(); break;
        case 7: isfull();   break;
        case 8: exit(0);
        default:
            break;
        }
    }
}