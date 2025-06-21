//Find median in a stream
//https://www.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1?page=1&category=Heap&sortBy=submissions

#include <queue>

class Solution {
  public:
  int signum(int a , int b){
      if(a==b){
          return 0;
      }
      else if(a>b){
          return 1;
      }
      else{
          return -1;
      }
  }
  void call_median(int element, priority_queue<int> &maxheap,
  priority_queue<int , vector<int> , greater<int> > &minheap , double &median){
      switch(signum(maxheap.size(), minheap.size())){
          
          case 0 :
          if(element > median){
              minheap.push(element);
              median = minheap.top();
          }
          else{
              maxheap.push(element);
              median = maxheap.top();
          }
          break;
          
          case 1 :  //n n-1
          if(element > median){  //barabar hojaenge n n 
              minheap.push(element);
              median = (maxheap.top()+ minheap.top())/2.0;
          }
          else{//unequal hojaenge n+1 n-1 -> 2 , soo first take one element into minheap from maxheap
            minheap.push(maxheap.top());
            maxheap.pop();
            maxheap.push(element);
            median = (maxheap.top()+ minheap.top())/2.0;
          }
          break;
          
          case -1 : //n-1 n 
          if(element > median){ //unequal condition n-1 n+1 -> 2 , soo first take one element into maxheap from minheap
              maxheap.push(minheap.top());
              minheap.pop();
              minheap.push(element);
              median = (maxheap.top()+ minheap.top())/2.0;
          }
          else{
              maxheap.push(element);
              median = (maxheap.top()+ minheap.top())/2.0;
          }
          
      }
      
  } 
    vector<double> getMedian(vector<int> &arr) {
        // code here
        int n = arr.size();
        priority_queue<int> maxheap;
        priority_queue<int , vector<int> , greater<int> > minheap;
        vector<double> ans;
        double median = 0.0;
        for(int i = 0; i <n;i++){
            call_median(arr[i] , maxheap , minheap , median);
            ans.push_back(median);
        }
        return ans;
    }
};
