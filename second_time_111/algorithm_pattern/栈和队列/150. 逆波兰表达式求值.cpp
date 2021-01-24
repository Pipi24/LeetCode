/*
逆波兰表达式：

逆波兰表达式是一种后缀表达式，所谓后缀就是指算符写在后面。

平常使用的算式则是一种中缀表达式，如 ( 1 + 2 ) * ( 3 + 4 ) 。
该算式的逆波兰表达式写法为 ( ( 1 2 + ) ( 3 4 + ) * ) 。
逆波兰表达式主要有以下两个优点：

去掉括号后表达式无歧义，上式即便写成 1 2 + 3 4 + * 也可以依据次序计算出正确结果。
适合用栈操作运算：遇到数字则入栈；遇到算符则取出栈顶两个数字进行计算，并将结果压入栈中。

时间复杂度：O(N)
空间复杂度：O(N)
*/
class Solution {
public
    int evalRPN(vectorstring& tokens) {
        vectorint v;
        for( auto s  tokens )
        {
            if( s == +  s == -  s ==   s ==  )
            {                            
                int second  = v.back(); v.pop_back();
                int first   = v.back(); v.pop_back();
                if( s == + ){ v.push_back( first + second ); }
                if( s == - ){ v.push_back( first - second ); }
                if( s ==  ){ v.push_back( first  second ); }
                if( s ==  ){ v.push_back( first  second ); }
            }
            else
            {
                v.push_back( stoi(s) );
            }
        }
        return v.back();
    }
};