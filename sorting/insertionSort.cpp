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

class sorts{
public:
    void insertionSort(vector<int>& arr){
        int n = arr.size();
        for(int i = 1; i < n;i++){
            int l,r;
            l = i-1;
            r=i;
            while((l>=0)and(l<r)and(arr[l] > arr[r])){
                int tmp = arr[l];
                arr[l] = arr[r];
                arr[r] = tmp;
                r--;
                l--;
            }
        }
    }

};

int main(){
    
vector<int> arrs = readArrayFromFile();
    sorts a;
    auto start = std::chrono::high_resolution_clock::now();
    a.insertionSort(arrs);
    auto end = std::chrono::high_resolution_clock::now();
    
    for(auto i : arrs) cout<<i<<" ";
    cout<<endl;
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "vanshTime taken: " << elapsed.count() << " seconds\n";
    return 0;
}