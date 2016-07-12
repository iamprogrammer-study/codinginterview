import java.util.Arrays;
import java.util.List;
import java.util.Stack;

public class Ghost_ValidParentheses {

    public static boolean isValid(String inputString) {
        if (inputString == null) {
            return false;
        }

        final Stack<Byte> stack = new Stack<>();
        final byte[] inputBytes = inputString.getBytes();

        for (final byte oneByte : inputBytes) {
            switch (oneByte) {
                case '(':
                case '{':
                case '[':
                    stack.add(oneByte);
                    break;

                case ')':
                    if (stack.isEmpty() || stack.pop() != '(') {
                        return false;
                    }
                    break;

                case '}':
                    if (stack.isEmpty() || stack.pop() != '{') {
                        return false;
                    }
                    break;

                case ']':
                    if (stack.isEmpty() || stack.pop() != '[') {
                        return false;
                    }
                    break;

                default:
                    break;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        final List<String> parentheses = Arrays.asList("", "()", "()[]{}", "(]", "([)]");
        parentheses.stream()
                   .map(i -> isValid(i))
                   .forEach(i -> System.out.println(i));
    }
}
