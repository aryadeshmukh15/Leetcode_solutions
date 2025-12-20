class Solution {
    public int countPrimes(int n) {
        int cnt = 0;
        boolean[] prime = new boolean[n + 1];

        // initially mark all as true
        for (int i = 0; i <= n; i++) {
            prime[i] = true;
        }

        if (n > 0) prime[0] = false;
        if (n > 1) prime[1] = false;

        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                cnt++;
                for (int j = 2 * i; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }
        return cnt;
    }
}
