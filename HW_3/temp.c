/*
  Timothy Driscoll
   ECE 2230 HW 2, 10/9/19
*/

//Include the neccesary libraries
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct queue_node{
  void  *itemPtr;
  struct node *link;
}queue_node;

struct queue_header{
  struct queue_node *front;
  struct queue_node *rear;
};

void createQueue(struct queue_header *q)
  {
    //struct queue_header *header;
    //header = (struct queue_header *)malloc(sizeof(struct queue_header));
    //*q = header;
    q = (struct queue_header *)malloc(sizeof(struct queue_header));
    q->front = NULL;
    q->rear = NULL;
  }

int emptyQueue(struct queue_header *q)
  {
    //struct queue_header *header = (struct queue_header *)q;
    if(q->front == NULL)
      return(1);
    else
      return(0);
  }

int fullQueue(struct queue_header *q)
  {
    //assumed that already constructed queue is not full since it can still
    //grow as linked list structure (Used text book a reference for this)
    return(0);
  }

void itemInsert(struct queue_header *q, q_data insert_data)
  {
    //struct queue_header *header = (struct queue_header *)q;
    struct queue_node *new_node;
    new_node = (struct queue_node *)malloc(sizeof(queue_node));

    if(new_node == NULL)
      printf("\nNo more system storage!\n");
    else
      {
        new_node->itemPtr = insert_data;
        new_node->link = NULL;
        if(q->rear == NULL)
          {
            q->front = new_node;
            q->rear = new_node;
          }
        else
          {
            q->rear->link = new_node;
            q->rear->= new_node;
          }
      }
  }

void itemRemove(struct queue_header *q, q_data remove_data)
  {
    //struct queue_header *header = (struct queue_header *)q;
    struct queue_node *new_node;


    if(q->front == NULL)
      {
        printf("\nThe queue is empty, nothing to remove!\n");
      }
    else
      {
        *remove_data = q->front->itemptr;
        new_node = q->front;
        q->front = new_node->link;
        free(new_node);
        if(q->front == NULL)
          q->rear = NULL;
      }
  }
