#include "list.h"


// Colton Vitkoczy

// This file manages the constructors and destructors of the library class objet, it asks the user
// how many posts they'd like to save. It conatains the function asking the user to display all posts
// along with the funciton asking if the user wants to display posts greater than a certain number of likes.



// This is the library class constructor it gets the size of the array and allocates new memory
// for the pointer of array to the socialmedia class object  
library::library()
{
	cout << "How many posts would you like to store? ";
	cin >> size_array;  // number of posts to store
	cin.ignore(100, '\n');

	// allocates memory of type socialmedia class and stores the address of the allocted
	// memory in array.
	array = new socialmedia[size_array]; 
	num_posts = 0;
}

// Destructor to deallocate memory for the socialmedia array 
library::~library()
{
	if (NULL != array)  
		delete [] array;
	array = 0;
	size_array = 0;
	num_posts = 0;
}
// Function to ask if the user would like to continue inputing social media posts
// and repeats until the number of posts entered is less than the size of the array
// the user entered.
void library::read_all()
{
	char response = 'y'; // does the user want to do this again
	while (tolower(response) == 'y' && num_posts < size_array)
	{
		array[num_posts].read(); // calls the read function from CS_Social.cpp for each post
		++num_posts; // increases the number of posts counter
		cout << "Would you like to continue inserting posts? : "; 
		cin >> response;
		cin.ignore(100, '\n');
	}
}

// Displays all posts the user has entered, first asking the user if they'd like to then
// calls the function 'display' from CS_Social.cpp in a loop and displays each post 
void library::display_all()
{
	char response = 'N';

	cout << "Would you like to display all posts?: ";
	cin >> response;
	cin.ignore(100, '\n');

	if ('Y' == toupper(response))
	{
		for (int i =0; i < num_posts; ++i)
			array[i].display(); // calls the display function for each element in the array
	}
}

// This function asks the user if they'd like to display social media posts greater than a certain number
// of likes. It then gets the number of likes from the user, enters a loop, and for each member of array 
// calls on the function is_match from CS_Social.cpp to get the number of likes. Then, compares the number 
// of likes called on to the number given by the user and displays this post if true.
//
// For this function I couldn't use array[i].likes becuase of the vioaltion of the scope of the function.
// Thats why I just called a function from socialmedia that returns the value we need. 
void library::matching_likes()
{
	char response = 'N';
	int likes_search = 0; // Object for getting number of likes to search for

	cout << "Would you like to display items greater than a certain number of likes?: " ;
	cin >> response;
	cin.ignore(100, '\n');

	if('Y' == toupper(response))
	{
		cout << "How many likes?: " ;
		cin >> likes_search;
		cin.ignore(100, '\n');
		
		// Loops through number of posts in array and displays them based on 
		// the following conditions
		for (int i = 0; i < num_posts; ++i)
		{
			if(array[i].is_match() > likes_search) // calls is_match return value for each like in array[i]
			       array[i].display();             // displays each post in array[i] that has likes greater than 
							       // likes_search
		}
	}
}	


// This function is a rough draft of the function above using a LLL. It has no application in the program
// I just saved it so I can come back and try it out as practice before the final and FP demos.

/*
void library::matching_likes()
{
	char response = 'N';
	int likes_search = 0;

	cout << "Would you like to display items greater than a certain number of likes?: " ;
	cin >> response;
	cin.ignore(100, '\n');

	if('Y' == toupper(response))
	{
		cout << "How many likes?: " ;
		cin >> likes_search;
		cin.ignore(100, '\n');

		node * current = head;
		while(NULL != current)
		{
			if (current -> likes > likes_search)
				cout << current -> array.likes << endl;
			current = current -> next;
		}

	}
}
*/
