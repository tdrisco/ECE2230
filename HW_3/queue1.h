/*
  Timothy Driscoll
   ECE 2230 HW 2, 10/9/19

   Header File for the queue ADT
*/

//#ifdef Q_H
//#define Q_H 1

//typedef void *q;
struct queue_header;

typedef void *q_data;

//Fucntion Headers
void createQueue(struct queue_header *q);

int emptyQueue(struct queue_header *q);

int fullQueue(struct queue_header *q);

void itemInsert(struct queue_header *q, q_data insert_data);

void itemRemove(struct queue_header *q, q_data remove_data);

//#endif
