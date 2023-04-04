// User function Template for C++

class Solution {
  public:
    long long int minOperations(int N) {
        long long int result = N/2;
        result*=(N+1)/2;
        return result;
    }
};