/* Timothy Driscoll
   ECE 2230 HW 1, 9/6/19

   Program Description: A c program that creates a singly-circular list
   and perfroms the following operations:

   1) Insert the numbers 1-10 at the head of the list
   2) Insert the numbers 21-30 at the tail of the list
   3) Insert the numbers 11-20 in the middle of the list
   4) Remove 5 items at the head of the list
   5) Remove 5 items at the tail of the list
   6) Print the remaining items on the list

*/

//Include the neccesary libraries
#include <stdio.h>
#include <stdlib.h>

// Define the structure which is set up as we defined in class
struct lnode{
  int info;
  struct lnode *link;
};
/*
startNewList: A fucntion that creates the first node in a list (starting it)
    Inputs: struct lnode *end_node - lnode structure pointing to last node
            int info - Represents the data to be stored in the new node
            int *node_countptr - pointer to maintain the length of the list
    Outputs: struct lnode * - Represents the updated end_node pointer
*/
struct lnode *startNewList(struct lnode *end_node, int info, int *node_countptr)
  {
    //Dynamically allocate the memory for a new node
    end_node = (struct lnode *) malloc(sizeof(struct lnode));

    //Set the desired data to the new node
    end_node->info = info;
    //Set the link to itslef thus creating the circle
    end_node->link = end_node;

    //Return the newly created node
    *node_countptr = *node_countptr + 1;
    return end_node;
  }
/*
insertHeadNode: A fucntion that inserts a node at the head of the list
    Inputs: struct lnode *end_node - lnode structure pointing to last node
            int info - Represents the data to be stored in the new node
            int *node_countptr - pointer to maintain the length of the list
    Outputs: struct lnode * - Represents the updated end_node pointer
*/
struct lnode *insertHeadNode(struct lnode *end_node, int info, int *node_countptr)
  {
    //Dynamically allocate memory for the new node
    struct lnode *new_head_node = (struct lnode *) malloc(sizeof(struct lnode));

    //Set the desired data to the new node
    new_head_node->info = info;
    //Set the new_head_node's link to the end_node's link which should always
    //point to the head
    new_head_node->link = end_node->link;
    //Set the end_node's link to the new_head_node (which is the new head)
    end_node->link = new_head_node;

    *node_countptr = *node_countptr + 1;
    return end_node;
  }
/*
insertTailNode: A fucntion that inserts a node at the tail of the list
    Inputs: struct lnode *end_node - lnode structure pointing to last node
            int info - Represents the data to be stored in the new node
            int *node_countptr - pointer to maintain the length of the list
    Outputs: struct lnode * - Represents the updated end_node pointer
*/
struct lnode *insertTailNode(struct lnode *end_node, int info, int *node_countptr)
  {
    //Dynamically allocate memory for the new node
    struct lnode *new_tail_node = (struct lnode *) malloc(sizeof(struct lnode));

    //Set the desired data to the new node
    new_tail_node->info = info;

    //Set new_tail_node's link to the link of the end_node (allowing the new
    //tail to point to the head of the list)
    new_tail_node->link = end_node->link;
    //Now set the old end_node's link to the new_tail_node (end of list)
    end_node->link = new_tail_node;
    //set end_node to new_tail_node so end_node actaully remians the end of the
    //list
    end_node = new_tail_node;

    *node_countptr = *node_countptr + 1;
    return end_node;
  }
/*
insertMiddleNode: A fucntion that inserts a new node to the middle of the list
    Inputs: struct lnode *end_node - lnode structure pointing to last node
            int info - Represents the data to be stored in the new node
            int length - reprsents the length of the list
            int *node_countptr - pointer to maintain the length of the list
    Outputs: no return
*/
void insertMiddleNode(struct lnode *end_node, int info, int length, int *node_countptr)
  {
    int middle_position;
    //Dynamically allocate memory for the new node and rover
    struct lnode *new_middle_node = (struct lnode *) malloc(sizeof(struct lnode));
    struct lnode *rover_node;

    //Calculate middle of the list given length of list if the length is odd
    //add one to the value
    if(length % 2 == 0)
      middle_position = length/2;
    else
      middle_position = (length+1)/2;

    //Set a rover equal to the end_node's link (head of the list)
    rover_node = end_node->link;
    int i = 0;

    for(i = 1; i != middle_position; i++)
      {
        //Advance the rover through the list to the middle position
        rover_node = rover_node->link;
      }

    //Set the desired data to the new node
    new_middle_node->info = info;

    //Assign the new_middle_node's link to where the rover is pointing
    new_middle_node->link = rover_node->link;
    //set the rover's link to the newly inserted middle to re-link the list
    rover_node->link = new_middle_node;
    //set end_node to new_tail_node so end_node actaully remians the end of the
    //list

    //Increment the length counter
    *node_countptr = *node_countptr + 1;
  }
