class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 返回满足条件的最大的x。
     * @param a int整型 代表题意中的a
     * @param b int整型 代表题意中的b
     * @param n int整型 代表题意中的n
     * @return int整型
     */
    int solve(int a, int b, int n) {
        int i = 0;
        for(i = n; i >= 0; i--) {
            if(i % a == b) {
                return i;
            }
        }
        return i;
    }
};