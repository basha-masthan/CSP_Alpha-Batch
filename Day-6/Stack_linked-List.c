#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

struct Stack
{
    struct Node *top;
};

void initializationStack(struct Stack *stack){
    stack->top = NULL;
}
int isEmpty(struct Stack *stack){
    return stack->top == NULL;
}

void Push(struct Stack *stack){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    int val;
    scanf("%d",&val);
    newnode->data = val;
    newnode->link=stack->top;
    stack->top=newnode;
}

void Pop(struct Stack *stack){
    if(isEmpty(stack)){
        printf("Stack Underflow");
    }
    else{
        struct Node *temp = stack->top;
    int pp = temp->data;
    stack->top=temp->link;
    free(temp);
    printf("%d\n",pp);
    }
}

void Peek(struct Stack *stack){
    if(isEmpty(stack)){
        printf("Stack Underflow");

    }
    printf("%d\n",stack->top->data); 
}

void Display(struct Stack *stack){

    if(isEmpty(stack)){
        printf("Stack Underflow");
    }
    int i;
    struct Node *temp = stack->top;
    while(temp!= NULL){
        printf("%d\n",temp->data);
        temp=temp->link;
    }
}

void main()
{
    struct Stack stack;
    initializationStack(&stack);
    int c;
    printf("\n\t Stack Operations \n\n 1.Push \n 2.Pop \n 3.Display \4. ...... \n 7.exit \n");
    while (1)
    {
        scanf("%d",&c);
        switch(c){
            case 1: Push(&stack);   break;
            case 2: Pop(&stack); break;
            case 3: Peek(&stack); break;
            case 4: Display(&stack); break;
            case 6:exit(0);
        }
    }
    
}*---
