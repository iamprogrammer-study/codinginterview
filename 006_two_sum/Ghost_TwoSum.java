public class Ghost_TwoSum {
    public int[] twoSum(int[] nums, int target) {
        java.util.Map<Integer, Integer> map = new java.util.HashMap<>();
        for (int idx = 0; idx < nums.length; idx++) {
            int complement = target - nums[idx];
            if (map.containsKey(complement)) {
                return new int[] {map.get(complement), idx};
            }
            map.put(nums[idx], idx);
        }
        throw new IllegalArgumentException("No two sum solution");
    }
}
