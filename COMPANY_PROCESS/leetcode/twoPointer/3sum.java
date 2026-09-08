class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        List<List<Integer>> result = new ArrayList<>();

        for(int i = 0; i < n; i++){
            if(i != 0 && nums[i] ==nums[i-1]) continue;
            int x = i + 1;
            int y = n - 1;

            while(x < y){
                int sum = nums[x] + nums[y] + nums[i];

                if(sum == 0) {
                    result.add(Arrays.asList(nums[i], nums[x], nums[y]));

                    while(x < y && nums[x] ==nums[x+1]) x++;
                    while(x < y && nums[y] ==nums[y-1]) y--;

                    x++; y--;
                } else if(sum < 0) {
                    x++;
                } else {
                    y--;
                }
            }
        }

        return result;
    }
}