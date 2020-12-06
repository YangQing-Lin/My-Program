/* Program to evaluate candidate routines for Robotic Process Automation.

  Skeleton program written by Artem Polyvyanyy, artem.polyvyanyy@unimelb.edu.au,
  September 2020, with the intention that it be modified by students
  to add functionality, as required by the assignment specification.

  Student Authorship Declaration:

  (1) I certify that except for the code provided in the initial skeleton
  file, the  program contained in this submission is completely my own
  individual work, except where explicitly noted by further comments that
  provide details otherwise.  I understand that work that has been developed
  by another student, or by me in collaboration with other students, or by
  non-students as a result of request, solicitation, or payment, may not be
  submitted for assessment in this subject.  I understand that submitting for
  assessment work developed by or in collaboration with other students or
  non-students constitutes Academic Misconduct, and may be penalized by mark
  deductions, or by other penalties determined via the University of
  Melbourne Academic Honesty Policy, as described at
  https://academicintegrity.unimelb.edu.au.

  (2) I also certify that I have not provided a copy of this work in either
  softcopy or hardcopy or any other form to any other student, and nor will I
  do so until after the marks are released. I understand that providing my
  work to other students, regardless of my intention or any undertakings made
  to me by that other student, is also Academic Misconduct.

  (3) I further understand that providing a copy of the assignment
  specification to any form of code authoring or assignment tutoring service,
  or drawing the attention of others to such services and code that may have
  been made available via such a service, may be regarded as Student General
  Misconduct (interfering with the teaching activities of the University
  and/or inciting others to commit Academic Misconduct).  I understand that
  an allegation of Student General Misconduct may arise regardless of whether
  or not I personally make use of such solutions or sought benefit from such
  actions.

   Signed by: Yuchen Zhu 1174451
   Dated: 30/10/2020

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <string.h>

/* #define's -----------------------------------------------------------------*/

#define ASIZE 26

/* type definitions ----------------------------------------------------------*/

// state (values of the 26 Boolean variables)
typedef unsigned char state_t[ASIZE];

// action
typedef struct action action_t;
struct action {
    char name;        // action name
    state_t precon;   // precondition
    state_t effect;   // effect
};

// step in a trace
typedef struct step step_t;
struct step {
    action_t *action; // pointer to an action performed at this step
    step_t   *next;   // pointer to the next step in this trace
    state_t current_state;
};

// trace (implemented as a linked list)
typedef struct {
    step_t *head;     // pointer to the step in the head of the trace
    step_t *tail;     // pointer to the step in the tail of the trace
} trace_t;

/* function prototypes -------------------------------------------------------*/
trace_t* make_empty_trace(void);
trace_t* insert_at_tail(trace_t*, action_t*);
void free_trace(trace_t*);
int main(int argc, char** argv);
action_t** read_actions(int* length);
action_t* read_action();
int mygetchar();
trace_t* read_trace(action_t** all_action, int num, int* trace_len);
int execute_trace(trace_t* trace, state_t initial_state);

/* my function prototypes ----------------------------------------------------*/

// add your function prototypes here ...

/* where it all happens ------------------------------------------------------*/

/* function definitions ------------------------------------------------------*/

// Adapted version of the make_empty_list function by Alistair Moffat:
// https://people.eng.unimelb.edu.au/ammoffat/ppsaa/c/listops.c
// Data type and variable names changed
trace_t
*make_empty_trace(void) {
    trace_t *R;
    R = (trace_t*)malloc(sizeof(*R));
    assert(R!=NULL);
    R->head = R->tail = NULL;
    return R;
}

// Adapted version of the insert_at_foot function by Alistair Moffat:
// https://people.eng.unimelb.edu.au/ammoffat/ppsaa/c/listops.c
// Data type and variable names changed
trace_t 
*insert_at_tail(trace_t* R, action_t* addr) {
    step_t *new;
    new = (step_t*)malloc(sizeof(*new));
    assert(R!=NULL && new!=NULL);
    new->action = addr;
    new->next = NULL;
    if (R->tail==NULL) { /* this is the first insertion into the trace */
        R->head = R->tail = new; 
    } else {
        R->tail->next = new;
        R->tail = new;
    }
    return R;
}

