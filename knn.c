// This program implements k-nearest-neighbor algs
// Xuran Wang
// Nov 17 2018
#include<stdlib.h>
#include<stdio.h>
#define VAR_SIZE 14
void class_alg(int q[],int k);

int main(int argc, char **argv){
    int i;
    int j;
    // deal with user input
    int data_size;// the size of total input data
    int *q=(int *)malloc(sizeof(int)*VAR_SIZE);
    int k;// the nearest k neighbors
    if(argc!=4){
	printf("Invalid Input");
	exit(1);
    }
    else{
	data_size=atoi(argv[1]);
	for(j=0;j<VAR_SIZE;j++){
	    int temp;
	    sscanf(argv[2],"%d, ",&temp);
	    q[j]=temp*1.0;
	}
	k=atoi(argv[3]);
    }

    int *f_x=malloc(sizeof(int)*data_size);// create an array of function value
    //int *train_d=(int *)malloc(sizeof(int*)*VAR_SIZE*data_size);

    // deal with input data from stdin(add each training example to train_d
    int *line[data_size];
    for(i=0;i<data_size;i++){
	line[i]=(int *)malloc(sizeof(int)*VAR_SIZE);
    }
    for(i=0;i<data_size;i++){
	for(j=0;j<VAR_SIZE;j++){
	    int temp;
	    scanf("%d, ",&temp);
	    *(line[i]+j)=temp;
	    //printf("%f ", *(line[i]+j));
	}
	scanf("%d,",f_x+i);
    }

    // deal with queries

    class_alg(q,k);

    //free all kinds of stuff
    for(i=0;i<data_size;i++){
	free(line[i]);
    }
    free(f_x);
    free(q);

}

void class_alg(int q[],int k){
    int c0=0;// count the number of neighbors that has a value of 0
    int c1=0;// count the numbef of neighbors that has a value of 1
    int *nei=malloc(sizeof(int)*k);// save the nearest k neighbors
    int i;
    for(i=0;i<k;i++){
	int j;
	int min_d=d(0);// the minimum distance
	int last_dist=0;// the last minimum distance
	for(j=0;j<data_size;j++){
	    int dist;
	    if(dist<min_d&&dist>=last_dis){
		last_dis=min_d;
		min_d=dist;
	    }
	}
    }

    if(c0>c1){
	printf("0\n");
    }
    else{
	printf("1\n");
    }
}

double d(int q1[], int q2[]){// this function calculate the distance between two points
}
