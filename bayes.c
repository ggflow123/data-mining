// This program implements naive algs
// Xuran Wang & Yuanzhe Liu
// Nov 17 2018
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define VAR_SIZE 14
#define M_PI 3.14159265358979323846
#define SMALL 0.00000000000000000001
int train_data_s;// the size of total input train data
int test_data_s;// the size of total test data

double * mean_value_1(int c, int train_data_s, int **train_d, int *f_train, double *list)
{
	int array_1[train_data_s];
	int array_2[train_data_s];
	int count_1 = 0;
	int count_2 = 0;
	double s1 = 0;
	double s2 = 0;
	int i = 0;
//	double list[4];
//separating the data with the last column tag: either 1 or 0
	for(i = 0; i < train_data_s; i++){
		if(f_train[i] == 0)//if the tag is 0
		{
		array_1[count_1] = train_d[i][c];
		count_1++;
		}
		if(f_train[i] == 1)//if the tag is 1
		{
		    array_2[count_2] = train_d[i][c];
		    count_2++;
		}
	}

	int sum = 0;
	double sum2 = 0;
	i = 0;

	for(i = 0; i < count_1; i++){
	sum = sum + array_1[i];
	}   
//calculating the mean with the tag 0
	double mean_1 = (double) sum/count_1;
	list[0] = mean_1;
//calculating the standard deviation with the tag 0
	i = 0;
	double temp = 0;
	for(i = 0; i < count_1; i++){
	    temp = (double) array_1[i] - mean_1;
	    sum2 = sum2 + temp * temp;
	}
	double t1 = (double) sum2/ count_1;
	s1 = sqrt(t1);
	list[1] = s1;
//calculating the mean with the tag 1
	i = 0;
	sum = 0;
	sum2 = 0;
	for(i = 0; i < count_2; i++){
	sum = sum + array_2[i];
	}
	double mean_2 = (double) sum/count_2;
	list[2] = mean_2;

//calculating the standard deviation with the tag 1
	i = 0;
	for(i = 0; i < count_2; i++){
	temp = (double) array_2[i] - mean_2;
	sum2 = sum2 + temp * temp;
	}

	double t2 = (double) sum2 / count_2;
	s2 = sqrt(t2);
	list[3] = s2;

	return list;

}

//probability function
double prob(double mean, double s, double v){
    double p;
    //if the standard deviation is 0,return 1 because this column will not funciont 
    if(s == 0)
	return 1;

    p =  (1/sqrt(2*M_PI*(s*s)))*exp((-(v-mean)*(v-mean))/(2*(s*s)));
    return p;
}

//using Naive Bayes Algorithm, based on the probability that we have already calculated, return 1 or 0 to compare to the tag of test data
int naive_bayes_alg(double pr0, double pr1, double *pro1, double *pro2){
    long double posterior1;
    long double posterior2;
    long double ev1 = (long double) pr0;
    long double ev2 = (long double) pr1;
    long double evidence;
    int i;

    for(i = 0; i<VAR_SIZE; i++){
	if(pro1[i] != 0 && pro2[i] != 0){
	ev1 = (long double) ev1 * pro1[i];
        ev2 = (long double) ev2 * pro2[i];
//	printf("ev1:%Lf, ev2:%Lf, pro1: %f, pro2: %f\n", ev1, ev2, pro1[i], pro2[i]);
	}
    }
    evidence = ev1 + ev2;

    posterior1 = ev1/evidence;
    posterior2 = ev2/evidence;

    if(posterior1 > posterior2)
	return 0;
    if(posterior1 == posterior2)
	return 0;
    if(posterior1 < posterior2)
	return 1;

    return 0;
}

//main function
int main(int argc, char **argv){
    int i;
    int j;



    // deal with user input
    char *file_train;
    char *file_test;
   // int k;// the nearest k neighbors
    if(argc!=5){
	printf("Invalid Input");
	exit(1);
    }
    else{
	file_train=argv[1];
	train_data_s=atoi(argv[2]);
	file_test=argv[3];
	test_data_s=atoi(argv[4]);
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

    //set up the count for the last column, which is the tag
    int count1 = 0;
    int count2 = 0;
    for(i = 0; i < test_data_s; i++){
	if(f_test[i] == 0)
	    count1++;
	if(f_test[i] == 1)
	    count2++;
    }

    double list[4];

  //  printf("count1, count2: %d, %d\n", count1, count2);

    double pr0 = (double) count1 / test_data_s;
    double pr1 = (double) count2 / test_data_s;

 //   printf("pr0: %f, pr1: %f\n", pr0, pr1);

    double m1[VAR_SIZE];
    double m2[VAR_SIZE];
    double st1[VAR_SIZE];
    double st2[VAR_SIZE];

    for(i = 0; i < VAR_SIZE; i++){
    double *ptr = mean_value_1(i, train_data_s, train_d, f_train, list);
    double mean_1 = *ptr;
    m1[i] = mean_1;
    double mean_2 = *(ptr + 1);
    m2[i] = mean_2;
    double s1 = *(ptr + 2);
    st1[i] = s1;
    double s2 = *(ptr + 3);
    st2[i] = s2;
    //printf("four value: %f, %f, %f, %f\n", mean_1, mean_2, s1, s2);
    }

    double pro1[VAR_SIZE]; // to record the probability with the tag of 0
    double pro2[VAR_SIZE]; // to record the probability with the tag of 1
    int right=0;
    for(i = 0; i < test_data_s; i++){
	for(j = 0; j < VAR_SIZE; j++){
	   double mean_1 = m1[j];
	   double s_1 = st1[j];
	   double mean_2 = m2[j];
	   double s_2 = st2[j];
	   double v = (double) test_d[i][j];
	  //  printf("%f, %f, %f\n ", mean_1, s_1, v);
	   double p1 = prob(mean_1, s_1, v);
	   double p2 = prob(mean_2, s_2, v);
	   pro1[j] = p1;
	   pro2[j] = p2;
	}
	int train_r = naive_bayes_alg(pr0, pr1, pro1, pro2);
	if(train_r == f_test[i]){
	    right++;
	}
    }
    
    printf("%f",(double)right/test_data_s);



    // record how many data in test dataset has the same value as using the training dataset
    // deal with queries
/*    for(i=0;i<test_data_s;i++){
	int train_r=class_alg(test_d[i], k, train_d, f_train);
	//printf("%d\n", train_r);
	if(train_r==f_test[i]){
	    right++;
	}
    }
    printf("%f",(double)right/test_data_s);
*/


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

