//Include the neccesary libraries
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


int main(void)
{

    //Intialize two different data types to test with
    int test[] = {0,1,2,3,4,5,6,7,8,9};
    char test2[] = {'a','b','c','d','e'};
    //intialize loop counter
    int i = 0;

    //Intialize two seperate queues to be used for testing
    q queue = NULL;
    q_data test1_data;
    q queue2 = NULL;
    q_data test2_data;

    //attmept to insert into and remove from queue before intalization
    itemInsert(queue, (q_data) &test[i]);
    test1_data = itemRemove(queue);

    //Dynamically allocate the memory for the two queues
    queue = (q *)malloc(sizeof(q));
    queue2 = (q *)malloc(sizeof(q));

    //intialize the queue
    createQueue(queue);

    //Insert the numbers 0 through 9 into the queue
    for(i = 0; i < 10; i++)
      {
        itemInsert(queue, (q_data) &test[i]);
      }

    //Remove the items from the queue and print to test results
    while(emptyQueue(queue))
      {
        test1_data = itemRemove(queue);
        printf("\nRemoved Item: %d",*(int*) test1_data);
      }

    //Attempt to remove from the empty queue
    test1_data = itemRemove(queue);

    //Intialize the second queue
    createQueue(queue2);

    //Insert the letters a-e into the queue to test a second data type
    for(i = 0; i < 5; i++)
      {
        itemInsert(queue2, (q_data) &test2[i]);
      }

    //Remove items from the second queue and print to test results
    while(emptyQueue(queue2))
      {
        test2_data = itemRemove(queue2);
        printf("\nRemoved Item: %c",*(char*) test2_data);
      }
    //try to remove from an empty queue again
    test2_data = itemRemove(queue2);

    //Delete the queue
    queue = deleteQueue(queue);
    //Try to remove from and insert into the deleted queue
    test1_data = itemRemove(queue);
    itemInsert(queue, (q_data) &test[i]);

    queue = deleteQueue(queue2);

    return 0;
  }
