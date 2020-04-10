/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.

 

Example:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.

*/

//Solution Using array to store stack elements

class MinStack {
private:
        int size = -1;
        int stack[100000] = {0};
        int min_stack_size = -1;    
        int min_stack[100000] = {0};
        
public:
    /** initialize your data structure here. */
    
    MinStack() {}
    
    void push(int x) {
        if(size == -1 || x <= min_stack[min_stack_size])
            min_stack[++min_stack_size] = x;
    
        stack[++size] = x;
    }
    
    void pop() {
        if(stack[size] == min_stack[min_stack_size])
            min_stack_size--;
        size--;
    }
    
    int top() {
        return stack[size];
    }
    
    int getMin() {
        return min_stack[min_stack_size];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
 
/*
Complexity analysis
Time: O(1) for each operation
Space: O(N)
*/
