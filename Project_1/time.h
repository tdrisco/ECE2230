/* time.h */

/* creates a double for using as the global sim time */
void time_init();

/* cleans up the time system as needed */
void time_fini();

/* returns the current sim time */
double time_get();

/* sets the current sim time */
void time_set(double t);

/* these return a random time which is used to set the
   time each passenger takes to make each of these steps
   these times are set into the corresponding event
   before it is scheduled. */
double time_arrive();
double time_airline();
double time_id();
double time_scan();
double time_train();
double time_gate(); 
