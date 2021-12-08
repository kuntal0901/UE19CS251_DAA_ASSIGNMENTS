#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>
void read_from_file(char  *filename,char *mode);
void remove_first_character(char *a);
int** update_minheap(int **array,int vertex, int distance,int value);
void printpath(int p[],int **array);
int** heapify(int **array,int length);
int delete_minheap(int **array,int value);
int**  create_minheap();
struct node 
{
    int neighbour; //next neighbour
    int weight; //weight between vertex and neighbour
    struct node * next; //next node
};

 struct vertex
{
     int data; //data of each vertex
     struct vertex * next; // points to next vertex
     struct node *first_node;
};
void reverse_direction(struct vertex *graph);
void create_node(struct vertex *list,char *after);
void dijkstra(int source,struct vertex* graph);
