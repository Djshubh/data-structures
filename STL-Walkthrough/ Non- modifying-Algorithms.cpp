/*
*  Non- modifying Algorithms
 count , min & max , compare , linear search, attribute .
*/


vector<int> vec = {9,60, 90, 8 , 45, 87 , 90,69 , 55, 7};
 // 1. COunting

 // Algorithm         Data                   operation
int n = count( vec.begin() + 2 , vec.end() -1 ,69);		// 2
int m = count_if (vec.begin(), vec.end() , [](int x ){return x ==69;});  // 2
int m = count_if (vec.begin(), vec.end() , [](int x ){return x < 10;});  // 3


 // 2. Min and Max

itr = max_element (vec.begin() +2 , vec.end()) ; 	// 90

 // It return the first max value

itr = max_element(vec.begin() , vec.end() ,
					[](int x, int y){ return (x%10)<(y%10) ; }); 	// 9

//Most Algorithms have a simple form and a generalised form

itr = min_element(vec.begin(), vec.end()) ; 	// 7

// generalised form : min_element()

pair_of_itr = minmax_element (vec.begin() , vec.end() ,
								[](int x, int y) {return (x%10)< (y%10);});

// returns a pair , which contains first of min and last of max .


// 3. Linear Searching (used when data is not sorted )

// 		Return the first match

itr = find(vec.begin(), vec.end() , 55);

itr - find_if (vec.begin(), vec.end(), [](int x) { return x>80 ; });

itr = find_if_not(vec.begin(),vec.end(), [](int x ){ return x>80; });

itr = search_n (vec.begin() , vec.end() , [](int x){ return x>80 ; });

itr = search_n(vec.begin(), vec.end(), 2, 69); 		//consecutive 2 items fo 69

// generalized form : search_n()

// Search subrange
vector<int> sub = {45, 87, 90};
itr = search( vec.begin(), vec.end(), sub.begin(), sub.end());
	// search first subrange

itr = find_end (vec.begin(), vec.end(), sub.begin(), sub.end());
	// search last subrange
// generalized form : search() , find_end()


// search any_of

vector<int> items = {87,69};
itr = find_first_of(vec.begin(), vec.end(), items.begin(), items.end());
		// Search any one of the item int items
itr = find_first_of(vec.begin(), vec.end(), items.begin(),items.end(),
					[](int x , int y){return x==y*4 ;});
		// Search any one the item in items that satisfy : x==y*4;

// Search Adjacent
itr = adjacent_find(vec.begin, vec.end()); // find 2 Adjacent items that are same.

itr = adjacent_find(vec.begin(), vec.end(),
					 [](int x, int y){return x==y*4 ; });
	// find two adjacent items that satisfy : x==y*4 ;



// 4.  comparing Ranges

if( equal(vec.begin(), vec.end(), vec2.begin())) {
	cout << "vec and vec2 are same.\n";
}

if(is_permutation(vec.begin(), vec.end(), vec2.begin())) {
	cout << "vec and vec2 have same itmes , but in different order. \n ";
}

pair_of_itr = mismatch(vec.begin(), vec.end(), vec2.begin());
// find first difference
// pair_of_itr.first is an iterator of vec
// pair_of_itr.second is an iterator of vec2

// Lexicographical comparison : one-by-one comparison with "less than"

lexicographical_compare(vec.begin(), vec.end(), vec2.begin(),vec2.end());
// {1,2,3,5}  < {1,2,4,5}
// {1,2}	  < {1,2,3}

//Generalized forms :
// equal() , is_permutation() , mismatch() , lexicographical_compare()



// 5.  Check Attributes

is_sorted(vec.begin(), vec.end();  // Check if vec is sorted

itr = is_sorted_until(vec.begin(), vec.end());
// itr points to first place to where elements are longer sorted.
// Generalized forms l is_sorted() , is_sorted_until()

is_partitioned(vec.begin(), vec,end(), [](int x ){return x>80;});
		// Check oif vec is partitioned according to the condition of (x>80)

is_heap (vec.begin(), vec.end()); 	// Check if vec is a heap
itr = is_heap_until(vec.begin(), vec.end());
		// finds the first place where it is no longer a heap
// Generalized forms : is_heap() , is_heap_until()

// All , any , none
all_of(vec.begin(), vec.end(), [](int x) {return x>80});
// if all of vec is bigger than 80

any_of(vec.begin(), vec.end(), [](int x) {return x>80});
// if any of vec is begger than 80

none_of(vec.begin(), vec.end(), [](int x) {return x>80});
// if none of vec is bigger than 80.
