#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>

struct node
{
char name[50];
struct node *link;
};

struct node *first=NULL;
struct node *new1;
struct node *temp;

void add(char na[]) //This function will add node into the circular link list
{
  new1=(struct node*)malloc(sizeof(struct node));//create memory for new node
  strcpy(new1->name,na);
  new1->link=new1;             //   create node

  if(first==NULL)
  {     first=new1;  }
  else
  {
     temp=first->link;
     while(temp->link!=first)
     { 	temp=temp->link;     }

     new1->link=temp->link;
     temp->link=new1;
  }
}
void print()  // This function is used to travers the circuler list
{
   int i=2;
   if(first==NULL)
   {
      printf("\nTHERE IS NO KID");
      return;
   }
   else
   {
      printf("\n1) %s",first->name);
      temp=first->link;
      while(temp!=first)
      {
	printf("  %d) %s ",i,temp->name);
	temp=temp->link;
	i++;
      }
   }
}

void eliminate(int d)  //Usind This fun. we delete the node at position 'd'
{
  int i;
  struct node *prev;
  while(first->link!=first)
  {
      if(d==1)
      {
	printf("\n\n==>%d) ' %s ' IS ELEMENETED\n",d,first->name);
	temp=first->link;
	while(temp!=first)
	{
	   prev=temp;
	   temp=temp->link;
	}
	prev->link=temp->link;
	first=prev->link;
      }
      else
      {
	temp=first;
	for(i=1;i<d;i++)
	{
	  prev=temp;
	  temp=temp->link;
	}
	prev->link=temp->link;
	printf("\n\n=>PASSES=%d) ' %s ' IS ELEMENETED\n",d,temp->name);
	first=prev->link;
      }
      printf("\n\nKIDS STILL IN GAME");
      print();
      delay(1000);
   }
}

void main()
{
  int i,choice,M,N; //M:number of kids,N:random number,choice:for switch case.
  char na[50];
  clrscr();

  while(choice!=4)
  {
    printf("\n1)ENTER KIDS");
    printf("\n2)START ELIMINATION");
    printf("\n3)EXIT");
    printf("\nENTER YOUR CHOICE:");
    scanf("%d",&choice);

   switch(choice)
   {
    case 1:printf("\nENTER NUMBER OF KIDS:");
	   scanf("%d",&M);
	   for(i=1;i<=M;i++)
	   {
		   printf("\nENTER NAME:");
		   flushall();
		   gets(na);
		   add(na);  //This function add the node into link list
	   }
	   break;
    case 2: printf("\nENTER RANDOM NUMBER AMONG (1-%d) :",M-1);
	    scanf("%d",&N);
	    printf("\nTOTAL KIDS IN GAME");
	    print();
	    eliminate(N); //This function start the game of elimination
	    printf("\n\n\n--->KID ' %s ' WIN THE GAME",first->name);
	    printf("\n__________________CONGRATULATION___________________\n");
	    break;
    case 3: exit(0);
	    break;
    default:printf("\n->PLEASE ENTER PROPER CHOICE:");
   }
  }
  getch();
}
