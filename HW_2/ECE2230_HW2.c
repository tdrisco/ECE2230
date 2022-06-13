/* Timothy Driscoll
   ECE 2230 HW 2, 9/16/19

   Program Description: A c program that works with a stack and queue to insert
   and remove a group of numbers from each respective data structure.

   1) Insert the numbers 1-20 into the stack (using for loop)
   2) Using a while loop remove the numbers from the stack and insert them into
      the queue
   3) Using another while loop remove all the numbers from the queue
   4) Print all the numbers after removing them from the queue
   ** Make sure to check for an empty stack or queue don't count the numbers

*/

//Include the neccesary libraries
#include <stdio.h>
#include <stdlib.h>

//max size of both the stack and the queue
#define maxSize 100

// Define the structure used to implement the stack
struct Stacks{
  int count;
  int  items[maxSize];
};
/*
createStack: A fucntion that intializes the stack (sets count to 0)
    Inputs: struct Stacks *stack - A pointer pointing to a Stacks structure
    Outputs: no outputs
*/
void createStack(struct Stacks * stack)
  {
    stack->count = 0;
  }
/*
emptyStack: A fucntion that checks if the stack is empty or not
    Inputs: struct Stacks *stack - A pointer pointing to a Stacks structure
    Outputs: returns an int (1 or 0) representing if the list is empty(0) or not
    empty(1)
*/
int emptyStack(struct Stacks * stack)
  {
    if(stack->count == 0)
      {
        printf("\nThe stack is empty...\n\n");
        return(0);
      }
    else
      return(1);
  }
/*
itemPop: A fucntion that pops information off of the stack
    Inputs: struct Stacks *stack - A pointer pointing to a Stacks structure
    Outputs: pop_info - an integer that returns the information popped from the
    stack
*/
int itemPop(struct Stacks *stack)
  {
    int pop_info = 0;
    //check for an empty stack (nothing to pop)
    if(stack->count == 0)
      {
        printf("\nThe stack is empty, nothing to pop...\n\n");
      }
      else
        {
          //decrement the counter (count is one greater than index position)
          stack->count = stack->count - 1;
          //retrieve the data at the top of the stack
          pop_info = stack->items[stack->count];
        }
    return pop_info;
  }
/*
itemPush: A fucntion that pushes information onto the stack
    Inputs: struct Stacks *stack - A pointer pointing to a Stacks structure
            int info - The data that is to be pushed onto the stack
    Outputs: no outputs
*/
void itemPush(struct Stacks *stack, int info)
  {
    //make sure that the stack isn't full already
    if(stack->count == maxSize)
      {
        printf("\nThe stack is full, can't push another item...\n\n");
      }
      else
        {
          //Push the information onto the top of the stack the increment the
          //counter by one (count is one greater than index position)
          stack->items[stack->count] = info;
          stack->count = stack->count + 1;
        }
  }

//Define the structure used to implement the queue
  struct Queues{
    int count;
    int front;
    int rear;
    int  items[maxSize];
  };
/*
createStack: A fucntion that intializes the stack (sets count, front, rear to 0)
    Inputs: struct Queues *queue - A pointer pointing to a Queues structure
    Outputs: no outputs
*/
void createQueue(struct Queues * queue)
  {
    queue->count = 0;
    queue->front = 0;
    queue->rear = 0;
  }
/*
emptyQueue: A fucntion that determines if the stack is empty or not
    Inputs: struct Queues *queue - A pointer pointing to a Queues structure
    Outputs: Returns an int (1 or 0) representing if the list is empty(0) or not
    empty(1)
*/
int emptyQueue(struct Queues * queue)
  {
    if(queue->count == 0)
      {
        printf("\n\nThe queue is empty...\n\n");
        return(0);
      }
    else
      return(1);
  }
/*
emptyQueue: A fucntion that removes the next item from the queue
    Inputs: struct Queues *queue - A pointer pointing to a Queues structure
    Outputs: remove_info - An integer that stores the information removed from
             the queue (FIFO)
*/
int itemRemove(struct Queues *queue)
  {
    int remove_info = 0;
    //check for an empty queue
    if(queue->count == 0)
      {
        printf("\nThe queue is empty, nothing to remove...\n\n");
      }
      else
        {
          //remove info from the queue than using modular arithmetic increment
          //the front index
          remove_info = queue->items[queue->front];
          queue->front = (queue->front + 1) % maxSize;
          //decrease count by one
          queue->count = queue->count - 1;
        }
    return remove_info;
  }
/*
itemInsert: A fucntion that inserts an item into the queue
    Inputs: struct Queues *queue - A pointer pointing to a Queues structure
            int info - An integer storing the information to be inserted into
            the queue
    Outputs: no outputs
*/
void itemInsert(struct Queues *queue, int info)
  {
    //make sure that the queue isn't full
    if(queue->count == maxSize)
      {
        printf("\nThe queue is full, can't insert more information...\n\n");
      }
      else
        {
          //insert info from the queue than using modular arithmetic increment
          //the rear index
          queue->items[queue->rear] = info;
          queue->rear = (queue->rear + 1) % maxSize;
          //increase count by one
          queue->count = queue->count + 1;
        }
  }

int main(void)
{
    //Intialize stack and queue pointers
    struct Stacks *stack = NULL;
    struct Queues *queue = NULL;

    //Dynamically allocate space for the stack and queue
    stack = (struct Stacks *) malloc(sizeof(struct Stacks));
    queue = (struct Queues *) malloc(sizeof(struct Queues));

    //Intialize neccesary variables to hold information
    int pop_info;
    int remove_info;

    //Intialize the new stack and queue
    createStack(stack);
    createQueue(queue);

    int i;
    printf("\nPushing Items Onto Stack...\n");
    //push items 1-20 onto the stack
    for(i = 1;i <= 20;i++)
      {
        itemPush(stack,i);
        //printf("\nPushed Item: %d",i);
      }
    printf("\nPopping Items From Stack and Inserting Them Into Queue...\n");
    //Pop items off the stack and insert them into the queue until the stack is
    //empty
    while(emptyStack(stack))
        {
          pop_info = itemPop(stack);
          itemInsert(queue,pop_info);
          //printf("\nPopped Item: %d",pop_info);
        }
    printf("Removing Items From The Queue...\n");
    //Remove items from the queue and print them out until the queue is empty
    while(emptyQueue(queue))
        {
          remove_info = itemRemove(queue);
          printf("\nRemoved Item: %d",remove_info);
        }


  return 0;
}
