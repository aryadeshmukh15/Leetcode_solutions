class Solution {
    public boolean isNStraightHand(int[] hand, int groupSize) {
       if (hand.length % groupSize != 0) return false;

        Arrays.sort(hand);

        HashMap<Integer, Integer> freq = new HashMap<>();

        // count frequency
        for (int num : hand) {
            freq.put(num, freq.getOrDefault(num, 0) + 1);
        }

        // try forming groups
        for (int num : hand) {
            if (freq.get(num) == 0) continue;

            // form group starting from num
            for (int i = 0; i < groupSize; i++) {
                int current = num + i;

                if (freq.getOrDefault(current, 0) == 0) {
                    return false;
                }

                freq.put(current, freq.get(current) - 1);
            }
        }

        return true;
    }
}