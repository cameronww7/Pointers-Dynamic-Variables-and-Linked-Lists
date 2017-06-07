/*************************************************************************
 * AUTHOR        : Cameron Walters
 * Assignment 	 : Project 4 Pointers, Dynamic Variables, and Linked Lists
 * Class         : CS 301
 ************************************************************************/

#include "header.h"
#include "NodeType.h"

/************************************************************************
 *
 * _______________________________________________________________________
 *
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *
 * POST-CONDITIONS
 *
 ************************************************************************/
int main()
{
	NodeType *head;   //First node in list
	char      option; //Users menu choice
	int       value;  //value to be stored

	head = NULL;

	option = menuPrompt("\n\tA for Add\n"
			   	   	      "\tD for Delete\n"
			   	   	      "\tS for Search\n"
			   	   	      "\tP for Print\n"
						  "\tQ for Quit\n"
						  "\tEnter your Choice : ");

	while(option != 'Q')
	{
		switch(option)
		{
			//Adds to the front of the list
			case 'A' : value = NumberError("\tEnter any Integer "
										   "(between 0-1000): ",
											         0, 1000);
					   head = AddToList(head, value);
				break;
			//Deletes from front or search and deletes
			case 'D' :	if(!isEmpty(head))
						{
							head = DeletePrompt(head);
						}

				break;
			//Searched through linked list for an item
			case 'S' :if(!isEmpty(head))
						{
							Search(head);
						}
				break;
			//Prints the list unless its empty
			case 'P' : 	if(!isEmpty(head))
						{
							PrintList(head);
						}
				break;
		}

		option = menuPrompt("\n\tA for Add\n"
							  "\tD for Delete\n"
							  "\tS for Search\n"
							  "\tP for Print\n"
							  "\tQ for Quit\n"
							  "\tEnter your Choice : ");
	}


	cout << "\n\nThank You, and Have a Wonderful Day";
	return 0;
}

NodeType* AddToList(NodeType *head,
			   int      &value)
{
	NodeType *curPtr;  //A pointer pointing at something

	cout << "\n\tAdding value \"" << value << "\" to the front of the list\n";

	curPtr          = new NodeType;
	curPtr->info    = value;
	curPtr->nextPtr = head;
	head            = curPtr;

	return head;
}

NodeType* DeletePrompt(NodeType *head)
{
	int option;
	option = NumberError("\n\t1 for Front Delete\n"
						   "\t2 for Search & Delete\n"
						   "\tEnter your Choice : ",
										1, 2);
	switch(option)
	{
		//Calls front Delete Function
		case 1 : head = DeleteFront(head);
			break;
		//Calls search and delete
		case 2 : head = FindAndDelete(head);
		break;
	}

	return head;
}

NodeType* DeleteFront(NodeType *head)
{
	NodeType *curPtr; //A pointer pointing at something

	curPtr = head;

	cout << "\n\tDeleting --> " << curPtr->info << endl;

	curPtr = head;
	head   = head->nextPtr;
	delete curPtr;

	return head;
}

NodeType* FindAndDelete(NodeType *head)
{
	NodeType *curPtr; //A pointer pointing at something
	NodeType *deletePtr; //A pointer pointing at an item to be deleted
	int       numToBeDeleted;
	bool      found = false;

	curPtr = head;
	//Prints list so user knows whats in it
	PrintList(head);
	//Prompts user for what to be deleted
	numToBeDeleted = NumberError("\tEnter a Integer from Above to be Deleted: ",
													      0, 1000);
	cout << "\n\tFinding & Deleting --> " << numToBeDeleted << endl;
	//Checks and sees if head is the node to be deleted
	if(head->info == numToBeDeleted)
	{
		cout << "\n\tFound & Deleting --> " << numToBeDeleted << endl;
		deletePtr = head;
		head      = deletePtr->nextPtr;
		delete deletePtr;
	}
	else
	{
		//finds the node before the node need to be deleted
		while (curPtr->nextPtr != NULL && !found)
		{
			if(curPtr->nextPtr->info == numToBeDeleted)
			{
				found = true;
			}
			else
			{
				curPtr = curPtr->nextPtr;
			}
		}
		// if the node doesn't exist gives error message
		if(curPtr->nextPtr == NULL)
		{
			cout << "\n\tWas Not Found --> " << numToBeDeleted << endl;
		}
		else
		{
			cout << "\n\tFound & Deleting --> " << numToBeDeleted << endl;
			//checks to see if the noded needed to be deleted is at NULL
			if (curPtr->nextPtr->nextPtr == NULL)
			{
				deletePtr       = curPtr->nextPtr;
				curPtr->nextPtr = NULL;
			}
			//finds node in the middle and deletes it
			else if (curPtr->nextPtr->info == numToBeDeleted)
			{
				deletePtr       = curPtr->nextPtr;
				curPtr->nextPtr = deletePtr->nextPtr;
			}
			delete deletePtr;
		}
	}

	return head;
}

