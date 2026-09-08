class Solution {
    public int[] twoSum(int[] numbers, int target) {
        for(int i = 0; i < numbers.length; i++){ // O(n)
            int j = Arrays.binarySearch(numbers, target - numbers[i]); // O(log n)
            if(j >= 0) return new int[] {i+1, i!=j ? j+1 : j+2};
        }

        return new int[2];
    }
}