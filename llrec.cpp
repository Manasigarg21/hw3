#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

#include <cstdlib>


/**
 * Given a linked list pointed to by head, creates two lists
 * where all values less than or equal to the pivot value are
 * placed in a linked list whose head will be pointed to by
 * smaller and all values greater than the pivot
 * value are placed in a linked list whose head will be pointed to
 * by larger.  The input list pointed to by head should be empty
 * upon return and head set to NULL (i.e. we are not making copies)
 * in the smaller and larger lists but simply moving Nodes out of
 * the input list and into the two other lists.
 * 
 * ==============================================================
 * MUST RUN IN O(n) where n is the number of nodes in the input list
 * ==============================================================
 *
 * @pre: smaller and larger may containing garbage (do NOT have
 *       to be NULL)
 *
 * @param[inout] head
 *   Reference to the head pointer to the input list.
 *   Should be set to NULL upon return
 * @param[out] smaller
 *   Reference to a head pointer for the list of nodes with values
 *   less than or equal to the pivot
 * @param[out] larger
 *   Reference to a head pointer for the list of nodes with values
 *   greater than the pivot
 * @param[in] pivot
 *   Pivot value
 *
 */
void llpivotHelper(Node *&head, Node *&smaller, Node *&larger, int pivot){
	if (head->val <= pivot){
		//create a new node 
		//Node* temp = new Node(head->val);
		//smaller = temp;
		smaller = head;
		llpivot(head->next, smaller->next, larger,pivot);
			//smaller->next;
	}
	else{
		larger = head; 
		llpivot(head->next, smaller, larger->next,pivot);
	}
}
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){

	if (head == NULL){
		smaller = nullptr;
		larger = nullptr; 
		return;
	}
	llpivotHelper(head, smaller, larger, pivot);
}



