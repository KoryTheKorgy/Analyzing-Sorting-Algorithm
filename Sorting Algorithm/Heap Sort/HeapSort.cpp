#include <algorithm>
#include <vector>
#include <fstream>
#include <chrono>
#include <iostream>
#include <cstdio>

const int dataset = 10;
const int maxLength = 1e6;
const double maxN = 1e9;

using std::vector;
using std::swap;

void heapify(vector<double> &arr, int N, int i){
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < N && arr[l] > arr[largest])
		largest = l;
	if (r < N && arr[r] > arr[largest])
		largest = r;
	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, N, largest);
	}
}
void heapSort(vector<double> &arr, int N)
{
	for (int i = N / 2 - 1; i >= 0; i--)
		heapify(arr, N, i);
	for (int i = N - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

signed main(){
	std::ofstream fout;
	std::ifstream fin;

	for (int i = 1; i <= 10; i++){
		fin.open("../../Input/input" +std::to_string(i)+".txt");
		fout.open("Output/output"+std::to_string(i)+".txt");

		vector<double> vec(maxLength);
		for (int j = 0; j < maxLength; j++){
			fin >> vec[j]; 
		}
		auto start = std::chrono::high_resolution_clock::now();
        heapSort(vec,maxLength);
		auto end = std::chrono::high_resolution_clock::now();
		fout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms\n";
		fin.close();
		fout.close();
	}
    return 0;
}

