
//this prgram calculates mathmatical problems 
// expressed by postfix notaton
// the notation is for example ab+c* means (a+b)*c
// there are no bracket invloved in postfix expresion 
// that the reason they are usefull specialy in complier technologies 


#include <stack>
#include <cstring>

class postfix
{
    private:
        stack<int> estack;
        char* exp;
    public:
        postfix()
        {
            exp = "#4#2+-";
        }
        postfix(char* ie)
        {
            exp= ie;
        }

        int evaluate(char ope);
        int calculate();

        int do_the_math(int a,int b,char ope);
};

int postfix::calculate()
{
    for(int i = 0;exp[i] !='\0';i++)
    {
        if(exp[i] == '#')
        {
            i++;
            int j = atoi( &exp[i] );
            estack.push(j);
        }
        else if(exp[i] == '=')
             return estack.top();
        else evaluate(exp[i]);
    }
    return -1;
}

int postfix::evaluate(char ope)
{
    int a,b,rst;
    if(!estack.empty()){ 
        a = estack.top();
        estack.pop();
    }else return -1;

    if(!estack.empty()){
        b = estack.top();
        estack.pop();
    }else return -1;
    
    rst = do_the_math(a,b,ope);
    estack.push(rst);

    return 1;
}

int postfix::do_the_math(int a,int b,char ope)
{
    int rst;

    if(ope == '+') 
        rst = b + a;
    else if(ope == '-')
        rst = b - a;
    else if(ope == '*') 
        rst = b*a;
    else if(ope == '/') 
        rst = b/a;

    return rst;
}
