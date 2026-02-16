#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

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
    void qs(vector<int>&arr , int l, int h){
        if(l>=h) return;
        vector<int> vals(3);
        // try taking mini as pivot, it should take highest time
        // int mini = min(arr[l],arr[h]);
        // mini = min(mini, arr[((h+l)/2)]);
        
        vals[0] = arr[l];
        vals[1] = arr[h];
        vals[2] = arr[((h+l)/2)];
        sort(vals.begin(),vals.end());
        
        
        int pivot = vals[1];
        int i = l-1;
        int j = h+1;
        while(true){
            do{
                i++;
            }while(arr[i]<pivot);
            do{
                j--;
            }while(arr[j]>pivot);

            if(i>=j) break;
            swap(arr[i],arr[j]);
        }
        qs(arr,l,j);
        qs(arr,j+1,h);
    }

    void quickSort(vector<int>& arr){
        int n = arr.size();
        qs(arr,0,n-1);
    }
};

int main(){
    const int N = 5000;
    vector<int> arrs = readArrayFromFile();
    // vector<int> arrs = {9,4,7,3,1};

    sortss a;

    auto start = std::chrono::high_resolution_clock::now();
    a.quickSort(arrs);
    auto end = std::chrono::high_resolution_clock::now();

    // for(auto i : arrs) cout<<i<<" ";

    cout<<endl;
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Time taken by quick sort: " << elapsed.count() << " seconds\n";
    return 0;
}