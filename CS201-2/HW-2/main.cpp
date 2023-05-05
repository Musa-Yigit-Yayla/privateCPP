#include <iostream>
#include "MaxSubsequenceSums.cpp"
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> generateArray(int n);
const int HIGHEST_ARRAY_SIZE = 5000000;

int main(){
    MaxSubsequenceSums mss;
    int n = 5;
    vector<long long> executionTimes;
    vector<int> results; // vector to check results of whether each algorithm are same
    cout << "Would you like to check whether each algorithm yields the same result ? (Y\N):";
    char preference;
    cin >> preference;
    if(preference != 'Y'){
        preference = 'N';
    }

    while( n <= HIGHEST_ARRAY_SIZE){
        vector<int> currArray = generateArray(n);

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

        if(preference == 'Y'){
            results.push_back(result1);
            results.push_back(result2);
            results.push_back(result3);
            results.push_back(result4);
        }
        n *= 2;
    }
    if(preference == 'Y'){
        displayResults(results);
    }
    return 0;
}

//generates an int array with given size filled with random values
vector<int> generateArray(int n){
    vector<int> result;
    for(int i = 0; i < n; i++){
        int value = rand();
        value -= INT_MAX / 2;
        result.push_back(value);
    }
    return result;
}
//Displays the results of the each array ran on each algorithm in a formatted manner
void displayResults(const vector<int>& results){
    static char format[10];
    static int invokeCount = 0; // number of times this method is invoked
    if(invokeCount == 0){
        int currIndex = 0;
        for(int i = 0; i < 4; i++){
            if(i == 0){
                format[currIndex++] += '\\';

            }

            if(i == 3){

            }
        }
    }
    printf()
}
