public class Ghost_SumOfTwoIntegers {
    public int getSum(int a, int b) {
        while ((a & b) != 0x00) {
            final int x = (a & b) << 1;
            final int y = (a ^ b);
            a = x;
            b = y;
        }
        return a | b;
    }
}
