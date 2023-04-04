/*   
Remainder on dividing by 11

Given a big positive number x represented as string, find value of x % 11 or x mod 11. Output is expected as an integer.

Example 1:

Input: x = 1345
Output: 3
Explanation: 1345 % 11 = 3 */



class Solution
{
public:
    int xmod11(string x)
    {
        int len = x.length(); 
        int num, rem = 0, i = 0; 
 
    for (; i<len; i++) 
    { 
        num = rem * 10 + (x[i] - '0'); 
        rem = num % 11; 
    } 
    return rem; 
    }
};