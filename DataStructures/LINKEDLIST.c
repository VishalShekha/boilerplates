#include<stdio.h>
#include<stdlib.h>

typedef struct ll{
    int ele;
    struct ll* next;
} list;

void addLast(list* header, list* newNode){
    list* currNode = header;
    while(currNode->next != NULL){
        currNode = currNode->next;
    }
    currNode->next = newNode;
}

void deleteFirst(list* header){
    if(header->next == NULL){
        printf("List is empty\n");
        return;
    }
    list* temp = header->next;
    header->next = temp->next;
    printf("%d removed from the list\n", temp->ele);
    free(temp);
}

void peekFirst(list* header){
    if(header->next == NULL){
        printf("List is empty\n");
    }else{
        printf("First element is %d\n", header->next->ele);
    }
}

void printList(list* header){
    if(header->next == NULL){
        printf("List is empty\n");
    }else{
        list* currNode = header->next;
        while(currNode != NULL){
            printf("%d -> ", currNode->ele);
            currNode = currNode->next;
        }
        printf("NULL\n");
    }
}

list* Find(list* header, int e){
    list* currNode = header->next;
    while(currNode != NULL){
        if(currNode->ele == e)
            return currNode;
        currNode = currNode->next;
    }
    return NULL;
}

int main(){
    int n;
    printf("Enter the number of elements to add initially: ");
    scanf("%d", &n);

    list* header = (list*)malloc(sizeof(list));
    header->next = NULL;

    for(int i = 0; i < n; i++){
        int x;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &x);
        list* newNode = (list*)malloc(sizeof(list));
        newNode->ele = x;
        newNode->next = NULL;
        addLast(header, newNode);
    }

    while(1){
        printf("\nEnter the operation to be done\n1.Add Element\n2.Delete First Element\n3.Peek First Element\n4.Print List\n5.Find Element\n6.Exit\n: ");
        int op;
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Enter the element to be added: ");
            int x;
            scanf("%d", &x);
            list* newNode = (list*)malloc(sizeof(list)); 
            newNode->ele = x;
            newNode->next = NULL;
            addLast(header, newNode);
            break;
        
        case 2:
            deleteFirst(header);
            break;

        case 3:
            peekFirst(header);
            break;

        case 4:
            printList(header);
            break;

        case 5:
            printf("Enter the element to find: ");
            int e;
            scanf("%d", &e);
            list* found = Find(header, e);
            if(found != NULL)
                printf("Element %d found.\n", e);
            else
                printf("Element %d not found.\n", e);
            break;

        case 6:
            return 0;

        default:
            printf("Enter a valid number: ");
            break;
        }
    }

    return 0;
}
