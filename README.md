# data-mining
This is for 2018 fall semester cs241 final project: Data Mining

## convertDiscrete.py
- This program handle the raw data to discrete data
### The format of edited discrete data
- The sequence is the same as the raw data, with the value need to test at the end of each line of data.
- There are 14 attributes in total.
- They are saved in the adult_edit.csv
- The 15th value in the data file is the function value

## convertDiscreteSplit.py
- Have all the functionalities of convertDiscrete.py
- split the orignial file into train and test data set
- usage: python convertDiscreteSplit.py filename trainingPerc seed
- (these parameters are mandetory or the program will fail. I think we need them to be filled out every time so I just assume that.)
## knn.c
- This program use K-nearest-neighbors algs to check the overall acuracy.
- ./knn &lt;train data file&gt; &lt;train data size&gt; &lt;test data file&gt; &lt;test data size&gt; &lt;k value&gt;

## bayes.c
- This program use Naïve Bayes algorithm to check the overall acuracy.
- Usage: this program assumes five arguments in the command line!
- ./bayes  &lt;train data file&gt; &lt;train data size&gt; &lt;test data file&gt; &lt;test data size&gt;  

## Makefile
- Makefile uses gccx instead of gcc because we are working in clyde. If you want to run it locally, gccx is simply
- gcc -g -pedantic -std=c99 -Wall -Wextra 
- Also, for bayes.c, keep the -lm flag. You want that to compile bayes.c because bayes.c contains math.h

### NEED further modification about
- Validation
