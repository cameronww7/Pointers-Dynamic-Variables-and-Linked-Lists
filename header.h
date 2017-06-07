/*************************************************************************
 * AUTHOR        : Cameron Walters
 * Assignment 	 : Project 4 Pointers, Dynamic Variables, and Linked Lists
 * Class         : CS 301
 ************************************************************************/

#ifndef HEADER_H_
#define HEADER_H_

#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <limits>
#include <ios>

#include "NodeType.h"

using namespace std;

NodeType* AddToList(NodeType *head,
			   int      &value);
NodeType* DeletePrompt(NodeType *head);
NodeType* DeleteFront(NodeType *head);
NodeType* FindAndDelete(NodeType *head);

void Search(NodeType *head);
void PrintList(NodeType *head);

bool isEmpty(NodeType *head);

char menuPrompt(const string MENU_PROMPT);
int NumberError(const string MENU_FORMAT,	// IN & OUT		- output string
		 	 	const int IN_MIN,			// IN & OUT		- minimum option
		 	 	const int IN_MAX);			// IN & OUT		- maximum optio

#endif /* HEADER_H_ */
