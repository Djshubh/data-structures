/*
*	Sorted Data Algorithm 
*	- Algorithm that require data being pre-sorted
*	- Binary search , merge , set operations
*/

// Note : Every sorted data Algorithm has generalized form with a same name.

// 1.  Binary Search 
// search Elements 

bool found = binary_search(vec.begin(), vec.end(), 9); 
		// check if 9 is in vec

vector<int> s = {9,45,66}; 
bool found = includes(vec.begin(), vec.end()		 	// Range #1
						s.begin(), se.end());			// Range #2	

// Return true ifall elements of s is included in vec
// Both vec and s must be sorted 

// Search Position 
itr = lower_bound(vec.begin, vec.end(), 9);			// vec[1]
// Find the first position where 9 could be inserted aan still keep the sorting

itr = upper_bound(vec.begin(), vec.end(), 9);		// vec[4]
// Find the last position where 9 could br inserted and still keep the sorting.

pair_of_itr = equal_range(vec.begin(), vec.end(), 9);
// Return both first and last position.

// 2. Merge 
vector<int> vec = {8,9,9,10};
vector<int> vec2 = {7,9,10};

merge(vec.begin(), vec.end()			// Input Range #1
		vec2.begin(), vec2.end(),		// Input Range #2
		vec_out.begin()); 				// Output 
		// Both vec and vec2 should be sorted (same for the set operation)
		// Nothing is dropped , all duplicated are kept.
	// vec_out : {7,8,9,9,9,10,10}

vector<int> vec = {1,2,3,4,1,2,3,4,5} // Both part of vec aare already sorted
inplace_merge(vec.begin(), vec.begin()+4, vec.end());
// vec : {1,1,2,2,3,3,4,4,5}		- One step of merge sort

// 3. Set Operations 
//  	-- Both vec and vec3 should be sorted
// 		-- The resulted data is also sorted

vector<int> vec = {8,9,9,10}
vector<int> vec2 = {7,9,10}
vector<int> vec_out[5];

set_union(vec.begin(), vec,end()			// Input Range #1
		vec2.begin(), vec2.end(),			// Input Range #2
		vec_out.begin()); 					// Output 
// if X is in both vec and vec2 , only one X is kept in vec_out
// vec_out : {7,8,9,9,10}

set_intersection(vec.begin(), vec,end()			// Input Range #1
		vec2.begin(), vec2.end(),				// Input Range #2
		vec_out.begin()); 						// Output
// Only the items that are in both vec and vec2 are saved in vec_out
// vec_out : {9,10,0,0,0}

set_difference(vec.begin(), vec,end()			// Input Range #1
		vec2.begin(), vec2.end(), 				// Input Range #2
		vec_out.begin()); 						// Output
// Only the items that are in vec but not in vec2 are saved , but not from both
// vec_out : {7,8,9,0,0}

