//912. Sort an Array
//https://leetcode.com/problems/sort-an-array/description/?envType=problem-list-v2&envId=heap-priority-queue

class Solution {
public:
    void heapify(vector<int>& arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
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
    vector<int> sortArray(vector<int>& nums) {
        int size = nums.size();
        //firstly build max heap for input array coz input array is not necessary in max heap order 
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(nums, size, i);
        }
        //then swap last to first, then size--, then heapify again 
        while (size > 1) {
            swap(nums[size - 1], nums[0]);
            size--;
            heapify(nums, size, 0);
        }
        return nums;
    }
};