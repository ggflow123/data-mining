# data-mining
This is  for 2018 fall semester cs241 final project: Data Mining

## convertDiscrete.py
- This program handle the raw data to discrete data
### The format of edited discrete data
- The sequence is the same as the raw data, with the value need to test at the end of each line of data.
- There are 14 attributes in total.
- They are saved in the adult_edit.csv
- The 15th value in the data file is the function value
## knn.c
- This program use K-nearest-neighbors algs to find the value of a query.
- For the K-d tree to find nearest neighbors, we use the code from https://github.com/jtsiomb/kdtree
- We read the discrete data from stdin.
### how to use it
-  input the data from stdin
- ./knn "the total number of data" "query" "nearest k value" < "input_data"
- the format of query: <value,value,...,value>
### NEED further modification about
- change k from radius of searching scope to "nearest k points"
- maybe should read more than one query from a file in future
