#include "social_media.h"


//Colton Vitkoczy

// This code manages how we read in a dynamically allocated array of social media posts,
// displays all posts, and searches for posts with likes greater than a number given by
// the user.   


// Constants

const int POSTS = 10; // this becomes useless after memory is dynamically allocated


// class object library

class library
{	
	public:
		library();            // constructor
		~library();           // destructor
		void read_all();      // Fucntion to read in all posts 
		void display_all();   // Function to display all posts
		void matching_likes();// Function to display posts greater than a certain # of likes. 

	private:
		socialmedia * array; // Pointer to one post or the first of many of socialmedia class
		int size_array;      // int for the size of the array
		int num_posts;       // int for how many posts the user wants to store
};



