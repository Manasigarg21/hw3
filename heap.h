#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>

template <typename T, typename PComparator = std::less<T> >
class Heap 
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);
	//push back to vector 
	//check if comp returns true 
		//

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
	void down(int index);
	void up (int index); 
	std::vector<T> vec; 
	PComparator comp; 
	int m_; 

};

// Add implementation of member functions here
//initialize constructor here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c){
	m_ = m;
	comp = c;
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){}

//trickle up function to be used with push
template <typename T, typename PComparator>
void Heap<T,PComparator>::up(int index){
	if (index>0){//checks to see if index is valid
		int parent = (index-1)/m_ ; //sets parent index
		if(parent >=0 && (comp(vec[index],vec[parent])) ){ //use comparator to see if nodes need to be swapper
			std::swap(vec[index],vec[parent]);//swap nodes
			index = parent; //update the value of index
			up(index);//recurse
		}
	}
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::down(int index){
	//smallestChild tracker
	int smallerChild = m_*index +1; 
	//base case that returns when we are at the final node to be checked
	if ((unsigned int)(smallerChild) >= vec.size()){
		return;
	}
	int max = vec.size()-1;
	//keeps track of the largest node in the vector
	int largestChild = std::min(m_*index+m_,max);
	
	//check all the possible children 
	for (int currChild = smallerChild+1; currChild<= largestChild; currChild++){ //0?
		//compare the smallest node to the current one
		if (comp(vec[currChild], vec[smallerChild])){
			smallerChild = currChild; 
		}
	}
	//perform swap if the smaller node needs to be swapped with the current node at index passed in
	if (comp(vec[smallerChild], vec[index])){
			std::swap(vec[smallerChild], vec[index]);
			//recurse
			down(smallerChild);
	}
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		throw std::underflow_error("Heap is empty, invalid access");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
	return vec[0]; 
}

// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		throw std::underflow_error("Heap is empty, invalid access");
  }
//int operator not bool
		//pop swaps first and last
		std::swap(vec[0], vec[vec.size()-1]);
		//actually pop the element
		vec.pop_back();
		//only if its not empty after popping we trickle down
		if(vec.size()>=1){
			down(0);
		}
		
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
	//want to push the item into array
	vec.push_back(item);
	//trickle up and sort its position within the array 
	up(vec.size()-1);
}

template <typename T, typename PComparator>
 bool Heap<T,PComparator>::empty() const{
	 return vec.empty();
 }

template <typename T, typename PComparator>
 size_t Heap<T,PComparator>::size() const{
	 return vec.size(); 
 }

#endif

