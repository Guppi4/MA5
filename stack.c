#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include <unistd.h>
#include <sys/mman.h>

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#define S 1024 * 30
struct stack_tag
{
    char data[S];
    int tos;
};

static void fatal_error(const char *errmsg)
{
    fprintf(stderr, "%s\n", errmsg);
    exit(1);
}

stack stack_create()
{
    stack s = (stack)malloc(sizeof(struct stack_tag));
    if (s == NULL)
        fatal_error("out of space");
    s->tos = -1;
}

void stack_destroy(stack *sptr)
{
    if (*sptr != NULL)
        free(*sptr);
    *sptr = NULL;
}

element_type stack_top(stack s)
{
    if (s->tos == 0)
    {
        return "Empty";
    };
    int i;
    for (i = (s->tos) - 2; s->data[i] != '\0'; i--);//return to begin of top string 
      i++;
    
    
    char* top = (char*)malloc(sizeof(char)*1024);
    strcpy(top, &(s->data[i]));
    return top;
}

element_type stack_pop(stack s)
{
     if(s->data == 0){
        perror("Error! stack is empty");
    }
    int i;
    for (i = (s->tos) - 2; s->data[i] != '\0'; i--){
        s->tos--;
    }//return to begin of top string 
     char* pop = (char*)malloc(sizeof(char)*1024);
    strcpy(pop, &(s->data[i]));
    return pop;
}

void stack_push(stack s, element_type e)
{
    for (int i = 0; i < strlen(e); i++)
    {

        s->tos++;
        s->data[s->tos] = e[i];
    }
    s->data[s->tos++] = '\0';
    printf("%s pushed to stack\n", e);
}

int stack_size(stack s)
{
    return s->tos + 1;
}

int stack_is_empty(stack s)
{
    return s->tos == -1;
}