import java.util.Arrays;
import java.util.Collection;

public class Ghost_SingleNumber {

    public static int singleNumber(Collection<Integer> numbers) {
        int solution = 0;
        for (Integer number : numbers) {
            solution ^= number;
        }
        return solution;
    }

    public static void main(String[] args) {
        Collection<Integer> numbers = Arrays.asList(1, 2, 3, 4, 5, 4, 3, 2, 1);

        int solution = singleNumber(numbers);

        System.out.println(solution);
    }
}
