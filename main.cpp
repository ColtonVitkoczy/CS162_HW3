#include "list.h"

//Colton Vitkoczy

// This is the main cpp file it calls the functions required for porgram #4

int main()
{
	library media_list;          // Creates a library class object 
	media_list.read_all();       // Calls the funciton to read all posts from library class object 
	media_list.display_all();    // Calls the function to display all posts entered
	media_list.matching_likes(); // Calls the function to display posts greater then a given number
	return 0;                    // of likes.  
}