/*
printList: A function that prints the info from the list
    Inputs: struct lnode *end_node - lnode structure pointing to last node
    Outputs: no return
  */
void printList(struct lnode *end_node)
  {
    struct lnode *rover;
    rover = end_node->link;

    do
      {
        printf("%d\n",rover->info);
        rover = rover->link;
      }
    while(rover != end_node->link);
  }
/*
deleteHead: A function that deletes the first node in the linked List
    Inputs: struct lnode *end_node - lnode structure pointing to last node
            int *node_countptr - pointer to maintain the length of the list
    Outputs: struct lnode * - Represents the updated end_node pointer
*/
struct lnode *deleteHead(struct lnode *end_node, int *node_countptr)
  {
    //Create a new lnode pointer
    struct lnode *head_node;
    //Set pointer to the head of the list (Corresponds to the end_node's link)
    head_node = end_node->link;
    //Update the end_node's link to the new head of the list (pointed to by the
    //head_node's link)
    end_node->link = head_node->link;
    //Free the head_node thus deleting it from the list
    free(head_node);
    //Update the length of the list
    *node_countptr = *node_countptr - 1;

    return end_node;
  }
/*
deleteTail: A function that deletes the last node in the linked List
    Inputs: struct lnode *end_node - lnode structure pointing to last node
            int *node_countptr - pointer to maintain the length of the list
    Outputs: struct lnode * - Represents the updated end_node pointer
*/
struct lnode *deleteTail(struct lnode *end_node, int *node_countptr)
  {
    //Intialize neccesary pointer nodes
    struct lnode *rover, *previous;
    //set rover to the begining of the list
    rover = end_node->link;

    //Iterate through the list until reaching the end node
    while(rover->link != end_node->link)
      {
        //make sure previous trails the rover always pointing to the link before
        previous = rover;
        rover = rover->link;
      }

    //Set the previous pointers link to end_node's link thus pointing to the
    //head
    previous->link = end_node->link;
    //Update the end node and free the rover thus deleting the tail
    end_node = previous;
    free(rover);

    //Update the node_count and return the updated end_node
    *node_countptr = *node_countptr - 1;
    return end_node;
  }

int main(void)
{
  //Intialize neccesary variables
  int node_count = 0;
  int *node_countptr = &node_count;
  struct lnode *end_node = NULL;

  //Start the list by creating the first node
  end_node = startNewList(end_node,1,node_countptr);

  int i = 2;
  //Insert 2-11 to the head of the list (1 was inserted when the list was
  //started)
  for(i = 2; i < 11; i++)
    {
      end_node = insertHeadNode(end_node,i,node_countptr);
    }
  //Insert 21-30 to the end of the list
  for(i = 21; i < 31; i++)
    {
      end_node = insertTailNode(end_node,i,node_countptr);
    }
  //insert 11-20 to the middle of the list
  for(i = 11; i < 21; i++)
    {
      insertMiddleNode(end_node,i,*node_countptr,node_countptr);
    }

  printf("\n-------Compelete List After Insertions-------\n");
  printList(end_node);
  printf("---------------------------------------------\n\n");

  //Delete five items from the head then five from the tail
  for(i = 0; i < 5; i++)
    end_node = deleteHead(end_node, node_countptr);
  for(i = 0; i < 5; i++)
    end_node = deleteTail(end_node, node_countptr);

  printf("\n-------Compelete List After Deletions-------\n");
  printList(end_node);
  printf("---------------------------------------------\n\n");


  return 0;
}
