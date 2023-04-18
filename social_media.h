#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;


//Colton Vitkoczy

// This is the .h file that contains the headers and namespaces used for the program. 
// It contains the socialmedia class object along with the constructor, deconstructor, 
// and function protoypes used in CS_social.cpp


// Constants
// These are called on in CS_social.cpp file when reading user input in a dynamic array.

const int AUTHOR = 40;
const int TITLE = 40; 
const int LINK = 50; 
const int TEXT = 40; 

// Socialmedia class object  
class socialmedia
{	
	public:
		socialmedia();  // Constructor
		~socialmedia(); // Destructor
		void read();    // Reads a single post
		void display(); // Displays a post
		int is_match(); // Returns an int for the match fucntion in list.cpp file

	private:
		char * author;  // Pointer of type char for author 
		char * title;   // Pointer of type char for title
		char * link;    // Pointer of type char for link
		char * text;    // Pointer of type char for text
		int likes;      // int for number of likes
		int comments;   // int for number of comments
};



