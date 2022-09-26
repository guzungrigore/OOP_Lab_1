// Queue implementation in C

#include <stdio.h>

int queue[], front = -1, rear = -1, LIMIT = -1;

void enQueue(int value) {
    if (front == -1)
        front = 0;
    int bool = 0;
    for (int i = front; i <= rear; i++) {
        if (value == queue[i]) {
            bool = 1;
        }
    }
    if (bool == 0) {
        rear++;
        queue[rear] = value;
        printf("\nInserted -> %d", value);
    } else {
        printf("Value already in the queue");
    }
}

void deQueue() {
    if (front == -1)
        printf("\nQueue is Empty!!");
    else {
        printf("\nDeleted : %d", queue[front]);
        front++;
        if (front > rear)
            front = rear = -1;
    }
}

// Function to print the queue
void display() {
    if (rear == -1)
        printf("\nQueue is Empty!!!");
    else {
        int i;
        printf("\nQueue elements are:\n");
        for (i = front; i <= rear; i++)
            printf("%d  ", queue[i]);
    }
    printf("\n");
}

void sort() {
    for (int i = front; i < rear; i++) {
        for (int j = i + 1; j <= rear; j++) {
            if (queue[i] > queue[j]) {
                int temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }
}

void search(int position) {
    if (position > rear || position < 1) {
        printf("\nThere is no such position in queue\n");
    } else {
        printf("\n%d\n", queue[position - 1 + front]);
    }
}

void reverse() {
    for (int i = front; i <= (rear + front) / 2; i++) {
        int temp = queue[i];
        queue[i] = queue[(rear + front) - i];
        queue[(rear + front) - i] = temp;
    }
}

void priorityQueue() {
    for (int i = front; i < rear; i++) {
        for (int j = i + 1; j <= rear; j++) {
            if (queue[i] < queue[j]) {
                int temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }
}

void enQueuePriority(int value) {
    if (front == -1) {
        front = 0;
    }
    int bool = 0;
    //int key;
    for (int i = front; i <= rear; i++) {
        if (value == queue[i]) {
            bool = 1;
        }
    }
    if (bool == 0) {
        rear++;
        queue[rear] = value;
        priorityQueue();
//            key = front;
//        } else if ( value < queue[rear]) {
//            rear++;
//            queue[rear] = value;
//            return;
//        } else {
//            for (int i = front; i < rear; i++) {
//                if (value > queue[i]) {
//                    key = i;
//                    break;
//                }
//            }
//        }
//        rear++;
//        for (int i = rear; i > key; i--) {
//            queue[i] = queue[i - 1];
//        }
//        queue[key] = value;
        printf("\nInserted -> %d", value);
    } else {
        printf("Value already in the queue");
    }
}

int isFull() {
    if ((front == rear + 1) || (front == 0 && rear == LIMIT - 1)) return 1;
    return 0;
}

int isEmpty() {
    if (front == -1) return 1;
    return 0;
}

void circularEnQueue(int value) {
    if (isFull())
        printf("\nQueue is full!! \n");
    else {
        for (int i = front; i != rear; i = (i + 1) % LIMIT) {
            if (value == queue[i]) {
                printf("Value already in the queue\n");
                return;
            }
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % LIMIT;
        queue[rear] = value;
        printf("\nInserted -> %d\n", value);
    }
}

int circularDeQueue() {
    int value;
    if (isEmpty()) {
        printf("\nQueue is empty !! \n");
        return (-1);
    } else {
        value = queue[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % LIMIT;
        }
        printf("\nDeleted element -> %d \n", value);
        return (value);
    }
}

void circularDisplay() {
    int i;
    if (isEmpty())
        printf(" \nEmpty Queue\n");
    else {
//        printf("\n Front -> %d ", front);
//        printf("\n Items -> ");
        for (i = front; i != rear; i = (i + 1) % LIMIT) {
            printf("%d ", queue[i]);
        }
        printf("%d ", queue[i]);
//        printf("\n Rear -> %d \n", rear);
    }
}

//void circularSearch(int position) {
//    if (isEmpty()) {
//        printf(" \n Empty Queue\n");
//    }
//    if (rear >= front && position -1 > rear) {
//        printf("\nThere is no such position in queue\n");
//    } else if (front > rear && position -1 > rear && position -1 < front) {
//        printf("\nThere is no such position in queue\n");
//    } else {
//        printf("%d\n", queue[(front + position) % LIMIT - 1]);
//    }
//}

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

void writeFile(char name[]) {
    char *filename = name;

    // open the file for writing
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening the file %s", filename);
    } else {
        printf("Insert your queue dividing them by a comma\n");
        // write to the text file
        char text[30];
        scanf("%s", text);
        //scanf("%[^\n]%*c", text);
        //fgets(text,30,stdin);
        //for (int i = 0; i < 10; i++)
        //fprintf(fp, "This is the line #%d\n", i + 1);
        fprintf(fp, "%s", text);
    }
    // close the file
    fclose(fp);
}

int main() {
    int action = -1, priority = 0, circular = 0;
    while (action) {
        printf("\nType 1 to queue an element\nType 2 to dequeue\nType 3 to search in queue\nType 4 to sort the queue"
               "\nType 5 to reverse the queue\nType 6 to transform into a Priority Queue\nType 7 to transform into a Circular Queue"
               "\nType 8 to export a file\nType 9 display a file\nType 0 to Exit the program\n");
        scanf("%d", &action);
        if (action == 1) {
            printf("Type the value to Queue:\n");
            int value;
            scanf("%d", &value);
            enQueue(value);
            display();
        } else if (action == 2) {
            deQueue();
            display();
        } else if (action == 3) {
            printf("Type the position to display\n");
            int position;
            scanf("%d", &position);
            search(position);
        } else if (action == 4) {
            sort();
            display();
        } else if (action == 5) {
            reverse();
            display();
        } else if (action == 6) {
            priority = 1;
            priorityQueue();
            display();
            while (priority == 1) {
                printf("Type 1 to EnQueue\nType 2 DeQueue\nType 3 to search in queue\nType 9 to return to normal queue\nType 0 to Exit the program\n");
                int actionPriority = -1;
                scanf("%d", &actionPriority);
                if (actionPriority == 1) {
                    printf("Type the value to Queue:\n");
                    int value;
                    scanf("%d", &value);
                    enQueuePriority(value);
                    display();
                } else if (actionPriority == 2) {
                    deQueue();
                    display();
                } else if (actionPriority == 3) {
                    printf("Type the position to display\n");
                    int position;
                    scanf("%d", &position);
                    search(position);
                } else if (actionPriority == 9) {
                    priority = 0;
                } else if (actionPriority == 0) {
                    printf("The program was terminated\n");
                    return 0;
                } else {
                    printf("Invalid Value\n");
                }
            }
        } else if (action == 7) {
            circular = 1;
            printf("Type the limit of the queue\n");
            scanf("%d", &LIMIT);
            while (circular == 1) {
                printf("\nType 1 to EnQueue\nType 2 DeQueue\nType 9 to return to normal queue\nType 0 to Exit the program\n");
                int actionCircular = -1;
                scanf("%d", &actionCircular);
                if (actionCircular == 1) {
                    printf("Type the value to Queue:\n");
                    int value;
                    scanf("%d", &value);
                    circularEnQueue(value);
                    circularDisplay();
                } else if (actionCircular == 2) {
                    circularDeQueue();
                    circularDisplay();
//                } else if (actionCircular == 3) {
//                    printf("Type the position to display\n");
//                    int position;
//                    scanf("%d", &position);
//                    circularSearch(position);
                } else if (actionCircular == 9) {
                    circular = 0;
                } else if (actionCircular == 0) {
                    printf("The program was terminated\n");
                    return 0;
                } else {
                    printf("Invalid Value\n");
                }
            }
        } else if (action == 8) {
            printf("Type the name of the file\n");
            char file[20];
            scanf("%s", file);
            displayFile(file);
        } else if (action == 9) {
            printf("Give a name to the file:\n");
            char name[20];
            scanf("%s", name);
            writeFile(name);
        } else if (action == 0) {
            printf("The program was terminated\n");
            return 0;
        } else {
            printf("Invalid value\n");
        }
    }
}
