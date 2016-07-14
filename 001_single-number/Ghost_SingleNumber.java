public class Ghost_SingleNumber {

    public static int singleNumber(int[] nums) {
        int solution = 0;
        for (int num : nums) {
            solution ^= num;
        }
        return solution;
    }

    public static void main(String[] args) {
        int[] nums = new int[] {1, 2, 3, 4, 5, 4, 3, 2, 1};

        int solution = singleNumber(nums);

        System.out.println(solution);
    }
}
