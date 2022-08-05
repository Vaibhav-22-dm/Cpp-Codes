#include <bits/stdc++.h>
using namespace std;

void add(int& subset, int num){
    subset |= 1<<(num-1);
}

void remove(int& subset, int num){
    subset ^= 1<<(num-1);
}

void display(int subset){
    for(int bit_no=0; bit_no<=9; bit_no++){
        // if(1&subset>>bit_no) cout << bit_no+1 << " ";
        if(subset & 1<<bit_no) cout << bit_no+1 << " ";
    }
    cout << endl;
}

int main(){

   /*
    Suppose we want to store subsets of a vector v = {1,2,3,4,5, ... ,N}.
    We can use a set<int> or a vector<int> to store the substets.
    Although there is a better approach to store the subsets. 
    We can use a boolean array of size N, where if ith element is true then ith element in original array is present in this subset.
    2^N such boolean arrays can make up the set of all subsets.
    These boolean arrays can be replaced by N bit number. 
    This is known as  bitmasking.
   */ 

  //Q. Given a set in terms of a bitmask, perform add, remove and display operations on it.
    int st = 15;
    display(st);
    remove(st,3);
    display(st);
    add(st,6);
    display(st);
    return 0;
}