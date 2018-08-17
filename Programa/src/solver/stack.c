#include "stack.h"
#include <stdlib.h>
#include <stdio.h>


Stack *stack_init()
{
  Stack *stack = malloc(sizeof(Stack));
  stack->first_node = NULL;
  return stack;
}

Node *node_init(int color)
{
  Node *new_node = malloc(sizeof(Node));
  new_node->color = color;
  new_node->down_node = NULL;
  return new_node;
}

void push(Stack *stack, int color, int r, int c)
{
  /* Aqui agrega tu código */
  Node *new_node = node_init(color);
  new_node->down_node = stack->first_node;
  stack->first_node = new_node;
  // printf("PUSH (%d, %d): %d\n", r, c, color);
  //if (stack -> first_node-> down_node != NULL){
    //printf("Ahora el nodo cabeza en (%d, %d) es color: %d\n", r, c, (stack -> first_node)-> down_node-> color);
//}
}

int pop(Stack *stack)
{
  /* Aqui agrega tu código */
  int k;
  if (stack -> first_node == NULL) {
    // printf("esto había: %d \n", stack->first_node->color);
    //printf("vacioooo\n");
    k = -1;
    return k;
    }
  else {
    k = (stack -> first_node)-> color;
    Node *node_pop = stack -> first_node;
    //printf("Yo tengo este color %d y el que está debajo mio es %d \n",k,(stack -> first_node) -> down_node ->color );
    if ((stack -> first_node) -> down_node == NULL){
      // printf("soy el ultimo nodo del stack %d\n", k);
      stack -> first_node = NULL;
    //  printf("STACK me vacié ahora apunto a : %s\n", (stack -> first_node));
    }
    else {
      stack -> first_node = (stack -> first_node) -> down_node;
    }
    free(node_pop);
  }
  return k;
}

void destroy(Stack *stack)
{
  /* Aqui agrega tu código */
  int cond;
  cond = 1;
  while (cond) {
    int color_node;
    color_node = pop(stack);
    if (color_node == -1){
      cond = 0;
    }
  }
  free(stack);
}


/* A continuación puedes crear cualquier función adicional que ayude en la
  implementación de tu programa */
