// Tree traversal in C

#include <stdio.h>
#include <stdlib.h>

struct node {
    int item;
    struct node *left;
    struct node *right;
};

struct node *newNode(int item) {
    struct node *temp
            = (struct node *) malloc(sizeof(struct node));
    temp->item = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Inorder traversal
void inorderTraversal(struct node *root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d,", root->item);
    inorderTraversal(root->right);
}

// Preorder traversal
void preorderTraversal(struct node *root) {
    if (root == NULL) return;
    printf("%d,", root->item);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Postorder traversal
void postorderTraversal(struct node *root) {
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d,", root->item);
}

// Create a new Node
struct node *createNode(int value) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->item = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct node *insert(struct node *node, int key) {

    if (node == NULL)
        return newNode(key);

    if (key < node->item)
        node->left = insert(node->left, key);
    else if (key > node->item)
        node->right = insert(node->right, key);

    return node;
}

struct node* minValueNode(struct node* node)
{
    struct node* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

struct node* deleteNode(struct node* root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->item)
        root->left = deleteNode(root->left, key);

    else if (key > root->item)
        root->right = deleteNode(root->right, key);

    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minValueNode(root->right);

        root->item = temp->item;

        root->right = deleteNode(root->right, temp->item);
    }
    return root;
}

void displayFile(char file[]) {
    FILE *ptr;
    char ch;

    // Opening file in reading mode
    ptr = fopen(file, "r");

    if (NULL == ptr) {
        printf("\nfile can't be opened \n");
    } else {
        printf("content of this file are \n");
    }

    // Printing what is written in file
    // character by character using loop.
    while (ch != EOF) {
        ch = fgetc(ptr);
        printf("%c", ch);
    }
    // Closing the file
    fclose(ptr);
}

void writeFile(char name[]){
    char *filename = name;

    // open the file for writing
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Error opening the file %s", filename);
    } else {
        printf("Insert your tree dividing them by a comma\n");
        // write to the text file
        char text[30];
        scanf("%s",text);
        //scanf("%[^\n]%*c", text);
        //fgets(text,30,stdin);
        //for (int i = 0; i < 10; i++)
            //fprintf(fp, "This is the line #%d\n", i + 1);
        fprintf(fp,"%s",text);
    }
    // close the file
    fclose(fp);
}


int main() {
    printf("Add the root of the binary tree:\n");
    int rot;
    scanf("%d",&rot);
    struct node *root = createNode(rot);

    int n = -1;
    while(n) {
        printf("\n___________________________________________________\n"
               "Type 1 to add an element\nType 2 to delete an element\n"
               "Type 3 to display the tree in Inorder traversal\n"
               "Type 4 to display the tree in Preorder traversal\n"
               "Type 5 to display the tree in Postorder traversal\n"
               "Type 6 to load a tree from a file and display it in terminal\n"
               "Type 7 to input the a tree and save it to a file\n"
               "Type 0 to exit the program\n");
        scanf("%d", &n);
        if (n == 1){
            printf("Type a number to insert\n");
            int x;
            scanf("%d",&x);
            insert(root,x);
        } else if (n == 2) {
            printf("Type the number to delete:\n");
            int x;
            scanf("%d", &x);
            deleteNode(root, x);
        } else if (n == 3) {
            printf("Inorder traversal \n");
            inorderTraversal(root);
        } else if (n == 4) {
            printf("Preorder traversal \n");
            preorderTraversal(root);
        } else if (n == 5) {
            printf("Postorder traversal \n");
            postorderTraversal(root);
        } else if (n == 6) {
            printf("Type the name of the file\n");
            char file[20];
            scanf("%s", file);
            displayFile(file);
        } else if (n == 7) {
            printf("Give a name to the file:\n");
            char name[20];
            scanf("%s", name);
            writeFile(name);
        } else if (n == 0){
            printf("Program exited\n");
            return 0;
        } else {
            printf("Invalid value\n");
        }

    }

}
