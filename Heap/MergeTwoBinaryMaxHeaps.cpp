//MergeTwoBinaryMaxHeaps
//https://www.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1?page=1&category=Heap&sortBy=submissions

// User function Template for C++

class Solution {
  public:
    void heapify(vector<int>& arr, int n, int i) {
        int largest = i;
        int left = 2 * i +1;
        int right = 2 * i + 2;

        // check left and right of largest passed
        if (left < n && (arr[largest] < arr[left])) {
            largest = left;
        }
        if (right < n && (arr[largest] < arr[right])) {
            largest = right;
        }

        if (largest != i) { // if largest is updated from i to something else
            swap(arr[largest], arr[i]);
            heapify(
                arr, n,
                largest); // call again to check subtree of largest updated node
        }
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        
        //1->merge both vector , they are already soreted 
        //2->heapify the sorted vector 
        
        //step-1 merge both vectors
        vector<int> ans;
     
        for(auto i:a){
            ans.push_back(i);
        }
        for(auto i:b){
            ans.push_back(i);
        }
        
        int size = ans.size();
        for(int i = size/2-1 ; i>=0 ; i--){
            heapify(ans, size, i);
        }
        return ans;
    }
};