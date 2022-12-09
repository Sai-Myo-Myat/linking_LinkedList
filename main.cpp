#include <iostream>

struct  node {
    float data;
    struct node *next;
    struct node *own;
};

struct node* takeMal(){
    struct  node* myNode = static_cast<node *>(malloc(sizeof(struct node)));
    return myNode;
}

void createNode(struct node *Node, float values[]){
    struct node *nodeList = static_cast<node *>(malloc(sizeof(struct node)));
    for (int i = 0; i < 5; ++i) {
        struct node* addNode = takeMal();
        addNode->data = values[i];
        if (i == 0){
            Node->own = addNode;
            nodeList = Node->own;
        }else  {
            nodeList->next = addNode;
            nodeList = nodeList->next;
        }
    }
}



struct node* searchNode(struct node *myNode, float dataToFind){
    struct node *nodeToReturn = takeMal();
    printf("%c",'\n');
    while (myNode != NULL){
        if (myNode->data == dataToFind){
            printf("WE found!!!!\n");
            nodeToReturn = myNode;
            return nodeToReturn;
        }
        struct node *ownNode = myNode->own;
        while (ownNode != NULL){
            if (ownNode->data == dataToFind){
                printf("We found it from sub-Node\n");
                nodeToReturn = ownNode;
                return nodeToReturn;
            }else{
                ownNode = ownNode->next;
            }
        }

        myNode = myNode->next;
    }
    return  nodeToReturn;
}

struct node* updateNode(struct node *myNode,float dataToBeUpdated,float dataToUpdate){
    struct node* result = searchNode(myNode,dataToBeUpdated);
    result->data = dataToUpdate;
    return myNode;
}

struct node*  deleteNode(struct node *myNode, float dataToDelete){
    struct node* result = searchNode(myNode,dataToDelete);
    result->data = ' ';
    return myNode;
}


void printEachLine(struct node *myNode, struct  node *nextNode){
    while (myNode != NULL){
        printf("%2lf",myNode->data);
        myNode = myNode->next;
    }
}

//float one,float two,float three,float four,float five
void printData(struct node *myNode){

//    struct node *copyNode = myNode;
//     for (int i = -1; i < 5; ++i) {
//         if (i == -1){
//             while (myNode !=NULL){
//                 if (myNode->data == 32){
//                     printf("%c\t\t\t ",myNode->data);
//                     myNode = myNode->next;
//                 }else {
//                     printf("%2lf   ",myNode->data);
//                     myNode = myNode->next;
//                 }
//             }
//             myNode = copyNode;
//         }else if (i==0){
//             printf("%c",'\n');
//            while (myNode !=NULL){
//                printf("%2lf   ",myNode->own->data);
//                myNode = myNode->next;
//            }
//            myNode = copyNode;
//        }else if (i == 1){
//            printf("%c",'\n');
//            while (myNode !=NULL){
//                printf("%2lf   ",myNode->own->next->data);
//                myNode = myNode->next;
//            }
//            myNode = copyNode;
//        }else if (i == 2){
//            printf("%c",'\n');
//            while (myNode !=NULL){
//                printf("%2lf   ",myNode->own->next->next->data);
//                myNode = myNode->next;
//            }
//            myNode = copyNode;
//        }else if (i == 3){
//            printf("%c",'\n');
//            while (myNode !=NULL){
//                printf("%2lf   ",myNode->own->next->next->next->data);
//                myNode = myNode->next;
//            }
//            myNode = copyNode;
//        }else if (i == 4){
//            printf("%c",'\n');
//            while (myNode !=NULL){
//                printf("%2lf   ",myNode->own->next->next->next->next->data);
//                myNode = myNode->next;
//            }
//        }
//    }
}

int main() {
    struct node *one = takeMal();
    struct node *two = takeMal();
    struct node *three = takeMal();
    struct node *four = takeMal();
    struct node *five = takeMal();

    one->data = 1;
    two->data = 2;
    three->data =3;
    four->data =4;
    five->data =5;

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = NULL;

    //1.1,1.2,1.3,1.4,1.5
    float valueOne[5] = {1.1,1.2,1.3,1.4,1.5};
    createNode(one,valueOne);
    float valueTwo[5] = {2.1,2.2,2.3,2.4,2.5};
    createNode(two,valueTwo);
    float valueThree[5] = {3.1,3.2,3.3,3.4,3.5};
    createNode(three,valueThree);
    float valueFour[5] = {4.1,4.2,4.3,4.4,4.5};
    createNode(four,valueFour);
    float valueFive[5] = {5.1,5.2,5.3,5.4,5.5};
    createNode(five,valueFive);



    printData(one);
    searchNode(one,1.5);
    updateNode(one,4.3,5);
    printf("after update%c",'\n');
    deleteNode(one,3);
    printf("after delete %c",'\n');
    printData(one);

    return  0;
}


//    struct node *nextNode;
//    struct node *currentNode;
//    struct node *addNode2 = static_cast<node *>(malloc(sizeof(struct node)));;
//    struct node *addNode3 = static_cast<node *>(malloc(sizeof(struct node)));;
//    struct node *addNode5 = static_cast<node *>(malloc(sizeof(struct node)));;
//    struct node *addNode6 = static_cast<node *>(malloc(sizeof(struct node)));;
//    addNode->data = value[0];
//    Node->own = addNode;
//    currentNode = Node->own;

//    for (int i = 1; i < 5; ++i) {
//        nextNode->data = value[i];
//        currentNode->next = nextNode;
//        currentNode = nextNode;
//    }
//    int i=1;
//    while (currentNode != NULL){
//        currentNode->data = value[i];
//        currentNode = currentNode->next;
//        i++;
//    }
/*
     struct node *nextNode = myNode;
    for (int i = 0; i < 5; ++i) {
        if (i == 0){
            nextNode = myNode->own;
        }
        printEachLine(myNode,nextNode);
        nextNode = nextNode->next;
    }

    void printEachLine(struct node *myNode, struct  node *nextNode){
    int count = 0;
    while (myNode != NULL){
        printf("%2lf   ",nextNode->data);
//        nextNode = nextNode->next;
        myNode = myNode->next;
        count++;
    }
    printf("%c",'\n');
}
 */

