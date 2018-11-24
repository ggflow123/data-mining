// This program implements k-nearest-neighbor algs
// Xuran Wang
// Nov 17 2018
#include<stdlib.h>
#include<stdio.h>
#define VAR_SIZE 14
void class_alg(void *kd,float q[],int k);

int main(int argc, char **argv){
    int i;
    int j;
    // deal with user input
    int data_size;// the size of total input data
    float *q=(float *)malloc(sizeof(float)*VAR_SIZE);
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
    float *line[data_size];
    for(i=0;i<data_size;i++){
	line[i]=(float *)malloc(sizeof(float)*VAR_SIZE);
    }
    for(i=0;i<data_size;i++){
	for(j=0;j<VAR_SIZE;j++){
	    int temp;
	    scanf("%d, ",&temp);
	    *(line[i]+j)=temp*1.0;
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

void class_alg(float q[],int k){
    int c0=0;
    int c1=0;
    if(kd_res_size(result)>0){
	printf("%d\n",kd_res_size(result));
	while(!kd_res_end(result)){
	    float *pos=malloc(sizeof(float)*VAR_SIZE);
	    int *pch = kd_res_itemf(result,pos);
	    if(*pch==0){
		c0++;
	    }
	    else{
		c1++;
	    }
	    kd_res_next(result);
	}
    }
    if(c0>c1){
	printf("0\n");
    }
    else{
	printf("1\n");
    }
    kd_res_free(result);
}
