#include <stack>          // std::stack

using std::stack;

//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

class Solution {
public:
    bool isValid(string str) {
        stack<char> * openBracket = new stack<char>();
        stack<char> * closeBracket = new stack<char>();
        bool returnVal = true;
        
        for ( int i = 0 ; i < str.length(); i++) {
            if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
                openBracket->push(str[i]);
            } else if (str[i] == ')') {
                if (!openBracket->empty() && openBracket->top() == '(') {
                    openBracket->pop();
                } else {
                    returnVal = false;
                    break;
                }
            } else if (str[i] == '}') {
                if (!openBracket->empty() && openBracket->top() == '{') {
                    openBracket->pop();
                } else {
                    returnVal = false;
                    break;
                }
            } else if (str[i] == ']') {
                if (!openBracket->empty() && openBracket->top() == '[') {
                    openBracket->pop();
                } else {
                    returnVal = false;
                    break;
                }
            }
            
            cout << i << str[i] ;
        }
        
        returnVal = returnVal && (openBracket->empty());
        
        delete openBracket;
        return returnVal;
    }
};
