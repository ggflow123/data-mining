// This program implements k-nearest-neighbor algs
// Xuran Wang
// Nov 17 2018
#include<stdlib.h>
#include<stdio.h>
#include"kdtree.h"
#define VAR_SIZE 14

//void class_alg(int query[]);

int main(){
    void *kd = kd_create(VAR_SIZE);// create a kd-tree
    // need to write as vars to take in !!!!!!
    int data_size=40000;
    int *f_x=malloc(sizeof(int)*data_size);
    //int *train_d=(int *)malloc(sizeof(int*)*VAR_SIZE*data_size);
    // deal with input data from stdin(add each training example to train_d)
    int i;
    int j;
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
	scanf("%d, ",f_x+i);
	kd_insertf(kd,line[i],f_x+i);
    }

    // deal with queries

    float q[VAR_SIZE]={33,6,83311,9,13,2,4,0,4,1,0,0,13,39};

    void *result;
    result=kd_nearest_rangef(kd,q,1000.0);
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
    //class_alg(query);

    //free all kinds of stuff
    for(i=0;i<data_size;i++){
	free(line[i]);
    }
    free(f_x);
    kd_res_free(result);
    kd_free(kd);

}

//void class_alg(int query[]);