// Adapted version of the free_list function by Alistair Moffat:
// https://people.eng.unimelb.edu.au/ammoffat/ppsaa/c/listops.c
// Data type and variable names changed
void
free_trace(trace_t* R) {
    step_t *curr, *prev;
    assert(R!=NULL);
    curr = R->head;
    while (curr) {
        prev = curr;
        curr = curr->next;
        free(prev);
    }
    free(R);
}

/* my function definitions ---------------------------------------------------*/

// add your function definitions here ...

int
main(int argc, char *argv[]) {
    char* initial_state;
    int i, j, trace_len=0, action_len=0, valid_action_num;
    action_t** all_action;
    trace_t* trace;
    char c;
    initial_state=(char*)calloc(ASIZE, sizeof(char));
    assert(initial_state != NULL);
    while(scanf("%c\n\r", &c)==1) {
        if (c=='#') {
            break;
        }
        initial_state[c-'a']=1;
    }
    all_action=read_actions(&action_len);
    trace=read_trace(all_action, action_len, &trace_len);
    valid_action_num=execute_trace(trace, initial_state);
    printf("==STAGE 0===============================\n");
    printf("Number of distinct actions: %d\n", action_len);
    printf("Length of the input trace: %d\n", trace_len);
    if (valid_action_num==trace_len) {
        printf("Trace status: valid\n");
    } else {
        printf("Trace status: invalid\n");
    }
    printf("----------------------------------------\n");
    printf("  abcdefghijklmnopqrstuvwxyz\n> ");
    for (i=0; i<ASIZE; i++) {
        printf("%s", &initial_state[i]);
    }
    for (j=0; j<action_len; j++) {
        printf("\n%c ", all_action[i]->name);
    } 
}

action_t**
read_actions(int* action_len) {
    int num;
    action_t* action;
    action_t** all_action;
    all_action=(action_t**)malloc(sizeof(action_t*)*ASIZE);
    assert(all_action != NULL);
    while (read_action()!=NULL) {
        for (num=0; action==read_action(); num++) {
            action=all_action[num];
        }
    }
    *action_len=num;
    return all_action;
}

action_t*
read_action() {
    int i, column=1;
    char c;
    c=mygetchar();
    action_t* action;
    action=(action_t*)malloc(sizeof(action_t));
    assert(action != NULL);
    for (i=0;i<ASIZE;i++) {
        action->precon[i]=action->effect[i]=-1;
    }
    if (c=='#') {
        return NULL;
    }
    while (c != '#' && (c=mygetchar()) != '\r') {
        if (c==':'){
            column+=1;
        } else if (column==1) {
            action->precon[c-'a']=1;
        } else if (column==2) {
            action->precon[c-'a']=0;
        } else if (column==3) {
            action->name=c;
        } else if (column==4) {
            action->effect[c-'a']=1;
        } else if (column==5) {
            action->effect[c-'a']=0;
        } 
    }
    return action;
}

int
mygetchar() {
    char c;
    while ((c=getchar())=='\r') {
    }
    return c;
}

trace_t*
read_trace(action_t** all_action, int num, int* trace_len) {
    int i;
    char c;
    trace_t* trace;
    action_t* action;
    trace=make_empty_trace();
    while((c=mygetchar())!='\n') {
        for (i=0; i<num; i++) {
            if (all_action[i]->name==c) {
                action=all_action[i];
            }
        }
        trace=insert_at_tail(trace, action);
        *trace_len+=1;
    }
    return trace;
}

int
execute_trace(trace_t* trace, state_t initial_state) {
    int i, j, valid=1, valid_action_num=0;
    step_t* temp_step;
    temp_step=trace->head;
    while (temp_step!=NULL) {
        for(i=0; i<ASIZE; i++) {
            if (temp_step->action->precon[i]!=-1) {
                if (temp_step->action->precon[i]!=initial_state[i]) {
                    valid=0;
                }
            }
        }
        if (valid==1) {
            for (j=0; j<ASIZE; j++) {
                if (temp_step->action->effect[i]!=-1) {
                    initial_state[i]=temp_step->action->effect[i];
                    temp_step->current_state[i]=initial_state[i];
                }
                temp_step->current_state[i]=initial_state[i];
            }
            valid_action_num+=1;
            temp_step=temp_step->next;
        } else if (valid!=1) {
            return valid_action_num;
        }
    }
    return valid_action_num;
}


/* ta-da-da-daa!!! -----------------------------------------------------------*/