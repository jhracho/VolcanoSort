#ifndef VOLCANO_SORT_H_
#define VOLCANO_SORT_H_

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

// Helper function that pops an element at a specific index
int pop(vector<int> &input, int index){
	int val = input[index];
	input.erase(input.begin()+index);
	return val;	
}

// Main function that drives Volcano Sort
vector<int> volcanoSort(vector<int> &input){
	int length = input.size();
	if (length < 3){
		vector<int> error = {};
		return error;
	}
	
	// Initialize Volcano Order
	vector<int> volcanoOrder(length);

	// Retrieve Max Number
	int maxNum = input[0];
	int maxInd = 0;
	for (int i = 0; i < input.size(); i++){
		if (input[i] > maxNum){
			maxNum = input[i];
			maxInd = i;	
		}
	}

	// Insert Max Number
	int lindex = length/2;
	int rindex = lindex;
	int mindex = rindex;
	volcanoOrder[mindex] = maxNum;
	pop(input, maxInd);

	// Construct Volcano
	int direction = 1;
	int index;
	
	for (int i = 0; i < length-1; i++){
		int newMax = numeric_limits<int>::min();
		for (int j = 0; j < input.size(); j++){
			if (input[j] > newMax){
				newMax = input[j];
				index = j;
			}	
		}

		// Build volcano by alternating placements
		if (direction == 1){
			volcanoOrder[lindex-1] = newMax;
			lindex--;
			direction = 0;
		}
		else{
			volcanoOrder[rindex+1] = newMax;
			rindex++;
			direction = 1;
		}
		pop(input, index);
	}	
	
	// Erupt volcano into sorted order
	vector<int> volcanoSorted = {};
	if (length % 2 == 0){
		for (int i = 0; i < length; i++){
			volcanoSorted.push_back(pop(volcanoOrder, volcanoOrder.size()/2));	
		}
	}
	else{
		for (int i = 0; i < length/2; i++){
			volcanoSorted.push_back(pop(volcanoOrder,volcanoOrder.size()/2));
			volcanoSorted.push_back(pop(volcanoOrder,(volcanoOrder.size()/2)-1));
		}
		volcanoSorted.push_back(pop(volcanoOrder,0));
	}
	
	reverse(volcanoSorted.begin(), volcanoSorted.end());
	return volcanoSorted;
}

#endif
