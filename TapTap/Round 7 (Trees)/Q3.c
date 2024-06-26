// Binary Search Tree Implementaion:
// ===================================
#include <stdio.h>
#include <stdlib.h>
// Structure for a node in BST
struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into BST
struct Node* insert(struct Node* root, int data) 
{
    if (root == NULL) 
        return createNode(data);
    
    if (data < root->data) 
        root->left = insert(root->left, data);
    else if (data > root->data) 
        root->right = insert(root->right, data);
    
    return root;
}

// Function to find minimum value node in BST
struct Node* minValueNode(struct Node* node) 
{
    struct Node* temp = node;
    while (temp && temp->left != NULL) 
    {
        temp = temp->left;
    }
    return temp;
}

// Function to delete a node from BST
struct Node* deleteNode(struct Node* root, int data) 
{
    if (root == NULL) 
    {
        return root;
    }
    if (data < root->data) 
        root->left = deleteNode(root->left, data);
    else if (data > root->data) 
        root->right = deleteNode(root->right, data);
    else 
    {
        // Node with only one child or no child
        if (root->left == NULL) 
        {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } 
        else if (root->right == NULL) 
        {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to perform inorder traversal of BST and print the elements
void inorderTraversal(struct Node* root) 
{
    if (root != NULL) 
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to create BST with 'n' nodes
struct Node* createBST(int n) 
{
    struct Node* root = NULL;
    int i, data;
    printf("Enter %d integers to create BST:\n", n);
    for (i = 0; i < n; ++i) 
    {
        scanf("%d", &data);
        root = insert(root, data);
    }
    return root;
}

int main() 
{
    struct Node* root = NULL;
    int value;

    // Reading input values and performing operations on BST
    while (1) 
    {
        int choice;
        printf("\n1. Create\n2. Insert\n3. Delete\n4. Display\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            // case 1:  while (1) {
            //  scanf("%d", &value);
            //     if (value == -1) 
            //      main();
            // if (value > 0 && value < 1000) 
            //     root = insert(root, value);
            // break;
            //     }
            case 1: while (1)
            {
                scanf("%d", &value);
                if(value >0 && value < 1000) {insert(root, value);}
                if (value == -1) {main();}
                else
            }
                break;
            case 2:
                if (root == NULL)
                    printf("BST is empty.\n");
                else 
                {
                    printf("Enter integer to insert into the BST: ");
                    scanf("%d", &value);
                    if (value == -1) 
                        break;
                    if (value > 0 && value <= 1000)
                        insert(root, value); // Inserting value into the BST
                        //printf("Value inserted into BST.\n");
                    else 
                        printf("Invalid value!.\n");
                }
                break;
            case 3:
                printf("Enter integer to delete from the BST: ");
                scanf("%d", &value);
                if (value == -1) 
                    exit(0);
                root = deleteNode(root, value);
                printf("Value deleted from BST.\n");
                break;
            case 4:
                printf("BST elements: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid choice.\n");
        }
    }

    return 0;
}
