<sim.h>

/* The event types are as follows: */

#define EV_ARRIVE   0 /* this is when passenger arrives
                         at the airport */
#define EV_AIRLINEQ 1 /* this is when she selects an airline
                         and gets in line to check bags*/
#define EV_AIRLINE  2 /* this is when she gets to the agent
                         to check bags */
#define EV_IDQ      3 /* this is when she enters the line
                         to check her ID */
#define EV_ID       4 /* this is when she gets her ID check */
#define EV_SCANQ    5 /* this is when she gets in line for the scan */
#define EV_SCAN     6 /* this is when she gets to the scanner */
#define EV_TRAINQ   7 /* this is when she is finished being
                         scanned and heads for the train */
#define EV_TRAIN    8 /* this is when she gets off the train
                         and heads for her gate */
#define EV_GATE     9 /* this is when she arrives at the gate */

typedef struct passenger_s passenger_t;
struct passenger_s
{
   double arrival_time; /* gets to the airport */
   double airlineQ_time;
   double airline_time;
   double idQ_time;
   double id_time;
   double scanQ_time;
   double scan_time;
   double trainQ_time;
   double train_time;
   double gate_time;    /* gets to gate */
};

#define MAX_PASS 1000000
int num_passengers 0;
