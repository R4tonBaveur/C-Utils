#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

struct stack* push(struct stack *Stack,void *value){
	struct stack* new = new_stack();
	new->next = malloc(sizeof(struct stack));
	new->next->data = value;
	new->next->next = Stack->next;
	Stack = new;
	return Stack;
};
struct stack* pop(struct stack* Stack){
	struct stack* res = Stack->next;
	if(Stack->next!=NULL && Stack->next->next != NULL){
		Stack->next = Stack->next->next;
	}
	return res;

}
struct stack* new_stack(){
	/*
	 * Returns a pointer to a new empty queue
	 * */
	struct stack *Stack = malloc(sizeof(struct stack));
	Stack->data = NULL;
	return Stack;
};
void print_stack(struct stack *Stack,void (*print)(void*)){
	/*
	 * Prints the queue
	 * Param: Queue-> Queue to print
	 * Param: print-> function to print an element of the type contained by the queue
	 * */
	printf("Stack: [");
	struct stack* tmp = Stack;
	Stack = Stack->next;
	while(Stack!=NULL && Stack->next!=NULL){
		print(Stack->data);
		printf("\n, ");
		Stack = Stack->next;
	}
	if(Stack!=NULL){
		print(Stack->data);
	}
	printf("]\n");
	Stack = tmp;
}
void print_int(void *val){
	int *p = val
	printf("%d",*p);
}

int main(){
	struct stack* S = new_stack();
	int i=1;
	push(S,&i);
	print_stack(S,print_int);
	return 0;
}
