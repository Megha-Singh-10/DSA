908. Smallest Range I
/* You are given an integer array nums and an integer k.

In one operation, you can choose any index i where 0 <= i < nums.length and change nums[i] to nums[i] + x where x is an integer from the range [-k, k]. You can apply this operation at most once for each index i.

The score of nums is the difference between the maximum and minimum elements in nums.

Return the minimum score of nums after applying the mentioned operation at most once for each index in it.*/

TCp->O(N)
SC->O(N)

int smallestRangeI(vector<int>& A, int K) {
  return max(0, *max_element(begin(A), end(A)) - K - (*min_element(begin(A), end(A)) + K));
}
