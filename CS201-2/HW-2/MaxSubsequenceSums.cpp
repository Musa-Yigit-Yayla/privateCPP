/*
*Musa Yiğit Yayla
*22003108
*CS201-1
*
*This problem contains distinct solutions to max subsequence sum problem.
*Later on this problem will be used for time complexity analysis of different approaches.
*/


#include <vector>
#include <cmath>

using namespace std;
class MaxSubsequenceSums{
public:
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
        int maxLeftSum = this->maxSumRec(a, left, center);
        int maxRightSum = this->maxSumRec(a, center + 1, right);

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
        return max3(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
    }

    int maxSubSum3(const vector<int>& a){
        return this->maxSumRec(a, 0, a.size() - 1);
    }

    int maxSubSum4(const vector<int>& a){
        int maxSum = 0, thisSum = 0;

        for(int j = 0; j < a.size(); j++){
            thisSum += a.at(j);
            if(thisSum > maxSum){
                maxSum = thisSum;
            }
            else if(thisSum < 0){
                thisSum = 0;
            }
        }
        return maxSum;
    }
    int max3(int n1, int n2, int n3){
        int result = max(n1, n2);
        return max(result, n3);
    }
};
