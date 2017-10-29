//
// Created by sjjkk on 2017/10/26.
//
#include <iostream>
#include <vector>
#define True 1

using namespace std;

int searchMatrix(vector<int> &A, int target) {
    if(A.empty()){
        return 0;
    }
    unsigned int min = 0;
    unsigned int max = A.size() - 1;
    unsigned int middle = max/2;
    while (true){

        if(A.at(min) > target){
            return min;
        } else if(A.at(max) < target){
            return max + 1;
        }

        if(A.at(max) == target){
            return max;
        } else if(A.at(middle) == target){
            return middle;
        } else if(A.at(min) == target){
            return min;
        }
        if(max - min <= 1){
            return max;
        }
        if(A.at(middle) < target && A.at(max) > target){
            min = middle;
            middle = (min + max)/2;
        } else if (A.at(min) < target && A.at(middle) > target){
            max = middle;
            middle = (min + max)/2;
        }
    }
}

int main() {
    vector<int> intList;

    intList.push_back(1);
    intList.push_back(4);
    intList.push_back(9);
    intList.push_back(10);
    std::cout << 11 << " -> " << searchMatrix(intList, 11) << std::endl;
    for (unsigned int j = 0; j < 12; ++j) {
        std::cout << j << " -> " << searchMatrix(intList, j) << std::endl;
    }

//    for (int i = 1; i < 200; i += 20) {
//        std::cout << i << " -> " << searchInsert(<#initializer#>, i) << std::endl;
//    }
    return 0;
}


