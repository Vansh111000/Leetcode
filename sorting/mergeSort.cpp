// both merge and quick sort follow divide and conquer
#include <iostream>
#include <vector>
#include <chrono>
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
    void merge(vector<int> &arr,int l,int mid,int r){
        int m =mid+1;
        int left = l;
        vector<int>tm;

        while((left<=mid)and(m <= r)){
            if(arr[left]<arr[m]) tm.push_back(arr[left++]);
            else tm.push_back(arr[m++]); 
        }
        while(left<=mid) tm.push_back(arr[left++]);
        while(m<=r) tm.push_back(arr[m++]);

        
        for(auto i = l; i < r+1; i++) arr[i] = tm[i-l];
    }
    void mergeSort(vector<int>& arr, int l,int r){
        if(l<r){
            int mid = l-((l-r)/2);
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);
            merge(arr,l,mid,r);
        }
    }

};

int main(){
    const int N = 5000;
    vector<int> arrs = readArrayFromFile();
    // vector<int> arrs = {1,2,3,4,5};

    sortss a;

    auto start = std::chrono::high_resolution_clock::now();
    a.mergeSort(arrs,0,arrs.size()-1);
    auto end = std::chrono::high_resolution_clock::now();

    // for(auto i : arrs) cout<<i<<" ";

    cout<<endl;
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Time taken by quick sort: " << elapsed.count() << " seconds\n";
    return 0;
}