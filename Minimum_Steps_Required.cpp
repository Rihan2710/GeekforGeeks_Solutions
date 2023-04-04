/*
Minimum Steps Required

Given a string str consisting of only two characters 'a' and 'b'. You need to find the minimum steps required to make the string empty by removing consecutive a's and b's.

Example 1:

Input:
str = "bbaaabb"
Output:
2
Explanation:
Operation 1: Removal of all a's modifies str to "bbbb".
Operation 2: Removal of all remaining b's makes str
empty.
Therefore, the minimum number of operations required
is 2. */



Code :

int minSteps(string str) 
{
    int op_count=1, i=1;
    for(;i<str.size();i++)
    {
        if(str[i]!=str[i-1])
        {
            op_count++;
        }
    }
    return (op_count/2)+1;
}