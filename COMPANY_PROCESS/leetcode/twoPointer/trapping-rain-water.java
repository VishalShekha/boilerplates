class Solution {
    public int trap(int[] height) {
        int result = 0;

        int i = 0;
        int j = height.length - 1;

        int leftmax = height[i];
        int rightmax = height[j];

        while(i < j){
            if(height[i] < height[j]){
                leftmax = Math.max(height[i], leftmax);
                if(leftmax - height[i] > 0){
                    result += leftmax - height[i];
                }
                i++;
            } else {
                rightmax = Math.max(height[j], rightmax);
                if(rightmax - height[j] > 0){
                    result += rightmax - height[j];
                }
                j--;
            }
        }

        return result;
    }
}