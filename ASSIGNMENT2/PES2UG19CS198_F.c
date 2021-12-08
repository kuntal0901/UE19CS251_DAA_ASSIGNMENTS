#include "PES2UG19CS198_H.h"
int no_of_vertices;
void remove_first_character(char *a)
{
    int length=strlen(a);
    char temp[length];
    int i;
    for(i=1;i<length;i++)
    {
        a[i-1]=a[i];
    }
    a[i-1]='\0';
    
}
void create_node(struct vertex *list,char *after)
{
    struct node *temp=malloc(sizeof(struct node));
    struct node *temp1=malloc(sizeof(struct node));
    temp1=temp;
    char *str = after;
    const char s[2] = " ";
    char *token;
    token = strtok(str, s);
    do{
        
        temp->neighbour=atoi(token);
        token = strtok(NULL, s);
        temp->weight=atoi(token);
        if(token!=NULL)
        {
            temp->next=malloc(sizeof(struct node));
            temp=temp->next;
        }
        else
        {
            temp->next=NULL;
        }
        token = strtok(NULL, s);
        
    }while( token != NULL );
   list->first_node=temp1;
}
void reverse_direction(struct vertex *graph)
{
    struct vertex* newgraph=malloc(sizeof(struct vertex));
    struct vertex * traversal_newgraph=newgraph;
    struct vertex* temp=graph;
    int i;
    for(i=0;i<no_of_vertices;i++)
    {
        traversal_newgraph->data=i+1;
        traversal_newgraph->first_node=NULL;
        if(i!=no_of_vertices-1)
        {
            traversal_newgraph->next=malloc(sizeof(struct vertex));
            traversal_newgraph=traversal_newgraph->next;
        }
        else
        {
            traversal_newgraph->next=NULL;
        }
        
    }
    while(temp->next!=NULL)
    {
        struct node *traversalnode=temp->first_node;
        while(traversalnode->next!=NULL)
        {   traversal_newgraph=newgraph;
            for(i=1;i<traversalnode->neighbour;i++)
            {
                traversal_newgraph=traversal_newgraph->next;
            }
            struct node *temp1=traversal_newgraph->first_node;
            if(temp1!=NULL)
            {
                while(temp1->next!=NULL)
                {
                    temp1=temp1->next;
                }
                temp1->next=malloc(sizeof(struct node));
                temp1=temp1->next;
                temp1->weight=traversalnode->weight;
                temp1->neighbour=temp->data;
                temp1->next=NULL;
            }
            else
            {
                traversal_newgraph->first_node=malloc(sizeof(struct node));
                temp1=traversal_newgraph->first_node;
                temp1->weight=traversalnode->weight;
                temp1->neighbour=temp->data;
                temp1->next=NULL;
            }
            
            traversalnode=traversalnode->next;
        }
        temp=temp->next;
    }



    struct node *traversalnode=temp->first_node;
        while(traversalnode->next!=NULL)
        {   traversal_newgraph=newgraph;
            for(i=1;i<traversalnode->neighbour;i++)
            {
                traversal_newgraph=traversal_newgraph->next;
            }
            struct node *temp1=traversal_newgraph->first_node;
            if(temp1!=NULL)
            {
                while(temp1->next!=NULL)
                {
                    temp1=temp1->next;
                }
                temp1->next=malloc(sizeof(struct node));
                temp1=temp1->next;
                temp1->weight=traversalnode->weight;
                temp1->neighbour=temp->data;
                temp1->next=NULL;
            }
            else
            {
                traversal_newgraph->first_node=malloc(sizeof(struct node));
                temp1=traversal_newgraph->first_node;
                temp1->weight=traversalnode->weight;
                temp1->neighbour=temp->data;
                temp1->next=NULL;
            }
            
            traversalnode=traversalnode->next;
        }
    dijkstra(no_of_vertices,newgraph);
}
void read_from_file(char *filename,char *mode)
{

    struct vertex *graph=malloc(sizeof(struct vertex));
    struct vertex *temp=malloc(sizeof(struct vertex));
    graph=temp;
    FILE *fp1=fopen(filename,"a");
    fputc(10,fp1);
    fclose(fp1);
    FILE *fp=fopen(filename,mode);
    if(fp!=NULL)
    {
        char *string=malloc(sizeof(char)*100);
        fgets(string,100,fp);
        no_of_vertices=atoi(string);
        int i;
        for(i=1;i<=no_of_vertices;i++)
        {
            fgets(string,100,fp);
            if(string!=NULL)
            {
                const char s[2] = " ";
                char a[80];
                strcpy(a,string);
                char *token;
                token = strtok(string, s);
                temp->data=atoi(string);
                token = strchr(a,' ');
                remove_first_character(token);
                temp->first_node=malloc(sizeof(struct node));
                token[strlen(token)-1]='\0';
                create_node(temp,token);
                                    
            }
            if(i<no_of_vertices)
            {
                temp->next=malloc(sizeof(struct vertex));
                temp=temp->next;
                
            }
            else
            {
                temp->next=NULL;
            }   

        }
        reverse_direction(graph);
        fclose(fp);
    }
    
}
void printpath(int *p,int **arr)
{
    int array[no_of_vertices+1];
    array[0]=0;
    int i=0,counter=0,j;

    for(i=1;i<no_of_vertices;i++)
    {
        printf("%d %d ",i,i);
        int a=p[i];
        if(a==0)
        {
            printf("NO PATH");
        }
        while(a!=0)
        {
            array[counter++]=a;
            a=p[a];
        }
        for(j=0;j<=counter-1;j++)
        {
            printf("%d ",array[j]);
        }
        for(j=1;j<no_of_vertices;j++)
        {
            if(arr[j][0]==i)
                printf("%d \n",arr[j][1]);
        }
        
        counter=0;
    }
}
void dijkstra(int source,struct vertex* graph)
{
    struct vertex *temp;
    
    int **array;
    int counter=1;
    int *p=malloc(sizeof(int)*(no_of_vertices+1));
    int vT[no_of_vertices];
    int vTcounter=0;
    array=create_minheap();
    int i,j,i5;
    for(int i4=1;i4<=no_of_vertices;i4++)
    {
          p[i4]=0;
    }
    array=update_minheap(array,source,0,counter-1);
    int i2;
    for(int i10=0;i10<no_of_vertices;i10++)
    {
        temp=graph;
        int vertex;
        vertex=delete_minheap(array,counter);
        for(i2=1;i2<=no_of_vertices;i2++)
        {
            if(array[i2][0]==vertex)
                break;
        }
        vT[vTcounter++]=vertex;
        int element[no_of_vertices];
        int weight[no_of_vertices];
        while(temp->data!=vertex && temp->next!=NULL)
        {
            temp=temp->next;
        }
        struct node *temp1=temp->first_node;
        int cou=0,found=0;
        while(temp1!=NULL)
        {
            found=0;
            for(i5=0;i5<vTcounter && !found;i5++)
            {
                
                if(vT[i5]==temp1->neighbour)
                {
                    break;
                    found=1;
                }
            }    
                 
            if(found==0)
                {
                    element[cou]=temp1->neighbour;
                    weight[cou]=temp1->weight;
                    cou++;
                    
                }
            temp1=temp1->next;
        }
        temp=graph;
        for(i=0;i<cou;i++)
        {
            int adjvertex=element[i];
            int i1;
            for(i1=1;i1<=no_of_vertices;i1++)
            {
                if(array[i1][0]==adjvertex)
                      break;
            }
            if(array[i2][1]+weight[i]<array[i1][1])
            {
                array[i1][1]=array[i2][1]+weight[i];
                p[adjvertex]=vertex;
                int chuckno=array[i1][1];
                array=update_minheap(array,adjvertex,chuckno,counter);
               
            }
            
        }
        
        counter++;
        
    }   
    printpath(p,array);
}
int**  create_minheap()
{
        int i, j;
        int c=2;
        int **arr = (int **)malloc((no_of_vertices+1) * sizeof(int *));
        for (i=0; i<=no_of_vertices; i++)
            arr[i] = (int *)malloc(c * sizeof(int));

        for (i = 1; i <=no_of_vertices; i++)
        {
            for (j = 0; j <c; j++)
            {
                if(j==0)
                    arr[i][j] = i; 
                else
                    arr[i][j] = __INT_MAX__;
                
            }            
        }
        return arr;
}
int** update_minheap(int **array,int vertex, int distance,int value)
{
    for(int i=1;i<=no_of_vertices;i++)
    {
        if(array[i][0]==vertex)
        {
               array[i][1]=distance;
        }
    }
   
    int i,child,parent,dv;
    int heap;
    int v;
    if(vertex<no_of_vertices)
    {     
        for(i=(no_of_vertices-value-1)/2;i>=1;i--)
        {   
            parent=i;
            dv=array[parent][1];
            v=array[parent][0];
            heap=0;
            int *temp;
            temp=array[parent];
            while((heap!=1) && 2*parent<no_of_vertices-value )
            {
                
                child=2*parent;
                if(child<no_of_vertices && (child+1)<(no_of_vertices-value+1))
                {
                    if(array[child][1]>array[child+1][1])
                    {
                        child=child+1;
                    }
                }
                    if(dv<=array[child][1])
                    {
                        heap=1;
                    }
                    else
                    {  array[parent]=array[child];
                        parent=child;
                    }
                
            }
            array[parent]=temp;
            
        }
        return array;
    }
    else
    {   
        for(i=(no_of_vertices-value+1)/2;i>=1;i--)
        {   
            parent=i;
            dv=array[parent][1];
            v=array[parent][0];
            heap=0;
            int *temp;
            temp=array[parent];
            while((heap!=1) && 2*parent<=no_of_vertices-value+1 )
            {
                
                child=2*parent;
                if(child<no_of_vertices && (child+1)<(no_of_vertices-value+1))
                {
                    if(array[child][1]>array[child+1][1])
                    {
                        child=child+1;
                    }
                }
                    if(dv<=array[child][1])
                    {
                        heap=1;
                    }
                    else
                    {  array[parent]=array[child];
                        parent=child;
                    }
                
            }
            array[parent]=temp;
            
        }
        return array;
    }
}

