//Include the neccesary libraries
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

//Create the structure that represents a queue node
struct queue_node{
  passenger_t* passenger;
  struct queue_node *link;
}queue_node;

//Create a structure that represents the queue header (stores pointer to front
// and the rear)
struct queue_s{
  struct queue_node *front;
  struct queue_node *rear;
};

queue_t *queue_init(int size)
  {
    //Intialize a queue header structure
    queue_t *header;
    //dynamically allocate the memeory for the queue header
    header = (queue_t *)malloc(sizeof(queue_t));

    //Intialize the front and rear to be NULL
    header->front = NULL;
    header->rear = NULL;
    printf("\nThe queue has been intialized!\n");
  }

  /* insert an item into the queue
     return 0 if successful, -1 otherwise */
int queue_insert(queue_t *q, passenger_t *c)
  {

  }
