#include <algorithm>
#include <vector>
#include <fstream>
#include <chrono>

const int dataset = 10;
const int maxLength = 1e6;
const double maxN = 1e9;

using std::vector;
using std::swap;

int partition(vector<double>&arr, int start, int end)
{
    double pivot = arr[(start+end)/2];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}
 
void quickSort(vector<double>&arr, int start, int end)
{
    if (start >= end)
        return;
    int p = partition(arr, start, end);
    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}

signed main(){
	std::ofstream fout;
	std::ifstream fin;

	for (int i = 1; i <= 10; i++){
		fin.open("../../Input/input"+std::to_string(i)+".txt");
		fout.open("Output/output"+std::to_string(i)+".txt");
		
		std::vector<double> data(maxLength);
		for (int j = 0; j < maxLength; j++){
			fin >> data[j];
		}

		auto start = std::chrono::high_resolution_clock::now();
		quickSort(data,0,maxLength-1);
		auto end = std::chrono::high_resolution_clock::now();
		fout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms\n";
		fin.close();
		fout.close();
	}
    return 0;
}
