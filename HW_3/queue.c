/*
  Timothy Driscoll
   ECE 2230 HW 2, 10/9/19

   Fucntion Implementation for queue ADT
*/

//Include the neccesary libraries
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

//Create the structure that represents a queue node
struct queue_node{
  q_data itemPtr;
  struct queue_node *link;
}queue_node;

//Create a structure that represents the queue header (stores pointer to front
// and the rear)
struct queue_header{
  struct queue_node *front;
  struct queue_node *rear;
};

void createQueue(q *queue)
  {
    //Intialize a queue header structure
    struct queue_header *header;
    //dynamically allocate the memeory for the queue header
    header = (struct queue_header *)malloc(sizeof(struct queue_header));
    //set the queue equal to the header casted as a q data type
    *queue = (q) header;
    //Intialize the front and rear to be NULL
    header->front = NULL;
    header->rear = NULL;
    printf("\nThe queue has been intialized!\n");
  }

int emptyQueue(q queue)
  {
    //create a new queue header that is equal to the queue handle casted as a
    //queue_header structure
    struct queue_header *header = (struct queue_header *)queue;
    //If front pointer is still NULL the queue is empty else is has data in it
    if(header->front == NULL)
      return(0);
    else
      return(1);
  }

int fullQueue(q queue)
  {
    //assumed that already constructed queue is not full since it can still
    //grow as linked list structure (Used text book a reference for this)
    //The system would have to exhuast all its avaliable memory.
    return(0);
  }

void itemInsert(q queue, q_data insert_data)
  {
    //Makes sure the queue has been intialized first
    if(queue == NULL)
      {
        printf("\nThe queue must first be initalized\n");
      }
    else
      {
        //create a new queue header that is equal to the queue handle casted as a
        //queue_header structure
        struct queue_header *header = (struct queue_header *)queue;
        //Intialize and allocate memory for the new node that is to be added to the
        //queue
        struct queue_node *new_node;
        new_node = (struct queue_node *)malloc(sizeof(queue_node));

        //Ensure that the system hasn't run out of storage (queue is full)
        if(new_node == NULL)
          printf("\nNo more system storage!\n");
        else
          {
            //intialize the nodes data to what the user inputed
            new_node->itemPtr = insert_data;
            new_node->link = NULL;
            //If queue is empty have both front and rear point to new node
            if(header->rear == NULL)
              {
                header->front = new_node;
                header->rear = new_node;
              }
            else
              {
                //If queue is not empty add the new node to the end of of the queue
                header->rear->link = new_node;
                //Adjust the header rear to point to the newly added node
                header->rear = new_node;
              }
            }
          }
        }

q_data itemRemove(q queue)
  {
    //Makes sure the queue has been intialized first
    if(queue == NULL)
      {
        printf("\nThe queue must first be initalized\n");
        return NULL;
      }
    else
      {
        //create a new queue header that is equal to the queue handle casted as a
        //queue_header structure
        struct queue_header *header = (struct queue_header *)queue;
        //Intialize a new queue_node structure in order to remove the data
        struct queue_node *new_node;
        //New q_data type pointer to store the removed data
        q_data *remove_data;

        //Check to see if the queue is empty or not, if it is empyt return NULL
        // and indicate to the user
        if(header->front == NULL)
          {
            printf("\nThe queue is empty, nothing to remove!\n");
            return NULL;
          }
        else
          {
            //Get the data to be removed from the front of the queue
            remove_data = header->front->itemPtr;
            //temporarily set the new_node to the front of the queue
            new_node = header->front;
            //Update the header to have the new front point to the link of the old
            //front
            header->front = new_node->link;
            //Free the new_node in order to offically remove the item from the queue
            free(new_node);
            //Check if the queue is now empty if it is set the rear pointer to NULL
            if(header->front == NULL)
              header->rear = NULL;
            //Return the retrieved data
            return remove_data;
      }
  }
}

q deleteQueue(q *queue)
  {
    //create a new queue header that is equal to the queue handle casted as a
    //queue_header structure
    struct queue_header *header = (struct queue_header *)queue;
    //create a rover that starts at the front of the list
    struct queue_node *rover = header->front;
    //create a follower to follow the rover
    struct queue_node *follower;

    //Run through the entire queue
    while(rover)
      {
        //have the follower trail the rover in order to be freed
        follower = rover;
        free(follower);
        //move the rover down the queue
        rover = rover->link;
      }
    // free the header
    free(header);
    // set the pointer to NULL and return
    queue = NULL;
    return queue;
  }
