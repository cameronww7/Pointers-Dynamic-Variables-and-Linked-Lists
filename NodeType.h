/*************************************************************************
 * AUTHOR        : Cameron Walters
 * Assignment 	 : Project 4 Pointers, Dynamic Variables, and Linked Lists
 * Class         : CS 301
 ************************************************************************/

#ifndef NODETYPE_H_
#define NODETYPE_H_



class NodeType
{

public:
   NodeType( int = 0 );  		// constructor with default value for
								// info field
   int info;                 	// data
   NodeType * nextPtr; 			// pointer to next node in the list
};



#endif /* NODETYPE_H_ */
