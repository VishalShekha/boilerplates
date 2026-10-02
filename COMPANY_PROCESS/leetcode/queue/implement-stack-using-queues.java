class MyStack {

    Queue<Integer> qu1;
    Queue<Integer> qu2;
    public MyStack() {
        qu1 = new LinkedList<>();
        qu2 = new LinkedList<>();
    }
    
    public void push(int x) {
        while(!qu1.isEmpty()){
            qu2.add(qu1.remove());
        }
        qu1.add(x);
        while(!qu2.isEmpty()){
            qu1.add(qu2.remove());
        }
    }
    
    public int pop() {
        return qu1.remove();
    }
    
    public int top() {
        return qu1.peek();
    }
    
    public boolean empty() {
        return qu1.isEmpty();
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */