//
// Created by sjjkk on 2017/10/29.
//
#include "iostream"
#include <vector>

using namespace std;
int findAhead(vector<int> &array, int position);

int binarySearch(vector<int> &array, int target) {
    // write your code here
    int min = 0;
    int max = array.size() - 1;
    int middle = (min + max)/2;
    while (true){
        if(array.at(min)>target || array.at(max) < target){
            return -1;
        }
        if(array.at(min) == target){
            return  findAhead(array,min);
        } else if(array.at(max)==target){
            return findAhead(array,max);
        }

        if(max - min <= 1){
            return -1;
        }

        if(array.at(middle)>target){
            max = middle;
            middle = (min + max)/2;
        } else if(array.at(middle)<target){
            min = middle;
            middle = (min + max)/2;
        } else{
            return findAhead(array,middle);
        }
    }
    return -1;
}

using namespace std;
int main(){
    vector<int> vector1;
    vector1.push_back(1);
    vector1.push_back(2);
    vector1.push_back(5);
    vector1.push_back(5);
    vector1.push_back(5);
    vector1.push_back(6);
    vector1.push_back(6);
    vector1.push_back(7);
    vector1.push_back(7);
    vector1.push_back(8);
    vector1.push_back(10);

    for (int i = 0; i < vector1.size(); ++i) {
        cout<<vector1.at(i)<<" ";
    }
    cout<<endl;
    for (int i = 0; i < vector1.size(); ++i) {
        cout<<i<<" ";
    }
    cout<<endl;

    for (int j = 0; j < 18; ++j) {
        cout<<j<< " -> "<<binarySearch(vector1, j)<<endl;
    }
    return 0;
}

/* return the first position of the number in the current position*/

int findAhead(vector<int> &array, int position) {
    int target = array.at(position);
    while (position>0 && array.at(position - 1) == target){
        --position;
    }
    return position;
}
