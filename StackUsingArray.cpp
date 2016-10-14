/*
Title: Stack Using Array
File Name: StackUsingArray.cpp
Copyright © 2015
Written under the supervision of David I. Schwartz, Ph.D., and
supported by a professional development seed grant from the B. Thomas
Golisano College of Computing & Information Sciences
(https://www.rit.edu/gccis) at the Rochester Institute of Technology.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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