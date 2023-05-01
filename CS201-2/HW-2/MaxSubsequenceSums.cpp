/*
*Musa Yiğit Yayla
*22003108
*CS201-1
*
*This problem contains distinct solutions to max subsequence sum problem.
*Later on this problem will be used for time complexity analysis of different approaches.
*/


#include <vector>

using namespace std;
class MaxSubsequenceSums{
    //O(N^3)
    int maxSubSum1(const vector<int>& a){
        int maxSum = 0;

        for(int i = 0; i < a.size(); i++){
            for(int j = i; j < a.size(); j++){
                int currSum = 0;

                for(int k = i; k <= j; k++){
                    currSum += a.at(k);
                }
                if(currSum > maxSum)
                    maxSum = currSum;
            }
        }

        return maxSum;
    }
    //O(N^2)
    int maxSubSum2(const vector<int>& a){
        int maxSum = 0;

        for(int i = 0; i < a.size(); i++){
            int currSum = 0;

            for(int j = i; j < a.size(); j++){
                currSum += a.at(j);

                if(currSum > maxSum)
                    maxSum = currSum;
            }
        }

        return maxSum;
    }

    int maxSumRec(const vector<int>& a, int left, int right){
        if(left == right){ //base case
            if(a.at(left) > 0){
                return a.at(left);
            }
            else{
                return 0;
            }
        }

        int center = (left + right) / 2;
        int maxLeftSum = this.maxSumRec(a, left, center);
        int maxRightSum = this.maxSumRec(a, center + 1, right);

        int maxLeftBorderSum = 0, leftBorderSum = 0;
        for(int i = center; i >= left; i--){
            leftBorderSum  += a.at(i);
            if(leftBorderSum > maxLeftBorderSum){
                maxLeftBorderSum = leftBorderSum;
            }
        }

        int maxRightBorderSum = 0, rightBorderSum = 0;
        for(int j = center + 1; j <= right; j++){
            rightBorderSum += a.at(j);

            if(rightBorderSum > maxRightBorderSum){
                maxRightBorderSum = rightBorderSum;
            }
        }
    }
};
