/* 
Approach:

Select the range of the unsorted array: Use an outer loop (i) that runs backward from n-1 to 0 (where n is the size of the array). The value i = n-1 means the range is from 0 to n-1, i = n-2 means the range is from 0 to n-2, and so on.
Push the maximum element to the end of the selected range: Use an inner loop (j) that runs from 0 to i-1. Compare adjacent elements and swap them if arr[j] > arr[j+1]. Repeating this process ensures the maximum element in the current range moves to index i.
Progressively sort the array: After each outer loop iteration, the last part of the array becomes sorted. For example:
After the first iteration, the element at the last index is sorted.
After the second iteration, the last two elements are sorted.
This continues until the entire array is sorted.
Complete sorting: After n-1 iterations, the whole array will be sorted.
Note: After each iteration, the sorted portion grows from the end, so the last index of the unsorted range decreases by 1 (controlled by i). The inner loop (j) ensures the maximum element in the range [0…i] is placed at index i.
*/

#include <iostream>
#include <vector>
#include <algorithm>
// #include <chrono>
#include <fstream>

using namespace std;

vector<int> readArrayFromFile(const string& filename = "array.txt") {
    ifstream in(filename);
    vector<int> arr;

    if (!in) {
        cerr << "Error: Could not open " << filename << endl;
        return arr;
    }

    int x;
    while (in >> x) {
        arr.push_back(x);
    }

    in.close();
    return arr;
}


class sortss{
public:
    void bubbleSort(vector<int>& arr){
        int n = arr.size();
        for(int i = n-1; i>0;i--){
            for(int j = 0; j < i;j++){
                if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
            }
        }
    }
};

int main(){
    const int N = 5000;
    vector<int> arrs = readArrayFromFile();
    // vector<int> arrs ={9,8,7,6,5,4,3,2,1};

    sortss a;

    auto start = std::chrono::high_resolution_clock::now();
        a.bubbleSort(arrs);
    auto end = std::chrono::high_resolution_clock::now();

    // for(auto i : arrs) cout<<i<<" ";

    cout<<endl;
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Time taken: " << elapsed.count() << " seconds\n";
    return 0;
}