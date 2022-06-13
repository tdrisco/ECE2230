/* main.c */
/* initialize queues */
/* malloc new EV_ARRIVE event and passenger */
event_t *start_ev;
start_ev = event_create();
start_ev.passenger = (passenger_t *)malloc(sizeof(passenger_t));
/* schedule EV_ARRIVE event at t=0 and put in event queue */
start_ev.event_time = 0.0;
event_schedule(start_ev);
/* run main loop */
while(!event_empty(eq))
{
    new_ev = event_cause();
    time_set(new_ev.event_time);
    switch (new_ev.event_type)
    {
    case (EV_ARRIVE) :
        new_ev.passenger.arrive_time = time_get();
        /* create EV_ENQUEUE event for this passenger */
        /* schedule EV_ENQUEUE event */
        if (MAX_PASS > num_passengers++)
        {
            /* create new EV_ARRIVE event and passsenger */
            /* schedule EV_ARRIVE event */
        }
        break;
    case (EV_AIRLINEQ) :
        break;
    case (EV_AIRLINE) :
        break;
    case (EV_IDQ) :
        break;
    /* remaining event types */
    default :
        /* error */
        break;
    }
    /* free event */
}
/* Print overall stats */