int** heapify(int **array,int length)
{
     int i,child,parent,dv;
    int heap;
    int v;
    for(i=(length)/2;i>=1;i--)
    {   
        parent=i;
        dv=array[parent][1];
        v=array[parent][0];
        heap=0;
        int *temp;
        temp=array[parent];
        while((heap!=1) && 2*parent<length )
        {
            
            child=2*parent;
            if(child<length)
            {
                if(array[child][1]>array[child+1][1])
                {
                    child=child+1;
                }
            }
                if(dv<=array[child][1])
                {
                    heap=1;
                }
                else
                {
                    array[parent]=array[child];
                    parent=child;
                }
            
        }
        array[parent]=temp;
    }
    return array;
}
int delete_minheap(int **array,int value)
{
    int *temp=array[1];
    array[1]=array[no_of_vertices-value+1];
    array[no_of_vertices-value+1]=temp;
    int i, j;
    int c=2;
    int **arr = (int **)malloc((no_of_vertices+1-value) * sizeof(int *));
    for (i=0; i<=(no_of_vertices-value); i++)
        arr[i] = (int *)malloc(c * sizeof(int));

    for (i = 0; i <=no_of_vertices-value; i++)
    {
        for (j = 0; j <c; j++)
        {
                if(j==0)
                    arr[i][j] = array[i][j]; 
                else
                    arr[i][j] = array[i][j]; 
                
        }            
    }
    arr=heapify(arr,no_of_vertices-value);
    for (i = 0; i <=no_of_vertices-value; i++)
    {
        for (j = 0; j <c; j++)
        {
                if(j==0)
                    array[i][j] = arr[i][j]; 
                else
                    array[i][j] = arr[i][j]; 
                
        }            
    }
        

    return array[no_of_vertices-value+1][0];
}
