#include <algorithm>
#include <fstream>
#include <chrono>
#include <vector>

const int dataset = 10;
const int maxLength = 1000000;
const double maxN = 1e9;


signed main(){
	std::ofstream fout;
	std::ifstream fin;

	for (int i = 1; i <= dataset; i++){
        fin.open("../../Input/input" +std::to_string(i)+".txt");
		fout.open("Output/output"+std::to_string(i)+".txt");
		
		std::vector<double> arr(maxLength);
		for (int j = 0; j < maxLength; j++){
			fin >> arr[j];
		}
		auto start = std::chrono::high_resolution_clock::now();
		std::sort(arr.begin(),arr.end());
		auto end = std::chrono::high_resolution_clock::now();
		fout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms\n";
		fin.close();
		fout.close();
	}
	return 0;
}
