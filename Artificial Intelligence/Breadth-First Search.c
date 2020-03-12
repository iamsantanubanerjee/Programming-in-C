#include<stdio.h>
#include<stdlib.h>
int *q, *visited, **matrix, front = -1, rear = -1, dim, flag = 0;
void bfs(int, int);
void add(int);
void delete();
void main()
{
  int i, j, start, end;
  printf("Enter the number of nodes: ");
  scanf("%d", &dim);
  q = (int *)malloc(dim *sizeof(int));                                          //Creating the queue of length equal to number of nodes
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
  printf("The path using BFS is: ");
  printf("%d", start);
  add(start);
  visited[start - 1] = 1;
  if(start == end)                                                              //Checking if starting node is equal to goal node
    flag = 1;
  bfs(start, end);
  printf("\n");
}
void bfs(int pos, int end)                                                      //Function to execute the breadth-first search, 'pos' stores the current node being explored
{
  while(flag != 1)
  {
    for(int j = 0; j < dim; j++)                                                //Exploring the current node
    {
      if(matrix[pos - 1][j] == 1 && (j + 1) == end)                             //Checking if goal node is found
      {
        printf(" -> %d", j + 1);
        flag = 1;
        break;                                                                  //Breaking out of the loop becuase no more exploration is needed
      }
      else if(matrix[pos - 1][j] == 1 && visited[j] == 0)                       //If the connected node is not visited before, printing it and storing it in queue
      {
        printf(" -> %d", j + 1);
        add(j + 1);
        visited[j] = 1;
      }
    }
    delete();                                                                   //Moving on to the next node in the queue by deleting previous node
    bfs(q[front], end);                                                         //Calling bfs with new node to explore
  }
}
void add(int item)                                                              //Adding item to queue
{
  if(rear == -1)
  {
    rear++;
    front++;
    q[rear] = item;
  }
  else
  {
    rear++;
    q[rear] = item;
  }
}
void delete()                                                                   //Deleting item from the queue
{
    front++;
    if(front > rear)
      front = rear = -1;
}
