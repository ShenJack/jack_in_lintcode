//
// Created by sjjkk on 2017/10/26.
//
#include <iostream>
#include <vector>
#define True 1

using namespace std;

int searchMatrix(vector<int> &A, int target) {
    int_fast64_t min = 0;
    int_fast64_t max = target;
    int_fast64_t middle = target/2;
    while (true){
        if(max*max == target){
            return max;
        }
        if(max - min <= 1){
            return min;
        }
        if(middle*middle < target){
            min = middle;
            middle = (min + max)/2;
        } else{
            max = middle;
            middle = (min + max)/2;
        }
    }
}

int main() {
    vector<int_fast64_t> intList;

    intList.push_back(999999999);
    intList.push_back(4);

    for (unsigned int j = 0; j < intList.size(); ++j) {
        int_fast64_t num = intList.at(j);
        std::cout << num << " -> " << searchMatrix(<#initializer#>, num) << std::endl;
    }

    for (int i = 1; i < 200; i += 20) {
        std::cout << i << " -> " << searchMatrix(<#initializer#>, i) << std::endl;
    }
    return 0;
}


