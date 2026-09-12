class Solution {

    public int findsmallest(int nums[], int x, int j){
        for(int i = nums.length -1; i > j; i--){
            if(nums[i] > x) return i;
        }
        return j;
    }

    public void reverseorder(int nums[], int i){
        int j = nums.length - 1;
        while(i < j){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++; j--;
        }
    }

    public void nextPermutation(int[] nums) {
        for(int i = nums.length-1; i > 0; i--){
            if(nums[i-1] < nums[i]){
                int k = findsmallest(nums, nums[i-1], i);
                int temp = nums[k];
                nums[k] = nums[i-1];
                nums[i-1] = temp;
                reverseorder(nums, i);
                return;
            }
        }
        reverseorder(nums, 0);

    }
}