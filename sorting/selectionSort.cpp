#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
using namespace std;
/*
First, we will select the range of the unsorted array using a loop (say i) that indicates the starting index of the range. The loop will run forward from 0 to n-1. The value i = 0 means the range is from 0 to n-1, and similarly, i = 1 means the range is from 1 to n-1, and so on. (Initially, the range will be the whole array starting from the first index.)
Now, in each iteration, we will select the minimum element from the range of the unsorted array using an inner loop.
After that, we will swap the minimum element with the first element of the selected range(in step 1).
Finally, after each iteration, we will find that the array is sorted up to the first index of the range.
*/

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
    static void selectionSort(vector<int>&arr){
        int n = arr.size();
        for(int i = 0;i<n-1;i++){
            int min = i;
            for(int j = i+1;j<n;j++){
                if(arr[min] > arr[j]) min = j;
            }
            int temp = arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
};

int main(){
    const int N = 5000;
    vector<int> arrs = readArrayFromFile();

    sortss a;

    auto start = std::chrono::high_resolution_clock::now();
    a.selectionSort(arrs);
    auto end = std::chrono::high_resolution_clock::now();

    // for(auto i : arrs) cout<<i<<" ";

    cout<<endl;
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Time taken: " << elapsed.count() << " seconds\n";
    return 0;
}