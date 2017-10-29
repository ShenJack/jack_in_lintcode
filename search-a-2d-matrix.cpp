//
// Created by sjjkk on 2017/10/27.
//
#include <iostream>
#include <vector>

using namespace std;
int find(vector<vector<int>> listlist,int position){
    int n = position / listlist.at(0).size();
    int m = position % listlist.at(0).size();

    return listlist.at(n).at(m);
}

bool searchMatrix(vector<vector<int>> &A, int target) {
    if(A.size() == 0){
        return false;
    } else if(A.at(0).size() == 0){
        return false;
    }
    int size = A.size() * A.at(0).size();
    if(A.empty()){
        return 0;
    }
    unsigned int min = 0;
    unsigned int max = size - 1;
    unsigned int middle = max/2;
    while (true){

        if(find(A,min) > target){
            return false;
        } else if(find(A,max) < target){
            return false;
        }

        if(find(A,max) == target){
            return true;
        } else if(find(A,middle) == target){
            return true;
        } else if(find(A,min) == target){
            return true;
        }
        if(max - min <= 1){
            if(find(A,max)==target){
                return true;
            } else return find(A, min) == target;
        }
        if(find(A,middle) < target && find(A,max) > target){
            min = middle;
            middle = (min + max)/2;
        } else if (find(A,min) < target && find(A,middle) > target){
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



    vector<vector<int>> initDouble;
    initDouble.push_back(intList);
    std::cout << 11 << " -> " << searchMatrix(initDouble, 11) << std::endl;
    for (unsigned int j = 0; j < 12; ++j) {
        std::cout << j << " -> " << searchMatrix(initDouble, j) << std::endl;
    }

//    for (int i = 1; i < 200; i += 20) {
//        std::cout << i << " -> " << searchInsert(<#initializer#>, i) << std::endl;
//    }
    return 0;
}
