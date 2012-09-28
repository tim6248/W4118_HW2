/*
 * ptree.h
 *
 *  Created on: Sep 27, 2012
 */

#ifndef PTREE_H_
#define PTREE_H_

#include <linux/syscalls.h>
#include <linux/sched.h>
#include <linux/list.h>

int do_nothing(void);

/* Stack struct */
struct tasklist {
	struct task_struct *task;
	int depth;
	struct list_head list; /* Linked List */
};


void print_all_pids(void);

/* Prints the pids in a dfs manner */
void print_pids_dfs(void);

/* acquires lock need to browse task */
void acquire_tasklist_lock(void);

void release_tasklist_lock(void);

int no_children(struct task_struct *task);

int has_children(struct task_struct *task);

void print_task(struct task_struct *task, int depth);

int list_size(struct list_head *head);

/*
 * Returns the init process which is the root parent
 * of all processes on the system.
 */
struct task_struct* get_init_process(void);

int is_a_process(struct task_struct *task);

/**
 * play ground test function
 */
void t0(void);
void t1(void);

#endif /* PTREE_H_ */
