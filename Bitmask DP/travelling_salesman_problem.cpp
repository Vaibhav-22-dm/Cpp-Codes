/*
Problem Statement
Given a set of cities and distance between every pair of cities as an adjacency matrix, the problem is to find the shortest possible route that visits every city exactly once and returns to the starting point.

Approach -

In travelling salesman problem algorithm, we take a subset N of the required cities that need to be visited, the distance among the cities dist, and starting city s as inputs. Each city is identified by a unique city id which we say like 1,2,3,4,5………n

Here we use a dynamic approach to calculate the cost function Cost(). Using recursive calls, we calculate the cost function for each subset of the original problem.

To calculate the cost(i) using Dynamic Programming, we need to have some recursive relation in terms of sub-problems.

We start with all subsets of size 2 and calculate C(S, i) for all subsets where S is the subset, then we calculate C(S, i) for all subsets S of size 3 and so on.

There are at most O(n2^n) subproblems, and each one takes linear time to solve. The total running time is, therefore, O(n^22^n). The time complexity is much less than O(n!) but still exponential. The space required is also exponential.

*/


#include <bits/stdc++.h>
using namespace std;


void mincost(int i){
    return;
}

int main(){
    int n = 4;
    int ary[3][3];
    ary[0][0] = 0;
    ary[0][1] = 4;
    ary[0][2] = 1;
    ary[1][0] = 4;
    ary[1][1] = 0;
    ary[1][2] = 2;
    ary[2][0] = 1;
    ary[2][1] = 2;
    ary[2][1] = 0;
    
    long long int vis = 0;
    mincost(0);

    return 0;
}