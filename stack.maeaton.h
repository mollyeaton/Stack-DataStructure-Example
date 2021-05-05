#ifndef ASSIGNMENT02_STACK_MAEATON_H
#define ASSIGNMENT02_STACK_MAEATON_H

//define the maximum length for the name
#define MAX_NAME_LENGTH 32

//create a struct to hold the information within each node
typedef struct StackNodeStruct {
    char name[MAX_NAME_LENGTH];
    int value;
    struct StackNodeStruct *next;
} StackNode;

//Requires: the stack object and the name, value for the new node
//Modifies: the stack object
//Effects: creates a new node based on parameters and adds it to the stack
int stackPush(StackNode **stack, char *name, int value);

//Requires: the stack object
//Modifies: the stack object
//Effects: removes and returns the top node from the stack
StackNode *stackPop(StackNode **stack);

//Requires: the stack object
//Modifies: the stack object
//Effects: removes and returns the bottom node from the stack
StackNode *stackRemoveBottomNode(StackNode **stack);

//Requires: the stack object
//Modifies: nothing
//Effects: loops through and prints the information contained within the stack
int stackPrint(StackNode *stack);


#endif //ASSIGNMENT02_STACK_MAEATON_H
