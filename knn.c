// This program implements k-nearest-neighbor algs
// Xuran Wang
// Nov 17 2018
#include<stdlib.h>
#include<stdio.h>
#define VAR_SIZE 14
int train_data_s;// the size of total input train data
int test_data_s;// the size of total test data
int class_alg(int q[],int k,int **train_d, int *f_train);
int d(int q1[],int q2[]);


int main(int argc, char **argv){
    int i;
    int j;



    // deal with user input
    char *file_train;
    char *file_test;
    int k;// the nearest k neighbors
    if(argc!=6){
	printf("Invalid Input");
	exit(1);
    }
    else{
	file_train=argv[1];
	train_data_s=atoi(argv[2]);
	file_test=argv[3];
	test_data_s=atoi(argv[4]);
	k=atoi(argv[5]);
    }




    // create array to save these inputs
    int *f_train=malloc(sizeof(int)*train_data_s);
    int *f_test=malloc(sizeof(int)*test_data_s);
    int *train_d[train_data_s];
    for(i=0;i<train_data_s;i++){
	train_d[i]=(int *)malloc(sizeof(int*)*VAR_SIZE);
    }
    int *test_d[test_data_s];
    for(i=0;i<test_data_s;i++){
	test_d[i]=(int *)malloc(sizeof(int*)*VAR_SIZE);
    }




    // deal with input data from files
    FILE *ftr;
    FILE *fte;
    ftr=fopen(file_train,"r");
    fte=fopen(file_test,"r");
    if(ftr==NULL||fte==NULL){
       printf("Error Opening File");
       exit(1);
    }




    // deal with train data    
    for(i=0;i<train_data_s;i++){
	for(j=0;j<VAR_SIZE;j++){
	    fscanf(ftr,"%d, ",train_d[i]+j);
	    //printf("%d ", *(train_d[i]+j));
	}
	fscanf(ftr,"%d",f_train+i);
	//printf("x%d\n",*(f_train+i));
    }




    // deal with test data
    for(i=0;i<test_data_s;i++){
	for(j=0;j<VAR_SIZE;j++){
	    fscanf(fte,"%d, ",test_d[i]+j);
	    //printf("%d ", *(test_d[i]+j));
	}
	fscanf(fte,"%d",f_test+i);
	//printf("x%d\n",*(f_test+i));
    }





    int right=0;// record how many data in test dataset has the same value as using the training dataset
    // deal with queries
    for(i=0;i<test_data_s;i++){
	int train_r=class_alg(test_d[i], k, train_d, f_train);
	//printf("%d\n", train_r);
	if(train_r==f_test[i]){
	    right++;
	}
    }
    printf("%f",(double)right/test_data_s);


    //free all kinds of stuff
    for(i=0;i<train_data_s;i++){
	free(train_d[i]);
    }
    for(i=0;i<test_data_s;i++){
	free(test_d[i]);
    }
    free(f_train);
    free(f_test);

}


int class_alg(int q[],int k,int **train_d, int *f_train){
    int c0=0;// count the number of neighbors that has a value of 0
    int c1=0;// count the numbef of neighbors that has a value of 1
    int *nei=malloc(sizeof(int)*k);// save the index of nearest k neighbors
    int i;
    int j;
    int last_dist=0;// the last minimum distance
    // find the smallest distance
    for(i=0;i<k;i++){
	int min_d;
	int index=0;
	min_d=last_dist;// the minimum distance
	for(j=0;j<train_data_s;j++){
	    int dist=d(q,train_d[j]);
	    if(dist>last_dist){
		if(dist<=min_d){
		    min_d=dist;
		    index=j;
		}
	    }
	    if(dist==last_dist){// check if we have already add it into nei
		int x;
		int isre=0;
		for(x=0;x<k;x++){
		    if(nei[x]==j){
			isre=1;
		    }
		}
		if(isre==0){
		    index=j;
		}
	    }
	}
	nei[i]=index;
    }

    for(i=0;i<k;i++){
	if(f_train[i]==0){
	    c0++;
	}
	else{
	    c1++;
	}
    }

    if(c0>c1){
	return 0;
    }
    else{
	return 1;
    }
}


int d(int q1[], int q2[]){// this function calculate the distance between two points
    int i;
    int sum=0;
    for(i=0;i<VAR_SIZE;i++){
	sum=sum+(q1[i]-q2[i])*(q1[i]-q2[i]);
    }
    return sum;
}

