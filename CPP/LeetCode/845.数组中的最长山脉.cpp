class Solution {
public:
    int longestMountain(vector<int>& A) {
        if(A.size() == 0) return 0;
        int high_index = 0, low_index = 0;
        int maxn = 0;
        bool flag = false;
        for(int i = 0 ; i < (int)A.size()-1; i++) {
            if((A[i] < A[i+1] && low_index != 0) || A[i] == A[i+1]) {
                high_index = low_index = 0;
                flag = false;
            }
            if(A[i] < A[i+1]) {
                high_index++;
                flag = true;
            }
            else if(A[i] > A[i+1] && flag) {
                low_index++;
                maxn = max(maxn, high_index+low_index+1);
            }
        }
        return maxn;
    }
};

/* 优秀题解 40ms 88.5%
class Solution {
public:
    int longestMountain(vector<int>& A) {
        int start = -1;
        int ans = 0;
        for (int i = 1; i < A.size(); i++) {
            if (A[i - 1] < A[i]) { // 总是在上升阶段，确定山脉起点 start
                if (i == 1 || A[i - 2] >= A[i - 1]) {
                    start = i - 1;
                }
            } else if (A[i - 1] > A[i]) {
                if (start != -1) {
                    ans = max(ans, i - start + 1); // 总是在下降阶段，计算山脉长度
                }
            } else {
                start = -1; // 平缓期重置起点
            }
        }

        return ans;
    }
};

//作者：geguanting
//链接：https://leetcode-cn.com/problems/longest-mountain-in-array/solution/jian-dan-de-yi-ci-bian-li-by-geguanting/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/