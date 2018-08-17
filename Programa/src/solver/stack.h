#pragma once


typedef struct Stack Stack;

typedef struct Node Node;


struct Node
{
  /* Aqui agrega tu código */
  int color;
  Node *down_node;
};

struct Stack
{
  /* Aqui agrega tu código */
  Node *first_node;
};

Stack *stack_init();

void push(Stack *stack, int color, int r, int c);

int pop(Stack *stack);

void destroy(Stack *stack);
