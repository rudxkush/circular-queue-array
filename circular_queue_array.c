/*************************************************
"Circular Queue using array"
**************************************************/
#include<stdio.h>
#include <assert.h>
#define capacity 5

/****************************************
declared queue struct
*****************************************/
struct queue
{
int headIndex;
int tailIndex;
int element[capacity];
int size;
};
typedef struct queue queue; 

/****************************************
overflow check function
*****************************************/
int isFull(queue* Queue) 
{
  if ((Queue->headIndex == Queue->tailIndex + 1) || (Queue->headIndex == 0 && Queue->tailIndex == capacity - 1))
  {return 1;}
  return 0;
}

/****************************************
underflow check function
*****************************************/
int isEmpty(queue* Queue)
{
  if(Queue->headIndex == Queue->tailIndex)
  {return 1;}
  return 0;
}

/****************************************
adds element to queue
*****************************************/
void enQueue(queue* Queue,int elemToinsert)
{
  if(!isFull(Queue))  //handles OVERFLOW
  {
    if(Queue->headIndex == -1)
    {Queue->headIndex = 0;}
    
    if(Queue->tailIndex<capacity-1)
    {Queue->tailIndex ++;}
    else
    {Queue->tailIndex = 0;}
    
    Queue->element[Queue->tailIndex] = elemToinsert;
    printf("\n-----------enQueue():: element-> %d added",elemToinsert,Queue->tailIndex); 
    // action message
    printf(" H:%d  T:%d-----------",Queue->headIndex,Queue->tailIndex);                 
    // head-tail status
    Queue->size++;
  }
  else
  {
    printf("\n-----------enQueue():: ~Queue is full!!-----------");
  }
}

/****************************************
pops element from queue
*****************************************/
void deQueue(queue* Queue)
{
  if(!isEmpty(Queue))  
  {
    printf("\n-----------~deQueue():: element-> %d deleted",Queue->element[Queue->headIndex]); 
    // action message
    printf(" H:%d  T:%d-----------",Queue->headIndex,Queue->tailIndex);                       
    // head-tail status
    
    if(Queue->headIndex == capacity-1) // sets headIndex to '0' on max position     
    {Queue->headIndex = 0;} 
    
    else                               // increments headIndex on "deQueue" 
    {Queue->headIndex ++;}  
    Queue->size--;
  }
  
  else  //handles UNDERFLOW
  {
    printf("\n-----------~deQueue():: empty queue ~underflow detected-----------");
  }
}

/****************************************
shows Queue stats 
*****************************************/
void showQueue(queue Queue)
{
  int iterator;                //navigates through the queue
  iterator = Queue.headIndex;  //starts iteration from "headIndex"

  printf("\n\n.------------------------------------------");
  printf(  "\n| Elements of Queue:");
  if(Queue.size!=0)
  {
    for(;iterator!=Queue.tailIndex;)
    {
      printf(" %d ",Queue.element[iterator]);
      if(iterator==capacity-1)
      {iterator = 0;}
      else
      {iterator++;}
    }
  printf(" %d ",Queue.element[iterator]);
  }
  else
  {printf(" ~empty ");}
  
  printf("\n|\n| Head: %d    Tail: %d",Queue.headIndex,Queue.tailIndex);
  printf("\n|\n| Elements : %d/5",Queue.size);
  printf("\n'------------------------------------------");
}

/*************************
Operation enum definition
**************************/
enum UserSelection
{
	NoOperation = 0,
	EnQueue = 1,
	DeQueue = 2,
	ShowQueue = 3,
	QuitProgram = 4,
};
void showMenu()
{
	const char *instruction = "\n\n" \
							"------------------------\n" \
							"|   Queue Operation    |\n" \
							"|----------------------|\n" \
							"| 1 | EnQueue          |\n" \
							"| 2 | DeQueue          |\n" \
							"| 3 | ShowQueue        |\n" \
							"| 4 | Quit program     |\n" \
							"------------------------\n";
	
	printf("%s\n", instruction);
}
/**************************
Get User Input
**************************/
int getUserInput()
{
	int optSelected = 0;
	
	showMenu();
	
	printf("Enter option << ");
	assert(scanf("%d", &optSelected) != 0 && "Invalid user input\n");

	
	return optSelected;
}
int main()
{
  queue blah;
  blah.headIndex = -1;
  blah.tailIndex = -1;
  blah.size = 0;
  int tempVal = 0;
  
  printf("Queue Implementation Using array");
  printf("\n____________________________________________\n");
  
  enum UserSelection optSelected;

	while (optSelected != QuitProgram)
	{
		switch (optSelected = getUserInput())
		{
			case EnQueue:
			{
        printf("\n Enter Number : ");
        scanf ("%d",&tempVal);
				enQueue(&blah,tempVal);
				break;
			}
		
			case DeQueue:
			{
				deQueue(&blah);
				break;
			}

			case ShowQueue:
			{
        showQueue(blah);
				break;
			}

			case QuitProgram:
			{
				printf("main:: Quitting... !\n");
				break;
			}
			
			default:
			{
				printf("main:: Invalid option !\n");
				break;
			}
		}
	} 
  
  return 0;
}

