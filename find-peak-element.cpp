#include <iostream>
#include <vector>
using namespace std;
int findPeak(vector<int>& A) {
    unsigned int first = 0;
    unsigned int last = A.size()-1;
    unsigned int middle = (first+last)/2;

    int firstValue = A.at(first);
    int lastValue = A.at(last);
    while (true){
        middle = (first+last)/2;
        int beforeMiddle = A.at(middle-1);
        int pastMiddle = A.at(middle+1);
        int valueMiddle = A.at(middle);
        if(beforeMiddle<valueMiddle && pastMiddle < valueMiddle){
            /* middle 大于 两边*/
            return middle;
        }
        else if(beforeMiddle <valueMiddle && pastMiddle > valueMiddle ){
            /*middle 处于 上坡*/
            first = middle;
        }
        else if(beforeMiddle > valueMiddle && pastMiddle < valueMiddle){
            /*middle 处于 下坡*/
            last = middle;
        } else {
            /*middle 处于 底部*/
            /*middle 小于 两边*/
            if(valueMiddle < firstValue){
                last = middle;
            } else if(valueMiddle < lastValue){
                first = middle;
            } else{
                /*middle 处于谷底 但是 大于 两端*/
                last = middle;
            }
        }
    }
}
int main() {
    vector<int> peakList;
    peakList.push_back(1);
    peakList.push_back(3);
    peakList.push_back(2);
//    peakList.push_back(3);
//    peakList.push_back(7);
//    peakList.push_back(124);
//    peakList.push_back(1);
//    peakList.push_back(2);
//    peakList.push_back(3);
//    peakList.push_back(5);
//    peakList.push_back(4);
//    peakList.push_back(0);

    cout<<findPeak(peakList)<<endl;

    return 0;
}
