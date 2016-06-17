#include <stdio.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <time.h>

#define READY 500
#define MAX 100
#define READ 0
#define WRITE 1
#define PAPER 1
#define SCISSOR 2
#define ROCK 3
int it=1;
int p0[2];
int p1[2];

void my_str(char *buf,int n){
	sprintf(buf,"%d",n);
	
}

/* The signal handler for the child process */
void childSigHandlerC ()
{
	char buf[MAX];
	int t;
	srand(time(NULL));
   	t = 1 + rand() % 3;
    printf("+++ Child C: Generated a random number = %d\n",t);
    my_str(buf,t);
    close(p0[READ]);
	write(p0[WRITE],buf,MAX);
	
    sleep(1);
   	return;
}
void childSigHandlerD ()
{
	char buf[MAX];
	int t;
	srand(time(NULL));
   	t = 1 + rand() % 3;
    printf("+++ Child D: Generated a random number = %d\n",t);
    my_str(buf,t);
    close(p1[READ]);
	write(p1[WRITE],buf,MAX);
	
    sleep(1);
   	return;
}

void give_score(int t1,int t2,float* score_C,float* score_D){
	if(t1==ROCK && t2==SCISSOR){
		(*score_C) = (*score_C)+1;
		printf("--- Parent increases score of Child C by 1 and final score_C = %.1f\n",*score_C);
	}else if(t2==ROCK && t1==SCISSOR){
		(*score_D) = (*score_D)+1;
		printf("--- Parent increases score of Child D by 1 and final score_D = %.1f\n",*score_D);
	}else if(t1==ROCK && t2==PAPER){
		(*score_D) = (*score_D)+1;
		printf("--- Parent increases score of Child D by 1 and final score_D = %.1f\n",*score_D);
	}else if(t2==ROCK && t1==PAPER){
		(*score_C) = (*score_C)+1;
		printf("--- Parent increases score of Child C by 1 and final score_C = %.1f\n",*score_C);
	}else if(t1==SCISSOR && t2==PAPER){
		(*score_C) = (*score_C)+1;
		printf("--- Parent increases score of Child C by 1 and final score_C = %.1f\n",*score_C);
	}else if(t2==SCISSOR && t1==PAPER){
		(*score_D) = (*score_D)+1;
		printf("--- Parent increases score of Child D by 1 and final score_D = %.1f\n",*score_D);
	}else{
		(*score_C) = (*score_C)+.5; (*score_D) = (*score_D)+.5;
		printf("--- Parent increases score of Child C and D by 1 and final score_C = %.1f and score_D = %.1f\n",*score_C,*score_D);
	}
	return;
}

void SIGINT_handler(){
	exit(0);
	return;
}

int main(){
	printf("\n############################################  The Game Starts Now.  ########################################\n\n");
	int i,status,j,temp,t1,t2;
	float pivot_even=0;
	int pids[3];
	char buf[MAX];
	float score_C=0,score_D=0;
	pid_t pid;
	srand(time(NULL));
	pipe(p0); pipe(p1);
	pids[0] = getpid();
	
	if(pids[1]=fork()){ //parent
    	if(pids[2]=fork()){
    	} //parent
    	else {
    		 signal(SIGUSR1, childSigHandlerD);
    		 signal(SIGINT, SIGINT_handler);
     		
      		 while (1){};// D waiting until parent sends signal to terminate
    	}// child2 (D)
	}
	else{
	    signal(SIGUSR1, childSigHandlerC);
	    signal(SIGINT, SIGINT_handler);
     	
      	while (1){};//C waiting until parent sends signal to terminate
	}

	
	while(((int)score_C)<10 && ((int)score_D)<10){
		printf("********************************************  ITERATION -->  %d  **********************************************\n",it++);
		sleep(1);
		kill(pids[1],SIGUSR1);
		sleep(1);
		kill(pids[2],SIGUSR1);
		sleep(2);
		close(p0[WRITE]);
		close(p1[WRITE]);
		read(p0[READ],buf,MAX);
		t1 = atoi(buf);
		read(p1[READ],buf,MAX);
		t2 = atoi(buf);
		give_score(t1,t2,&score_C,&score_D);
		printf("................................................t1 = %d, t2 =  %d, score_C = %.1f, score_D = %.1f \n\n\n\n",t1,t2,score_C,score_D );	
	}
	printf("C terminates.\n");
	kill(pids[1],SIGINT);
	printf("D terminates.\n");
	kill(pids[2],SIGINT);

	if((int)(score_C)==10 && (int)(score_D)==10){
		t1  =  0; t2 = 0;
		while(t1==t2){
			t1 = rand();
			t2 = rand();
		}
		char win = t1>t2 ? 'C' : 'D';
		char loose = t1<t2 ? 'C' : 'D';
		printf("Result:  (score_%c ) > (score_%c ) .... Hence,  %c  WINS !!!\n",win,loose,win);
	}
	else{
		char win = score_C>score_D ? 'C' : 'D';
		float wins = score_C>score_D ? score_C : score_D;
		char loose = score_C<score_D ? 'C' : 'D';
		float looses = score_C<score_D ? score_C : score_D;
		printf("Result:  (score_%c = %.1f) > (score_%c = %.1f) .... Hence,  %c  WINS !!!\n",win,wins,loose,looses,win);
	}
	printf("P terminates.\n");
	exit(0);
	return 0;
}

