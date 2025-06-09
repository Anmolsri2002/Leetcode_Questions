class Solution {
public:
    long numOfChildren(long current, long neighbour, long n) {
        if (neighbour > n) {
            if (current > n) return 0;
            return n - current + 1;
        }
        return neighbour - current + numOfChildren(current * 10, neighbour * 10, n);
    }
    int solve(long current, long n, long k) {
        if(k == 0) 
             return (int) (current / 10);

        for (long i = max(current, 1L); i < current + 10; i++) {
            long count = numOfChildren(i, i + 1, n);
            if (count >= k) 
                return solve(i * 10, n, k - 1);
            k-= count;
        }

        return -1;
    }
    int findKthNumber(int n, int k) {
        int ans = solve(0, n, k);
        return ans;
    }
};