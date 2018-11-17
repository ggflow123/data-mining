// This program implements k-nearest-neighbor algs
// Xuran Wang
// Nov 17 2018
#include<stdlib.h>
#include<stdio.h>

int main(){
    // need to write as vars to take in !!!!!!
    int data_size=4;
    int var_size=15;
    int train_d[var_size][data_size];
    // deal with input data from stdin
    int i;
    int j;
    for(i=0;i<data_size;i++){
	for(j=0;j<var_size;j++){
	    scanf("%d, ",&train_d[j][i]);
	    printf("%d ", train_d[j][i]);
	}
	printf("\n");
    }

}
    //train_alg(train_d);
    //class_alg();
//void train_alg();
//void class_alg();