void PrintList(NodeType *head)
{
	NodeType *curPtr; //A pointer pointing at something
	int       index = 0;

	curPtr = head;

	//prints the list from head to NULL
	cout << "\n\tPrinting the List \n";
	while(curPtr != NULL)
	{
		cout << "\tIndex " << ++index << " : " <<  curPtr->info << endl;
		curPtr = curPtr->nextPtr;
	}

}

void Search(NodeType *head)
{
	NodeType *curPtr; //A pointer pointing at something
	bool      found = false;
	int       numToBeFound;

	curPtr = head;

	//Prints list so user knows whats in it
	PrintList(head);

	numToBeFound = NumberError("\tEnter a Integer to be found: ",
													      0, 1000);

	while (curPtr->nextPtr != NULL && !found)
	{
		//if true, the search item is found and outputs
		if(curPtr->info == numToBeFound)
		{
			cout << "\n\tFound --> " << numToBeFound << endl;
			found = true;
		}
		else
		{
			curPtr = curPtr->nextPtr;
		}
	}

	//outputs an error message if item searched for isnt found
	if(!found)
	{
		cout << "\n\tWas not Found --> " << numToBeFound << endl;
	}
}

bool isEmpty(NodeType *head)
{
	bool empty = false;

	//checks and sees if the list is empty
	if(head == NULL)
	{
		cout << "\n\tList is Empty\n";
		empty = true;
	}
	return empty;
}

char menuPrompt(const string MENU_PROMPT)
{

	bool someBool;					// PROCESSING	- determines whether
									// 				  the menu is output
	char option;					// IN & OUT		- user input choice

	do
	{
		someBool = false;

		// OUTPUT - the menu
		cout << MENU_PROMPT;
		cin.get(option);
		option = toupper(option);

		if (  option == 'A' || option == 'D' || option == 'P' ||
		      option == 'Q' || option == 'S')
		{
			someBool = true;
		}
		else
		{
			cout << "\n * Error *  Please Enter one choice Of A,D,P,Q \n";
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}while(!someBool);

	return option;

}


/************************************************************************
 *  int NumberError
 * _______________________________________________________________________
 * This function outputs the menu and tracks if the user inputs an
 *	invaild character or number within the range that was passed.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *		MENU_FORMAT : menu format needs to be predetermined
 *		IN_MIN 		: minimum input option needs to be predetermined
 *		IN_MAX		: maximum input option needs to be predetermined
 * POST-CONDITIONS
 * 		Returns a valid user choice (option) to the calling function
 ************************************************************************/
int NumberError(const string MENU_FORMAT,	// IN & OUT		- output string
		 	 	const int IN_MIN,			// IN & OUT		- minimum option
		 	 	const int IN_MAX)			// IN & OUT		- maximum option
{
	bool someBool;					// PROCESSING	- determines whether
									// 				  the menu is output
	int option;						// IN & OUT		- user input choice

	do
	{
		someBool = false;

		// OUTPUT - the menu
		cout << MENU_FORMAT;

		/*****************************************************************
		 * This is a check for the user's input. It will first check
		 * 	if the user has put in a vaild number, if invaild it will
		 *	clear the input then reoutput the menu until and do the
		 *	check's until the user puts in a vaild entry.
		 *****************************************************************/
		if(!(cin >> option))
		{
			cout << "\n**** Please input a NUMBER between " << IN_MIN
				 << " and " << IN_MAX << " ****";
			cin.clear();

			someBool  = true;
			cout << endl << endl;
		}
		else if (option > IN_MAX || option < IN_MIN)
		{
			cout << endl;
			cout << "**** The number " << option << " is an invalid "
					"entry     ****\n";
			cout << "**** Please input a number between "
				 << IN_MIN << " and " << IN_MAX << " ****\n";
			cout << endl;
			someBool = true;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}while(someBool);

	return option;
}

