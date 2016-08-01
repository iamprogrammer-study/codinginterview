public class Ghost_MinStack {

    private java.util.Stack<Integer> numStack = null;
    private java.util.Stack<Integer> minStack = null;

    public MinStack() {
        numStack = new java.util.Stack<Integer>();
        minStack = new java.util.Stack<Integer>();
    }

    public void push(final int x) {
        numStack.push(x);
        if (minStack.isEmpty()) {
            minStack.push(x);
        }
        else if (minStack.peek() >= x) {
            minStack.push(x);
        }
    }

    public void pop() {
        final int popValue = numStack.pop();
        if (minStack.peek() == popValue) {
            minStack.pop();
        }
    }

    public int top() {
        return numStack.peek();
    }

    public int getMin() {
        return minStack.peek();
    }
}
