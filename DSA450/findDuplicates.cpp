#include <bits/stdc++.h>
using namespace std;

void findDuplicates(vector<int>& nums) ;

int main(){
    vector<int> nums = {4,3,2,7,8,2,3,1};
    findDuplicates(nums);
    cout << endl;

    return 0;
}

void findDuplicates(vector<int>& nums) {
    for(int i=0;i<nums.size();i++) cout << nums[i] << " ";
    cout << endl;
    vector<int> nums_hash(nums.size(),0);
    vector<int> nums_twice;
    for(int i = 0; i<nums.size(); i++){
        nums_hash[nums[i]-1]++;
        if(nums_hash[nums[i]-1]==2) nums_twice.push_back(nums[i]);
    }
    for(int i=0;i<nums.size();i++) cout << nums_hash[i] << " ";
    
    for(int i=0; i<nums_twice.size();i++) cout << nums_twice[i] << " ";
    cout << endl;
    return;
        
}