#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> noDupStack;

        // Iterate through the string and process each character
        for (char c : s) {
            if (!noDupStack.empty() && noDupStack.top() == c) {
                noDupStack.pop(); // Remove adjacent duplicate
            } else {
                noDupStack.push(c); // Push non-duplicate character
            }
        }

        // Construct the resulting string from the stack
        string toRet;
        while (!noDupStack.empty()) {
            toRet += noDupStack.top();
            noDupStack.pop();
        }

        // Reverse the string since the stack gives it in reverse order
        reverse(toRet.begin(), toRet.end());

        return toRet;
    }
};
