# Heaps and Priority Queues
--------------------------

### Language : C++   
### Every input/output uses standard I/O   
   
### Problem 1   
### K Nearest Neighbor(KNN) problem   
To solve KNN problem with priority queue using heap.   
Implemented heap using array.   
   
**EXAMPLE**   
   
**Input**   
Get the integer __X__ and __K__ at the first line. X is a standard value to find the Kth nearest value from it.
From the second line, the program gets the __integers__ to save them in the priority queue in an order from the nearest to the farthest.
If it gets __SHOW_K_TH_NEIGHBOR__ as input, it prints Kth nearest value. 
      
<pre>
35 5   
59   
28   
62   
42   
53   
13   
33   
SHOW_K_TH_NEIGHBOR   
41   
39   
6   
SHOW_K_TH_NEIGHBOR   
EXIT   
</pre>
   
**Output**   
<pre>
13   
42   
</pre>   
      
### Problem 2   
Same task with __Problem 1__, but using stl heap functions.   

