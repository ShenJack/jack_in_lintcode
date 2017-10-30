#include <vector>
#include "iostream"

using namespace std;

/*假设一个旋转排序的数组其起始位置是未知的（比如0 1 2 4 5 6 7 可能变成是4 5 6 7 0 1 2）。
你需要找到其中最小的元素。
 * sample input [4,5,6,7,0,1,2]
 *       output 0 */


int findMin(vector<int> nums) {
    unsigned int first = 0;
    unsigned int end = nums.size() - 1;
    unsigned int middle = (first + end)/2;
    while (true){
        middle = (first + end)/2;
        if(end - first == 1){
            if(nums.at(first)> nums.at(end)){
                return nums.at(end);
            } else{
                return nums.at(first);
            }
        } else if( end == first){
            return nums.at(end)>nums.at(first)?nums.at(first):nums.at(end);
        }


        if(nums.at(first) <= nums.at(end)){
            return nums.at(first);
        } else{
            /*first > end : Has been changed*/
            if(nums.at(middle) < nums.at(first)){
                /*断点在 middle之前*/
                end = middle;
            } else{
                first = middle;
            }
        }
    }
}
int main() {
    vector<int > numVector;
    for (int t = 0; t < 10; ++t) {
        for (int i = t; i < 10; ++i) {
            numVector.push_back(i);
        }
        for (int i = 0; i < t; ++i) {
            numVector.push_back(i);
        }
        for (int j = 0; j < numVector.size(); ++j) {
            cout<<numVector.at(j) << " ";
        }
        cout<<endl;

        cout << findMin(numVector) << endl;
        numVector.clear();
    }
    return 0;
}
