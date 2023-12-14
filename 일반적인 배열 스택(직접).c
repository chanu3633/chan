#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef struct{
	int data[MAX_STACK_SIZE];
	int top;
}StackType;

init_stack(StackType *s){
	
	return (s -> top = -1);
	
}

int is_full(StackType *s){
	
	return (s -> top == (MAX_STACK_SIZE - 1));
	
}

int is_empty(StackType *s){
	
	return (s -> top == -1);
	
}

void push(StackType *s, int item){
	
	if(is_full(s)){
		fprintf(stderr, "스택 포화 에러");
		return;
	}
	else s->data[++(s->top)] = item;
	
}

int pop(StackType *s){
	
	if(is_empty(s)){
		fprintf(stderr, "스택공백에러");
		exit(1);
	}
	else return s->data[(s->top)--];
	
	
}

int main(void){
	
	StackType s;
	init_stack(&s);
	
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	
	return 0;;
	
}


