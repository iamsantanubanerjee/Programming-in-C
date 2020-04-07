#include<stdio.h>
#include<stdlib.h>
int *stack, *visited, **matrix, top = -1, dim, flag = 0;
void dfs(int, int);
void add(int);
void delete();
void main()
{
  int i, j, start, end;
  printf("Enter the number of nodes: ");
  scanf("%d", &dim);
  stack = (int *)malloc(dim *sizeof(int));                                      //Creating the stack of length equal to number of nodes
  visited = (int *)malloc(dim *sizeof(int));                                    //Creating a visited array of length equal to number of nodes
  for(i = 0; i < dim; i++)
    visited[i] = 0;                                                             //Initialising the visited array elements to zero
  matrix = (int **)malloc(dim *sizeof(int *));                                  //Creating the adjacency matrix
  for(i = 0; i < dim; i++)
    matrix[i] = (int *)malloc(dim *sizeof(int));
  printf("\nEnter the adjacency matrix: \n");                                   //Taking input of the adjacency matrix from the user
  for(i = 0; i < dim; i++)
    for(j = 0; j < dim; j++)
      scanf("%d", &(*(*(matrix+i)+j)));
  printf("\nEnter the start node: ");                                           //Taking input of the starting nodes
  scanf("%d", &start);
  printf("\nEnter the end node: ");                                             //Taking input of the end node
  scanf("%d", &end);
  printf("The path using DFS is: ");
  printf("%d", start);
  visited[start - 1] = 1;
  add(start);
  if(start == end)                                                              //Checking if starting node is equal to goal node
    flag = 1;
  dfs(start, end);
  printf("\n");
}
void dfs(int pos, int end)
{
  while(flag != 1)
  {
    for(int j = 0; j < dim; j++)                                                //Exploring the current node
    {
      if(matrix[pos - 1][j] == 1 && visited[j] == 0)                            //If the connected node is not visited before, exploring it and it in stack
      {
        printf(" -> %d", j + 1);
        add(j + 1);
        visited[j] = 1;
        if((j + 1) == end)
        {
          flag = 1;
          break;
        }
        dfs(stack[top], end);                                                   //Calling dfs with new node to explore
      }
    }
    delete();
    dfs(stack[top], end);                                                       //Moving on to the previous node in the stack by deleting current node
  }
}
void add(int item)                                                              //Function to add element to stack
{
  top++;
  stack[top] = item;
}
void delete()                                                                   //Function to delete element from stack
{
  top--;
}
