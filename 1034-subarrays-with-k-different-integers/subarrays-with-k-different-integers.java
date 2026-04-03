class Solution {
    public int atMost(int[] nums, int k) {
   
        int left=0;
        int count=0;
        HashMap<Integer,Integer>freq=new HashMap<>();
        for(int right=0;right<nums.length;right++){
            freq.put(nums[right], freq.getOrDefault(nums[right], 0) + 1);
            while(freq.size()>k){
                freq.put(nums[left], freq.get(nums[left])-1);

            if(freq.get(nums[left])==0){
                freq.remove(nums[left]);
            }
            left++;
        }
        count+=right-left+1;
    }
    return count;
    }
    int subarraysWithKDistinct(int[] nums,int k){
        return(atMost(nums,k)-atMost(nums,k-1));

    }
}