// mergesort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>    // std::min

std::vector<int> mergeVectors(const std::vector<int> &a, const std::vector<int>& b) {

	auto ita = a.begin();
	auto itb = b.begin();
	std::vector<int> output;
	while (ita < a.end() && itb < b.end()) {
		if ((*ita) <= (*itb)) {
			output.push_back((*ita));
			++ita;
		}
		else {
			output.push_back((*itb));
			++itb;
		}

	}

	//Clear out the rest

	while (ita < a.end()) {
		output.push_back((*ita));
		++ita;
	}

	while (itb < b.end()) {
		output.push_back((*itb));
		++itb;
	}
	return output;
	
}

std::vector<int> mergesort(std::vector<int> &input) {

	for (auto i = 1; i <= input.size() / 2; i = i * 2) {

		for (auto j = 0; j <= input.size(); j+=i ) {
			auto first = j;
			auto original = j;
			auto second = std::min((j + i),(int)input.size());
			std::vector<int>::const_iterator firsthalf = input.begin() + first;
			std::vector<int>::const_iterator lasthalf = input.begin() + second;
			std::vector<int> sub1(firsthalf,lasthalf);
			
		 	j += i;
			first = std::min(j, (int)input.size());
			second = std::min((j + i), (int)input.size());

			firsthalf = input.begin() + first;
			lasthalf = input.begin() + second;
			std::vector<int> sub2(firsthalf,lasthalf);

			auto merged = mergeVectors(sub1,sub2);

			int counter = 0;
			for(int k = original; k < second; ++k) {
			   input[k] = merged[counter++];

			}

		}


	}
	return std::vector<int> {};
}

int main()
{
        std::cout << "merge sorting!\n";
	std::vector<int> list1{ 3,5,1,22,-1,31,12,28 };
	std::vector<int> list2{ 1,4,6,8 };
	std::vector<int> list3{ 2,5,7,12 };

	auto sorted = mergeVectors(list2, list3);
	mergesort(list1);
	for (auto it = list1.begin(); it < list1.end(); ++it) {
	  std::cout << "i:" << (*it) << std::endl;
	}

	return 0;
}

