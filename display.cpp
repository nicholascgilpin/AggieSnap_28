#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Window.h"
#include "Graph.h"
#include "GUI.h"

using namespace Graph_lib;

class Intro_Window : Graph_lib::Window{

    //Data Members
    Button continue_button;
    Text welcome;
    Text instructions;

    static void cb_continue(Address,Address);
        void continue_on();

    public: 
        Intro_Window(Point xy, int w, int h, const string& title);
};
struct Tag_obj;
struct Pic_obj;
//Class Display_Window creates the window and allows one to take input, manages the buttons and displays images
class Display_Window : Graph_lib::Window{
	// Data members
	ifstream ifs;
	ofstream ofs;
	vector<string> index_read; //used in next()
	string temp_str; //also used in next()
	// Constants
	static const int int_limit = 2147483640; // largest possible int and db size limit
	int index = 0;					 // An index of the current db line number
	bool search_mode;		 // true if the program is in search mode
	vector<string> s_results;		// An array of picture file names
	string db_filename = "Test_db.txt";
	vector<string> tag_buttons_pressed;// Use to save or search for Pic_obj's
	// Buttons
	Button next_button; //click to view the next picture
    Button previous_button; //click to view previous picture
    Button home_button; //click to return to viewing all images
	Button family;
	Button friends;
	Button aggieland;
	Button pets;
	Button vacation;
	Button search_button;
	Button add_file_button;
    Button quit_button;//click to exit program
    In_box input_file;//allows user to input a new file name and tags
    In_box input_url;
    Out_box mode; //indicates what images are being displayed 
	Out_box tags_displayed; //displays what tags are showing 
	Image *p;
   
    // Function Declarations
    static void cb_next(Address,Address);
        void next();
    static void cb_previous(Address,Address);
        void previous();
    static void cb_home(Address,Address);
        void home();
	static void cb_family(Address,Address);
        void tag0();
	static void cb_friends(Address,Address);
         void tag1();
	static void cb_aggieland(Address,Address);
         void tag2();
	static void cb_pets(Address,Address);
         void tag3();
	static void cb_vacation(Address,Address);
         void tag4();
	static void cb_search(Address,Address);
        void search();
	static void cb_add_file(Address,Address);
        void add_file();
    static void cb_quit(Address,Address);
        void quit();

	/*static void cb_search(Address,Address);
	void find();
	static void cd_add(Address, Address);
	void add();*/

public:
	Display_Window(Point xy, int w, int h, const string& title);
	vector<string> f_search(string db_fname, Tag_obj t);
	void check_index_range(int i);	// Corrects index range errors
	void set_search_mode(bool b);	// Changes the search_mode indicator and display
	void draw_image(string fname); // takes an image and draws it to the screen at Point(50,20)
	int family_i, friends_i, aggieland_i, pets_i, vacation_i; //tags
	string family_s, friends_s, aggieland_s, pets_s, vacation_s; //human-readable text that is written to index file
};

//Error message window
struct Error_window : Graph_lib::Window{
	Error_window(Point xy, int w, int h, const string& title );
private:
	Text message;
	Button ok_button;
	
	void ok();
	static void cb_ok(Address, Address);
}; 
// Tag_obj is used in the search function
struct Tag_obj
{
	//contains tags
	bool family;
	bool friends;
	bool aggieland;
	bool pets;
	bool vacation;
	Tag_obj()
	{
		family = false;
		friends = false;
		aggieland = false;
		pets = false;
		vacation = false;
	}
	Tag_obj(bool dfam, bool dfr, bool dag, bool dpt, bool dva)
	{
		family = dfam;
		friends = dfr;
		aggieland = dag;
		pets = dpt;
		vacation = dva;
	}

};
// check_index_range Corrects index range errors		//
// I might need to use qualified names for the vars...  
 
 void Display_Window::check_index_range(int i)
	{
		if (index < 0)
		{
			cerr << "Index range error.";
			index = 0;
		}
	} 
 
