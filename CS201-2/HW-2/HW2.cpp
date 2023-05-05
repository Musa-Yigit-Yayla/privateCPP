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

    //default array functions
     //O(N^3)
    int maxSubSum1(const int a[], int n){
        int maxSum = 0;

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int currSum = 0;

                for(int k = i; k <= j; k++){
                    currSum += a[k];
                }
                if(currSum > maxSum)
                    maxSum = currSum;
            }
        }

        return maxSum;
    }
    //O(N^2)
    int maxSubSum2(const int a[], int n){
        int maxSum = 0;

        for(int i = 0; i < n; i++){
            int currSum = 0;

            for(int j = i; j < n; j++){
                currSum += a[j];

                if(currSum > maxSum)
                    maxSum = currSum;
            }
        }

        return maxSum;
    }

    int maxSumRec(const int a[], int n, int left, int right){
        if(left == right){ //base case
            if(a[left] > 0){
                return a[left];
            }
            else{
                return 0;
            }
        }

        int center = (left + right) / 2;
        int maxLeftSum = this->maxSumRec(a, n, left, center);
        int maxRightSum = this->maxSumRec(a, n, center + 1, right);

        int maxLeftBorderSum = 0, leftBorderSum = 0;
        for(int i = center; i >= left; i--){
            leftBorderSum  += a[i];
            if(leftBorderSum > maxLeftBorderSum){
                maxLeftBorderSum = leftBorderSum;
            }
        }

        int maxRightBorderSum = 0, rightBorderSum = 0;
        for(int j = center + 1; j <= right; j++){
            rightBorderSum += a[j];

            if(rightBorderSum > maxRightBorderSum){
                maxRightBorderSum = rightBorderSum;
            }
        }
        return max3(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
    }

    int maxSubSum3(const int a[], int n){
        return this->maxSumRec(a, n, 0, n - 1);
    }

    int maxSubSum4(const int a[], int n){
        int maxSum = 0, thisSum = 0;

        for(int j = 0; j < n; j++){
            thisSum += a[j];
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
/*
*Musa Yiğit Yayla
*22003108
*/
#include <iostream>
#include "MaxSubsequenceSums.cpp"
#include <vector>
#include <cstdlib>
#include <chrono>

using namespace std;

void generateArray(int n, vector<int>& result);
void displayResults(const vector<int>& results);
void generateArray(int n, int result[]);

const int HIGHEST_ARRAY_SIZE = 500;

int main(){
    MaxSubsequenceSums mss;
    int n = 10000;
    //vector<long long> executionTimes;
    /*vector<int> results; // vector to check results of whether each algorithm are same
    cout << "Would you like to check whether each algorithm yields the same result ? (Y\\N):";
    char preference;
    cin >> preference;
    if(preference != 'Y'){
        preference = 'N';
    }*/

    //vector<int> currArray;
    int currArray[n];
    generateArray(n, currArray);

    auto startTime = std::chrono::steady_clock::now();




        //startTime = std::chrono::system_clock::now();
        int result1 = mss.maxSubSum4(currArray, n);
        //elapsedTime = std::chrono::system_clock::now() - startTime;
    auto endTime = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    cout << duration.count() << endl;
     std::cout << std::chrono::high_resolution_clock::duration::period::den << std::endl;
    //cout << to_string(elapsedTime) << endl;
    //The below loop used to try and retrieve all execution times of varying input sizes for all 4 algorithms
    /*while( n <= HIGHEST_ARRAY_SIZE){
        cout << n << endl;
        generateArray(n, currArray);

        std::chrono::time_point< std::chrono::system_clock > startTime;
        std::chrono::duration< double, milli > elapsedTime;

        startTime = std::chrono::system_clock::now();
        int result1 = mss.maxSubSum1(currArray);
        elapsedTime = std::chrono::system_clock::now() - startTime;

        executionTimes.push_back(elapsedTime.count());

        startTime = std::chrono::system_clock::now();
        int result2 = mss.maxSubSum2(currArray);
        elapsedTime = std::chrono::system_clock::now() - startTime;

        executionTimes.push_back(elapsedTime.count());

        startTime = std::chrono::system_clock::now();
        int result3 = mss.maxSubSum3(currArray);
        elapsedTime = std::chrono::system_clock::now() - startTime;

        executionTimes.push_back(elapsedTime.count());

        startTime = std::chrono::system_clock::now();
        int result4 = mss.maxSubSum4(currArray);
        elapsedTime = std::chrono::system_clock::now() - startTime;

        executionTimes.push_back(elapsedTime.count());

        if(n == 5){
            cout << result1 << endl;
            cout << result2 << endl;
            cout << result3 << endl;
            cout << result4 << endl;
        }

        if(preference == 'Y'){
            results.push_back(result1);
            results.push_back(result2);
            results.push_back(result3);
            results.push_back(result4);
        }
        n *= 10;
    }*/
    /*if(preference == 'Y'){
        displayResults(results);
    }*/
    return 0;
}

//generates an int array with given size filled with random values
void generateArray(int n, vector<int>& result){
    result.clear();
    for(int i = 0; i < n; i++){
        int value = rand();
        value -= INT_MAX / 2;
        result.push_back(value);
    }
    //return result;
}
void generateArray(int n, int result[]){
    for(int i = 0; i < n; i++){
        int value = rand();
        value -= INT_MAX / 2;
        result[i] = value;
    }
    //return result;
}
//Displays the results of the each array ran on each algorithm in a formatted manner
void displayResults(const vector<int>& results){
    static char format[22];
    static int invokeCount = 0; // number of times this method is invoked
    if(invokeCount == 0){
        int currIndex = 0;
        for(int i = 0; i < 4; i++){
            if(i == 0){
                format[currIndex++] = '"';

            }
            format[currIndex++] = '%';
            format[currIndex++] = '-';
            format[currIndex++] = '1';
            format[currIndex++] = '2';
            format[currIndex++] = 'd';
            if(i == 3){
                format[currIndex++] = '"';
            }
        }
    }
    cout << "Results\nAlgorithm1  Algorithm2  Algorithm3  Algorithm4" << endl;
    for(int i = 0; i < results.size(); i++){
        switch(i % 4){
            case 3: printf(format, results.at(i));
             cout << endl; break;
            default: printf(format, results.at(i)); break;
        }
    }
}
//Displays the execution times of the each array ran on each algorithm in a formatted manner
void displayExecutionTimes(const vector<int>& results){
    static char format[22];
    static int invokeCount = 0; // number of times this method is invoked
    if(invokeCount == 0){
        int currIndex = 0;
        for(int i = 0; i < 4; i++){
            if(i == 0){
                format[currIndex++] += '"';

            }
            format[currIndex++] += '%';
            format[currIndex++] += '-';
            format[currIndex++] += '1';
            format[currIndex++] += '2';
            format[currIndex++] += 'd';
            if(i == 3){
                format[currIndex++] += '"';
            }
        }
    }
    cout << "Results\nAlgorithm1  Algorithm2  Algorithm3  Algorithm4" << endl;
    for(int i = 0; i < results.size(); i++){
        switch(i % 4){
            case 3: printf(format, results.at(i));
             cout << endl; break;
            default: printf(format, results.at(i)); break;
        }
    }
}


