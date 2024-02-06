#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ExampleStruct {
    int someInt;
    char* someString;
    struct ExampleStruct* prev;
};

int main() {
    // Create an instance of the struct
    struct ExampleStruct myStruct;
    struct ExampleStruct myStruct2;
    myStruct.someInt = 8888;
    // Assume you have a string of unknown size
    char unknownString[] = "Hello, World!";

    // Determine the length of the string
    size_t stringLength = strlen(unknownString);

    // Allocate memory for the string
    myStruct.someString = (char*)malloc((stringLength + 1) * sizeof(char));  // +1 for null terminator

    // Copy the string into the allocated memory
    strcpy(myStruct.someString, unknownString);

    // Access and print values
    printf("Integer: %d\n", myStruct.someInt);
    printf("String: %s\n", myStruct.someString);
myStruct2.prev = &myStruct;
printf("test: %s\n", myStruct2.prev->someString);
    // Don't forget to free the allocated memory
    free(myStruct.someString);

    return 0;
}

/*
int main(int argc, char *argv[])
{
  int initial_range;
  int jump_range;
  int num_jumps;
  int initial_power;
  double power_reduction;
  char in_name[1024];
  int x_in, y_in, curr_pp_in, max_pp_in;
  int num_nodes = 0;
  // notes
  //  char *string = (char *)malloc(100);
  //  allocate array of 4 ints
  // int *arr = (int *)malloc(4 * sizeof(int));
  sscanf(argv[1], "%d", &initial_range);
  sscanf(argv[2], "%d", &jump_range);
  sscanf(argv[3], "%d", &num_jumps);
  sscanf(argv[4], "%d", &initial_power);
  sscanf(argv[5], "%lf", &power_reduction);
  printf("initial_range: %d \njump_range: %d \nnum_jumps: %d \ninitial_power %d \npower_reduction %lf \n ", initial_range, jump_range, num_jumps, initial_power, power_reduction);
  // Node *all_nodes = malloc(sizeof(Node));
  Node *all_nodes = NULL;
  Node *prev_node = NULL;
  int index = 0;
  for(int i =0 ; i < 1; i++){
    char* test = "please work";
  }
  while (scanf("%i %i %i %i %s", &x_in, &y_in, &curr_pp_in, &max_pp_in, in_name) == 5)
  {
    ++num_nodes;
    all_nodes = realloc(all_nodes, num_nodes * sizeof(Node));

    printf("X: %d, Y: %d, Curr_pp: %d, max_pp: %d, name: %s \n", all_nodes[index].x, all_nodes[index].y, all_nodes[index].curr_PP, all_nodes[index].max_PP, all_nodes[index].name);
    // all_nodes[index].name = malloc(strlen(in_name) + 1);
    // strcpy(all_nodes[index].name, in_name);
    // char *name_p = in_name;
    // printf("%s\n", &name_p);
    //all_nodes[index].name = strdup(in_name);
    all_nodes[index].x = x_in;
    //all_nodes[index].y = y_in;
    //all_nodes[index].curr_PP = curr_pp_in;
    //all_nodes[index].max_PP = max_pp_in;

    // printf( "%s\n", all_nodes[index].name);

    all_nodes[index].prev = prev_node;

    if (index != 0 && all_nodes[index].prev != NULL)
    {
      printf("Previous node is %d\n", all_nodes[index].prev->max_PP);
      printf("%s\n", &all_nodes[index].prev->name);
      printf("%d\n", all_nodes[index].prev->x);
      printf("%d\n", all_nodes[index].prev->y);
      printf("%d\n", all_nodes[index].prev->curr_PP);
      printf("%d\n", all_nodes[index].prev->max_PP);
      printf("\n\n\n");

      // printf("%d\n", all_nodes[index].prev->index);
    }

    prev_node = &all_nodes[index];
    // f(index != 0){
    // printf("previous node of %s is %s\n ", all_nodes[index].name, all_nodes[index].prev->name);
    // }

    index++;
  }

  for (int i = 1; i < num_nodes; i++)
  {
    if (i != 0)
    {
      printf("%c\n", &all_nodes[i].prev->name);
    }
    printf("%d\n", all_nodes[i].prev->x);
    printf("%d\n", all_nodes[i].prev->y);
    printf("%d\n", all_nodes[i].prev->curr_PP);
    printf("%d\n", all_nodes[i].prev->max_PP);
  }
 //stuck
    printf("%c\n", test)
}

// ignore the names for now, just identify them via index

int main(int argc, char *argv[])
{
  int initial_range;
  int jump_range;
  int num_jumps;
  int initial_power;
  double power_reduction;
  char in_name[1024];
  int x_in, y_in, curr_pp_in, max_pp_in;
  int num_nodes = 0;

  sscanf(argv[1], "%d", &initial_range);
  sscanf(argv[2], "%d", &jump_range);
  sscanf(argv[3], "%d", &num_jumps);
  sscanf(argv[4], "%d", &initial_power);
  sscanf(argv[5], "%lf", &power_reduction);
  Node *all_nodes = malloc(sizeof(Node));
  Node *prev_node = (NULL);
  int index = 1;

  scanf("%i %i %i %i %s", &x_in, &y_in, &curr_pp_in, &max_pp_in, in_name);
  num_nodes += 1;
  all_nodes = realloc(all_nodes, num_nodes * sizeof(Node));
  size_t string_length = strlen(in_name);
  all_nodes[0].name = (char *)malloc((string_length + 1) * sizeof(char));
  strcpy(all_nodes[0].name, in_name);
  all_nodes[0].x = x_in;
  all_nodes[0].y = y_in;
  all_nodes[0].curr_PP = curr_pp_in;
  all_nodes[0].max_PP = max_pp_in;
  all_nodes[0].prev = prev_node;
  prev_node = &all_nodes[0];
  while (scanf("%i %i %i %i %s", &x_in, &y_in, &curr_pp_in, &max_pp_in, in_name) == 5)
  {
    num_nodes += 1;
    all_nodes = realloc(all_nodes, num_nodes * sizeof(Node));
    size_t string_length = strlen(in_name);
    all_nodes[index].name = (char *)malloc((string_length + 1) * sizeof(char));
    strcpy(all_nodes[index].name, in_name);
    all_nodes[index].x = x_in;
    all_nodes[index].y = y_in;
    all_nodes[index].curr_PP = curr_pp_in;
    all_nodes[index].max_PP = max_pp_in;
    all_nodes[index].prev = prev_node;
    // free(prev_node);
    prev_node = &all_nodes[index];
   // printf("%p\n", prev_node);
    if (index > 0)
    {
      printf(" here: %s\n", all_nodes[index].prev->name);
    }
    index++;
  }
  // for(int i = 0; i < num_nodes; i++){
  //  printf("%s\n", all_nodes[i].name);

  // }

  for (int i = 0; i < num_nodes; i++)
  {
    printf("%s\n", all_nodes[i].name);
    printf("%d\n", all_nodes[i].x);
    printf("%d\n", all_nodes[i].y);
    printf("%d\n", all_nodes[i].curr_PP);
    printf("%d\n", all_nodes[i].max_PP);
  }
  Node *p = &all_nodes[num_nodes - 1];
  while (p->prev != NULL)
  {
    printf("name: %s, prev: %s\n", p->name, p->prev->name);

    p = p->prev;
  }
  /*
    for (int i = 2; i < num_nodes; i++)
    {
      if (all_nodes[i].prev != NULL)
      {
        printf("previous name: %s prev = %s\n", all_nodes[i].prev->name);
      }
    }
    printf("Node %d: name = %s\n", 1, all_nodes[1].name);

    for (int i = 0; i < num_nodes; i++)
    {
      if (all_nodes[i].prev != NULL);
      {
        printf("Node %d: name = %s, prev = %s\n", i, all_nodes[i].name, (void *)all_nodes[i].prev->name);
      }
      if (all_nodes[i].prev == NULL)
      {
        printf("%d\n", i);
      }
    }
   
}
 */ 