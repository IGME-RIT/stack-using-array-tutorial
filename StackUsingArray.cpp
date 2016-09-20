#include <memory>
#include <cassert>
#include <iostream>
#include <math.h>

using namespace std;

typedef struct {
	int* elems;
	int top = 0;
	int allocLength;
} Stack;

void createStack(Stack* s)
{
	s->top = 0;
	s->allocLength = 4;
	s->elems = (int*)malloc(sizeof(int) * 4);
	assert(s->elems != NULL);
}

void pushStack(Stack* s, int value)
{
	if (s->top == s->allocLength) {
		s->allocLength *= 2;
		s->elems = (int*)realloc(s->elems, s->allocLength* sizeof(int));
	//	Doubling strategy
	}
	s->elems[s->top] = value;
	s->top++;
}

int popStack(Stack* s)
{
	assert(s->top > 0);
	s->top--;
	return s->elems[s->top];
}

void deleteStack(Stack *s)
{
	free(s->elems);
	s->top = 0;
}

void printStack(Stack* s)
{
	for (int i = 0; i < s->top; i++)
	{
		cout << s->elems[i] << " ";
	}
	cout << endl;
}

int main() {
	Stack s;
	createStack(&s);

	for (int i = 0; i < 10; i++) {
		pushStack(&s, i);
	}

	printStack(&s);
	cout << "Pop: " << popStack(&s) << endl;
	printStack(&s);
	cout << "Pop: " << popStack(&s) << endl;
	printStack(&s);

	cout << "Stack disposed" << endl;
	deleteStack(&s);

	cout << "\nPress Enter to continue . . . ";
	cin.ignore();
	return 0;
}