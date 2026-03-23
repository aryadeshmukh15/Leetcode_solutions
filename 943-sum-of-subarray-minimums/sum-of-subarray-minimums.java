class Solution {
    public int sumSubarrayMins(int[] arr) {
        int n = arr.length;
        long mod = 1_000_000_007;

        int[] left = new int[n];
        int[] right = new int[n];

        Stack<Integer> stack = new Stack<>();

        // 🔹 Previous Smaller Element (strictly smaller)
        for (int i = 0; i < n; i++) {
            while (!stack.isEmpty() && arr[stack.peek()] > arr[i]) {
                stack.pop();
            }

            if (stack.isEmpty())
                left[i] = -1;
            else
                left[i] = stack.peek();

            stack.push(i);
        }

        stack.clear();

        // 🔹 Next Smaller Element (smaller or equal)
        for (int i = n - 1; i >= 0; i--) {
            while (!stack.isEmpty() && arr[stack.peek()] >= arr[i]) {
                stack.pop();
            }

            if (stack.isEmpty())
                right[i] = n;
            else
                right[i] = stack.peek();

            stack.push(i);
        }

        // 🔹 Calculate answer
        long result = 0;

        for (int i = 0; i < n; i++) {
            long count = (long)(i - left[i]) * (right[i] - i);
            result = (result + arr[i] * count) % mod;
        }

        return (int) result;
    }
}