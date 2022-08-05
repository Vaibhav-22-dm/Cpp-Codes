#include <bits/stdc++.h>
using namespace std;

vector<int> find_maxs(int a[], int n, int k){
    vector<int> v;
    int i = 0;
    list<int> q;
    if(k==1){
        for(int i=0;i<n;i++) v.push_back(a[i]);
        return v;
    }
    q.push_back(a[0]);
    for(int j=1; j<n; j++){
        while(!q.empty()&&a[j]>q.back()) q.pop_back();
        q.push_back(a[j]);
        if(j==k-1) v.push_back(q.front());
        if(j>=k){
            if(a[i]==q.front()) q.pop_front();
            v.push_back(q.front());
            i++;
        }
    }

    return v;
}

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> output;
    int i=0;
    int j=0;
    list<int> l;
    while(j<nums.size())
    {
        if(l.empty()){ 
            l.push_back(nums[j]);   
        }
        else
        {
            while(!l.empty() && l.back()<nums[j]){
                l.pop_back();
            }
            l.push_back(nums[j]);               
        }
        if(j-i+1<k)
            ++j;
        else if(j-i+1==k)
        {
            output.push_back(l.front());
            if(nums[i]==l.front())
                l.pop_front();
            ++i;
            ++j;
        }
    }
    return output;
    
}

void swap(int* a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void heapify(vector<int>& a, int n, int i){
    int largest = i;
    int l = 2*i+1;
    int r = l+1;
    if(l<n&&a[largest]<a[l]) largest = l;
    if(r<l&&a[largest]<a[r]) largest = r;
    if(largest!=i){
        swap(a[i],a[largest]);
        heapify(a,n,largest);
    }
    return;
}

void maxHeap(int arr[], int n, int k){
    vector<int> a;
    vector<int> v;
    for(int i=0;i<k;i++) a.push_back(arr[i]);
    for(int i=k/2;i>=0;i--) heapify(a,k,i);
    v.push_back(a[0]);

}

int main(){
    int a[11] = {1, 3, -1, 2, -5, -6, 11, -3, 2, 21, 22};
    int k = 4;
    int n = sizeof(a)/sizeof(a[0]);
    vector<int> b = {1, 3, -1, 2, -5, -6, 11, -3, 2, 21, 22};
    vector<int> l = find_maxs(a, n, k);
    for(auto i: maxSlidingWindow(b, k)) cout << i << " "; 
    cout << endl;
    for(auto i: l) cout << i << " "; 



    return 0;
}