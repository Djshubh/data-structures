
/*
* 	Numeric Algorithm
* 	-- Accumulate , inner product , partial sum , adjacent difference*
*/

// 1. Accumulate

int x = accumulate(vec.begin(), vec.end(), 10);
// 10 + vec[0] + vec[1] + vec[2] + ...

int x accumulate(vec.begin(), vec.end(), 10 , multiplies<int>());
// 10 * vec[0] * vec[1] * vec[2] * ...

// 2. Inner Product
// vector<int> vec = {9,60,70,8,45,87,90};		// 7 items

int x = inner_product(vec.begin(), vec.begin()+3,	// Range #1
						vec.end()-3,				// Range #2
						10);						// Init Value

// 10 + vec[0]*vec[4] + vec[2]*vec[5] + vec[3]*vec[6]


int x = inner_product(vec.begin(), vec.begin()+3,	// Range #1
						vec.end()-3,				// Range #2
						10,							// Init Value
						multiplies<int>(),
						plus<int>());						
 
 // 10 * (vec[0]+vec[4]) * (vec[2]+vec[5]) * (vec[3]+vec[6])

// 3. Partial Sum
partial_sum(vec.begin(), vec.end(). vec2.begin());
// vec2[0]  = vec[0]
// vec2[1]  = vec[0] + vec[1];
// vec2[2]  = vec[0] + vec[1] + vec[2];
// vec2[3]	= vec[0] + vec[1] + vec[2] + vec[3];
// ... 

partial_sum (vec.begin(), vec.end(), vec2.begin(), multiplies<int>());

// 4. Adjacent Difference 
adjacent_difference(vec.begin(), vec.end(), vec2.begin());
// vec2[0] = vec[0]
// vec2[1] = vec[1] - vec[0];
// vec2[2] = vec[2] - vec[1];
// vec2[3] = vec[3] - vec[2];
// ... 


adjacent_difference(vec.begin(), vec.end(), vec2.begin(), plus<int>());
// becomes adjacent sum 
