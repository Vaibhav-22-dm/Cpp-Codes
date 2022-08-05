// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


 // } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    
    int tour(petrolPump p[],int n)
    {
       //Your code here
       queue<petrolPump> q;
       for(int i = 0; i < n;i++){
           q.push(p[i]);
       }
       int balance = 0;
       int start = 0;
       int end = 0;
       int i = 0;
       do{ 
           balance += q.front().petrol;
           petrolPump temp = q.front();
           q.push(q.front());
           q.pop();
           cout << "balance: " << balance << " temp.petrol: " << temp.petrol << " temp.distance: " << temp.distance << endl;
           if(balance>=temp.distance){
               cout << "Entered3" << endl;
               start++;
               balance-=temp.distance;
               if(start%n==end) break;
           }
           else{
               cout << "Entered" << endl;
               start++;
               end = start;
               if(end>n-1) {
                   cout << "Entered1" << endl;
                   break;
               }
               balance = 0;
           }
           i++;
           cout << "start: " << start << " end: " << end << " i: " << i << endl;
       }while(end<=n-1);
       if(end>n-1||balance<0||start%n!=end) return -1;
       return end;
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    t = 1;
    while(t--)
    {
        int n;
        n = 13;
        // cin>>n;
        petrolPump p[n];
        // int j[n*2] = {4,6,6,5,7,3,4,5};
        // int j[n*2] = {7, 27, 40, 95, 71, 96, 79, 35, 2, 68, 3, 98, 93, 18, 57, 53, 81, 2, 42, 87, 90, 66, 20, 45, 30, 41};
        int j[n*2] = {24, 48, 32, 88, 23, 33, 76, 82, 80, 51, 55, 91, 32, 51, 58, 14, 82, 95, 4 ,82, 34, 21, 82, 83, 16, 88, 26, 97, 23, 5, 52, 93, 33, 98, 82 ,35};
        int k = 0;
        for (int i = 0; i < n*2; i+=2)
        {
            cout << "(" << j[i] << ", " << j[i+1] << "), ";
        }
        cout << endl;
        for(int i=0;i<n*2;i+=2){
            p[k].petrol= j[i];
            p[k++].distance = j[i+1];
        }
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}
  // } Driver Code Ends
  //87 27 40 95 71 96 79 35 2 68 3 98 93 18 57 53 81 2 42 87 90 66 20 45 30 41