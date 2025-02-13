class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        //min heap
        priority_queue<long,vector<long>,greater<long>>pq(nums.begin(),nums.end());
        //heapify and put all the elements in heap

        while(!pq.empty() && pq.top() < k){
            long smallestElement = pq.top();
            pq.pop();

            long secondSmallestElement = pq.top();
            pq.pop();

            pq.push(smallestElement * 2 + secondSmallestElement);
            count++;
        }
        return count;
    }
};