class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stack;

        // size
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            // check if stack empty
            if (stack.empty())
            {
                stack.push(s[i]);
            }
            else if (stack.top() == '(' && s[i] == ')' ||
                     stack.top() == '{' && s[i] == '}' ||
                     stack.top() == '[' && s[i] == ']')
            {
                stack.pop();
            }
            else
            {
                stack.push(s[i]);
            }
        }

        return stack.empty() ? true : false;
    }
};