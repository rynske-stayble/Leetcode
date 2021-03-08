class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> Stack;
        for (int i=0; i<s.length(); i++) {
            // std::cout << "1 " << i << s <<std::endl;
            if (s[i] == '(') {
                Stack.push(i);
                // std::cout << "2 " << i << s <<std::endl;
            } else if (s[i] == ')') {
                if (Stack.size() != 0) {
                    Stack.pop();
                    // std::cout << "3 " << i << s <<std::endl;
                } else {
                    s.erase(i,1);
                    i--;
                    // std::cout << "4 " << i << s <<std::endl;
                }
            }
        }
        while (Stack.size() != 0) {
            // std::cout << "5 " << j << " " << Stack.size() <<std::endl;
            s.erase(Stack.top(),1);
            Stack.pop();
        }
        return s;
    }
};
