

// Heap Algorithms 
// 
// Heap : 
// 1. First element is always largrst
// 2. Add / remove takes O(log(n)) time

vector<int> vec = {9,1,10,2,45,3,90,4,9,5,8};

make_heap(vec.begin(), vec.end());
 // vec : 90 45 10 9 8 3 9 4 2 5 1

Remove the largest element : 
pop_heap(vec.begin(), vec.end()); 
	// 1. Swap vec[0] with last item vec[size]
	// 2. Heapify [vec.begin() , vec.end() -1 ]

// vec : 45 9 10 4 8 3 9 1 2 5 90

vec.pop_back();		// Remove the last item (largest one)
// vec : 45 9 10 4 8 3 9 1 2 5

// Add a new element : 
vec.push_back(100);
push_heap(vec.begin(), vec.end()); 	
		// Heapify the last item in vec
  // vec : 100 45 10 4 9 3 9 1 2 5 8



// Heap Sorting :
vector<int> vec = {9,1,10,2,45,3,90,4,9,5,8};
make_heap(vec.begin(), vec.end());

sort_heap(vec.begin(), vec.end());
// vec : 1 2 3 4 5 8 9 9 10 45 100
// Note : sort_heap can only work on a heap. so first make_heap the vector
