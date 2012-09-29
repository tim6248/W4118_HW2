#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../android-goldfish-2.6.29/include/linux/prinfo.h" 

int main()
{
	struct prinfo *buf;
	int nr;
	int rc;

	nr = 100;
	buf = malloc(sizeof(struct prinfo) * nr);

	rc = syscall(223, buf, &nr);

//	printf("I did not crash i am a god");

	int i;
	for (i = 0; i < nr; i++) {
		struct prinfo p = buf[i];
				//printf("%s\n", buf[i].comm);
	}

	printf("\nTotal entries: %d\n", rc);
	return 0;
}

void print_tree(struct prinfo *tree, int size){
	int id_stack[size] = { 0 };
	int num_tabs = 0;
	int i = 0;
	for(int i = 0; i < size; i++){
		while(tree[i].parent_id != id_stack[num_tabs]){
			num_tabs--;
		}
		print_prinfo(num_tabs, tree[i]);
		num_tabs++;
		id_stack[num_tabs] = tree[i].pid;
	}
	
}

void print_prinfo(int count, struct prinfo p){
	char returned[count+1];
	int i = 0;
	for(i=0; i<count; i++)
		returned[i] = '\t'; 
	returned[count] = '\0';
	printf("%s %s,%d,%ld,%d,%d,%d,%ld\n", &returned, p.comm, p.pid, p.state,
			p.parent_pid, p.first_child_pid, p.next_sibling_pid, p.uid);

}
