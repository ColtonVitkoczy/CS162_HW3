#include "social_media.h"


//Colton Vitkoczy

//This code is going to manage how we write up functions for the social media class type


/* data members
		char author[AUTHOR];
		char title[TITLE];
		char link[LINK];
		char text[TEXT];
		int likes;
		int comments;

*/
// Constructor initializing data members to the zero equivalent value
socialmedia::socialmedia()
{
	author = NULL;
	title = NULL;
	link = NULL;
	text = NULL;
	likes = 0;
	comments = 0;

}
// Destructor to deallocate the dynamic memory for author, title, link, and text.
socialmedia::~socialmedia()
{
	if (NULL != author)
	       delete [] author;
	author = NULL;

	if (NULL != title)
	       delete [] title;
	title = NULL;

	if (NULL != link)
	       delete [] link;
	link = NULL;

	if (NULL != text)
	       delete [] text;
	text = NULL;
}

// This function reads in a post from the user it contains 4 dynamicaly allocated arrays 
// and two int objects. For each dynamic array, first a temporary char array of a constant size
// from socialmedia class is created. Input from the user is gathered, a new char array of 
// the input plus one is created and then copied into the data member type 
void socialmedia::read()
{
	// Dynamically allocated array to read in the author
	char temp[AUTHOR]; 
	cout << "Please enter in the author: ";
	cin.get(temp, AUTHOR, '\n');
	cin.ignore(100, '\n');

	author = new char [strlen(temp)+1];
	strcpy(author, temp);

	// Dynamically allocated array to read in the title
	char title_temp[TITLE];
	cout << "Please enter the title of the post: ";
	cin.get(title_temp, TITLE, '\n');
	cin.ignore(100, '\n');

	title = new char [strlen(title_temp)+1];
	strcpy(title, title_temp);

	// Dynamically allocated array to read in the hyperlink
	char link_temp[LINK];
	cout << "Please enter the link to the post: ";
	cin.get(link_temp, LINK, '\n');
	cin.ignore(100, '\n');

	link = new char [strlen(link_temp)+1];
	strcpy(link, link_temp);

	// Dynamically allocated array to read in the body of the post
	char text_temp[TEXT];
	cout << "Please enter the textbody of the post: ";
	cin.get(text_temp, TEXT, '\n');
	cin.ignore(100, '\n');

	text = new char [strlen(text_temp)+1];
	strcpy(text, text_temp);

	// Reads in number of likes
	//int temp_likes;
	cout << "Please enter the number of likes: ";
	cin >> likes;
	cin.ignore(100, '\n');

	//likes = new int temp_likes;
	// Reads in number of comments
	cout << "Please enter the number of comments: ";
	cin >> comments;
	cin.ignore(100, '\n');

}
// Displays social media posts, starts by checking if any data member is NULL and exits
// the function if so. If no dynamically allocated data member is NULL it displays the
// author, title, link, text, likes, and comments for a social media post. 
void socialmedia::display()
{
	if (NULL == author) // Nothing is in the authors array exit function
		return;

	if (NULL == title) // Nothing is in the title array exit function
		return;

	if (NULL == link) // Nothing is in the link array exit function
		return;

	if (NULL == text) // Nothing is in the text array exit funciton
		return;

	cout << author << '\n' 
	     << title << '\n'
	     << link << '\n'
	     << text << '\n'
	     << likes << '\n'
	     << comments << endl;

}

// This is a function for the list.cpp when searching for posts with likes greater than 
// a given number. This just returns the value for number of likes for when the function is called.
// I did this to get around the scope error I had when building the matching function in list.cpp
int socialmedia::is_match()
{
	int number_likes; // Declaring int object
	number_likes = likes; // Initializing it to number of likes
	return number_likes;  // Returning the number of likes 
}