/*
// Reads line of file, displays pic & tags, increments index
void Display_Window::next()
	{
		check_index_range(index);
		if (search_mode) // Searching
		{
			if (s_results.empty())
			{ 
				return 0; //if vector is empty then exit
			} 
			else if (index == 0)
			{
				// if index = 0 then we're on the default picture
				draw_image(s_results[0]);
				}
			else (index < 0)
			{
				// get picture from search results;
				draw_image(s_results[index]);
				}
		}
		if (!search_mode) // Browsing
		{
			check_index_range(index);
			if (index == 0)
			{
				// if index = 0 then we're on the default picture
				// get the picture from the first line of file
				draw_image(s_results[index]);
			}
			if (index < 0)
			{
				// picture from the next line of file
				draw_image(s_results[index]);
			}
		}
		
		check_index_range(index); // prevent range errors
		index += 1;			  	  // set to 0 when changing modes!
*/

//------------------THESE ARE TEMPORARY---------------------------------
void Display_Window::next()
{
	hide();
}
void Display_Window::previous()
{
	hide();
}

//-----------------------------------------------------------------------
void Display_Window::quit()
	{
		hide();
	}

void Display_Window::home()
	{
		//Changes the browsing status, indicating that you can see all images
		ostringstream ss;
		ss<<"All Images";
		mode.put(ss.str());

	}
void Display_Window::tag0()
	{
		family_i = 1;

	}
void Display_Window::tag1()
	{
		friends_i = 1;
		/*
				bool current_tags[] = Tag_obj(family_i, friends_i, aggieland_i, pets_i, vacation_i);
		string tag_aray[] = { "family", "friends", "aggieland", "pets", "vacation" };
		string ts_arr[4];
		string tags_to_show;
		for (int k = 0; k <= 4; k++)
		{
			if (current_tags[k])
			{
				ts_arr[k] = tag_aray[k];
				ostringstream active_t_stream;	
				active_t_stream << ts_arr[k] <<
				tags_displayed.put(active_t_stream.str());

				}
		}
		*/

	}
void Display_Window::tag2()
	{
		aggieland_i = 1;
	}
void Display_Window::tag3()
	{
		pets_i = 1;
	}
void Display_Window::tag4()
	{
		vacation_i = 1;
	}
void Display_Window::search()
	{
		//Changes the browsing status to say "Search Results"
		ostringstream ss;
		ss<<"Search Results";
		mode.put(ss.str());
		Tag_obj current_tags = Tag_obj(family_i, friends_i, aggieland_i, pets_i, vacation_i);
		vector<string> results = f_search(db_filename, current_tags);
		ostringstream no_match;	// Prints message if no matches are found
		if ((results[0] == "") && (results.size() == 1))
		{
			no_match << "No matches";
			tags_displayed.put(no_match.str());
		}
	}

// Handles reading and writing from the database---------------//
class db_access
{
public:
	vector<string> find_tags; //find_tags keeps track of which tags to search for
	//string db_filename = "Test_db.txt";
	ofstream ofs;		// write to db
	ifstream ifs;	// read db

	// Functions for taking input:
	void check_ftype(string file_name); // Check type of file/if allowed
	void check_ltype(string location);   // Decide if looking for a file location or URL location
	void add_picture(string location, string filename); // Download File/URL and name it filename
	//- Allow recovery if Url can’t be downloaded/opened from disk
	//- Allow recovery if incorrect file/url format

	// Function for saving input:
	void add_tags(vector<string> tags_entered); // tags entered to be added to the database
	vector<string> search_tags(); // tags entered in the search box
	void record_obj(string disk_ad);  // Check if db_file exist, then save input to database text file
	Pic_obj load_obj(int line_to_read); // creates a pic_obj from a line in the db
	void create_db(string db_name); // Creates database with file name db_name (txt file)
	

};

//tags
// int family, friends, aggieland, pets, vacation;
