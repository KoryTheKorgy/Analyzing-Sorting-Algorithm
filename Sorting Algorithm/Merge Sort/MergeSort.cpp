#include <algorithm>
#include <vector>
#include <fstream>
#include <chrono>

const int dataset = 10;
const int maxLength = 1e6;
const double maxN = 1e9;

using std::vector;
using std::swap;

void merge(vector<double> &arr, int const left, int const mid, int const right){
	auto const tempArr1 = mid - left + 1;
	auto const tempArr2 = right - mid;
	auto *leftArr = new int[tempArr1], *rightArr = new int[tempArr2];
	for (auto i = 0; i < tempArr1; i++) leftArr[i] = arr[left + i];
	for (auto j = 0; j < tempArr2; j++) rightArr[j] = arr[mid + 1 + j];
	auto indexArr1 = 0, indexArr2 = 0;
	int indexMergedArr = left;
	while (indexArr1 < tempArr1 && indexArr2 < tempArr2){
		if (leftArr[indexArr1] <= rightArr[indexArr2]){
			arr[indexMergedArr] = leftArr[indexArr1];
			indexArr1++;
		} else{
			arr[indexMergedArr] = rightArr[indexArr2];
			indexArr2++;
		}
		indexMergedArr++;
	}
	
	while (indexArr1 < tempArr1){
		arr[indexMergedArr] = leftArr[indexArr1];
		indexArr1++; indexMergedArr++;
	}
	while (indexArr2 < tempArr2){
		arr[indexMergedArr] = rightArr[indexArr2];
		indexArr2++; indexMergedArr++;
	}
}

void mergeSort(vector<double> &arr, int const low, int const high){
	if (low >= high)
		return;
	auto mid = low + (high - low) / 2;
	mergeSort(arr, low, mid);
	mergeSort(arr, mid + 1, high);
	merge(arr, low, mid, high);
}


signed main(){
	std::ofstream fout;
	std::ifstream fin;

	for (int i = 1; i <= dataset; i++){
        fin.open("../../Input/input" +std::to_string(i)+".txt");
		fout.open("Output/output"+std::to_string(i)+".txt");
		
		vector<double> vec(maxLength);
		for (int j = 0; j < maxLength; j++){
			fin >> vec[j];
		}
		
		auto start = std::chrono::high_resolution_clock::now();
		mergeSort(vec,0,maxLength-1);
		auto end = std::chrono::high_resolution_clock::now();
		fout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms\n";
		fin.close();
		fout.close();
	}
}
