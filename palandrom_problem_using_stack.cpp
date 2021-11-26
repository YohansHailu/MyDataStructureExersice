#include "stack_problems.cpp"
#include "stack"
class pSolution
{
    public:
        bool is_pal(string x,string y); 
        stack<char> string_to_stack(string s);
}; 

bool pSolution::is_pal(string x,string y)
{
    if( x.size() != y.size())
        return false;
    stack<char> stack_x = string_to_stack(x);
    for(int i = 0; !stack_x.empty(); i++)
    {
        if(stack_x.top() != y[i])
            return false;
        stack_x.pop();
    }

    return true;
    
}
stack<char> pSolution::string_to_stack(string s)
{
    stack<char> result;
    for(int i = 0;i<s.size();i++)
    {
        result.push(s[i]);
    }

    return result;
}
