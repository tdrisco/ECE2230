/* priority.h */
typedef struct priority_s priority_t;

/* create and initialize a new priority queue
   must be able to hold at least size items
   return pointer to the new priority queue, NULL if error */
priority_t *priority_init(int size);

/* insert an item into the priority queue
   return 0 if successful, -1 otherwise */
int priority_insert(priority_t *q, event_t *ev);

/* remove the highest priority item from the queue
   and return it, return NULL if there is an error */
event_t *priority_remove(priority_t *q);

/* return non-zero if the priority queue us empty */
int priority_empty(priority_t *q);

/* return nono-zero if the priority queue is full
   This may be trivial using a linked implementation */
int priority_full(priority_t *q);

/* free all resourced used by the priority queue then free
   the queue itself */
void priority_finalize(priority_t *q);
