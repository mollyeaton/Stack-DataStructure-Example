#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.maeaton.h"


int stackPush(StackNode **stack, char *name, int value){
    //create a temporary node to hold all of the info
    StackNode *temp = (StackNode*)malloc(sizeof(StackNode));
    //if the stack is currently empty then set the next value to NULL
    if (*stack == NULL) {
        //assign values for the node
        temp -> value = value;
        strcpy(temp -> name, name);
        temp -> next = NULL;
        //have the stack object be the temporary node
        *stack = temp;
    }
    //if the stack is not empty then link the list and store the new values
    else {
        //assign values for the node
        temp -> value = value;
        strcpy(temp -> name, name);
        temp -> next = *stack; //have the node point to the previous stack object
        //update the stack
        *stack = temp;
    }
    return 0;
}

StackNode *stackPop(StackNode **stack) {
    //create a temporary node to hold all of the info
    StackNode *temp = *stack;
    //if the stack is not empty then pop a node
    if (*stack != NULL) {
        //update the stack so it is beginning at the next node
        *stack = (*stack) -> next;
        temp -> next = NULL; //have the previous top reference NULL so it's not connected anymore
        return temp; //return the previous head
    }
    //if the stack is empty just return NULL
    else {
        return NULL;
    }
}

StackNode *stackRemoveBottomNode(StackNode **stack) {
    //create a temporary node to hold all of the info and a node for returning
    StackNode *temp;
    StackNode *returnNode;
    //if the stack is not empty then find the bottom node
    if (*stack != NULL) {
        //test case if there is only one element in the list
        if ((*stack) -> next == NULL) {
            //remove the element by making the stack NULL
            temp = *stack;
            *stack = NULL;
            return temp;
        }
        //test case if there are only 2 elements in the list
        if ((*stack) -> next -> next == NULL) {
            //have temp start at the second node
            temp = (*stack) -> next;
            //remove the second node
            (*stack) -> next = NULL;
            return temp; //return the previous tail
        }
        //have temp reference the original stack
        temp = *stack;
        //loop through the list until the 'next next' value is NULL
        //this will have make the resulting node the second to last in the stack
        while ((temp) -> next -> next != NULL) {
            temp = temp -> next;
        }
        //make the return node reference the tail
        returnNode = (temp) -> next ;
        //remove the bottom node
        temp -> next = NULL;

        return returnNode; //return the previous tail
    }
    //if the stack is empty just return NULL
    else {
        return NULL;
    }

}

int stackPrint(StackNode *stack) {
    //If the stack is empty print out accordingly
    if (stack == NULL) {
        printf("(stack is empty)");
        return 0;
    }
    //if the stack is not empty have the temp node reference the stack
    StackNode *temp = stack;
    //loop through the stack to print the values
    while ((temp -> next != NULL) ) {
        printf("|%s| %d\n", temp->name, temp->value);
        temp = temp->next;
    }
    //print the values for the final node
    printf("|%s| %d\n", temp->name, temp->value);

    return 0;
}


