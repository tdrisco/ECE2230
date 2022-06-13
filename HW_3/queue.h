/*
  Timothy Driscoll
   ECE 2230 HW 2, 10/9/19

   Header File for the queue ADT
*/

//Check to make sure that the queue.h file hasn't been previously included
#ifndef Q_H
#define Q_H 1

// Opaque type for the handle, used to hide the queue struct
typedef void *q;

//void pointer data type created to allow for the queue to handle all different
//data types
typedef void *q_data;

//Fucntion Headers and defintions

/*
createQueue: A fucntion that intializes the queue (sets front, rear to NULL)
    Inputs: q *queue - handle declared as an opaque type
    Outputs: no outputs
*/
void createQueue(q *queue);

/*
emptyQueue: A fucntion that determines if the queue is empty or not
    Inputs:  q *queue - handle declared as an opaque type
    Outputs: Returns an int (1 or 0) representing if the list is empty(0) or not
    empty(1)
*/
int emptyQueue(q queue);

/*
fullQueue: A fucntion that determines if the queue is full or not
    Inputs:  q queue - handle declared as an opaque type
    Outputs: Returns the interger value 0 for every call becasues since the
             queue is set up with a linked structured the only way the queue
             would be full is if the system exhausted all its memory
*/
int fullQueue(q queue);

/*
itemInsert: A fucntion that inserts an item into the queue by adding a new node
            to the rear of the linked list.
    Inputs: q queue - handle declared as an opaque type
            q_data insert_data - A void pointer that can represent any data type
            that the user wants to input into the queue.
    Outputs: no outputs
*/
void itemInsert(q queue, q_data insert_data);

/*
itemRemove: A fucntion that removes the next item from the queue
    Inputs: q queue - handle declared as an opaque type
    Outputs: remove_info - A void pointer that stores the information removed
            from the queue (FIFO)
*/
q_data itemRemove(q queue);

/*
deleteQueue: A fucntion that deletes the queue by freeing the data structure
    Inputs: q *queue - handle declared as an opaque type
    Outputs: q queue - handle declared as an opaque type
*/
q deleteQueue(q *queue);

#endif
