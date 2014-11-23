#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;


//Class Display_Window creates the window and allows one to take input, manages the buttons and displays images
class Display_Window : Graph_lib::Window{
	// Data members
	// Constants
	static const int int_limit = 2147483640; // largest possible int and db size limit
	static int index = 0;					 // An index of the current db line number
	static bool search_mode = false;		 // true if the program is in search mode

	// Buttons
	Button next_button;
	Button previous_button;
	Button home_button; //click to return to viewing all images
	Button quit_button;
	// Boxes
	// In_box search; //creates the input bar to search tags
	// In_box add_url;//allows you to enter urls
	// In_box add_input;//allows user to input a new file name and tags
	// Out_box mode; //indicates what images are being displayed
	
	// Function Declarations
	static void cb_next(Address, Address);
	void next();
	static void cb_previous(Address, Address);
	void previous();
	static void cb_home(Address, Address);
	void home();
	static void cb_quit(Address, Address);
	void quit();

	/*static void cb_search(Address,Address);
	void find();
	static void cd_add(Address, Address);
	void add();*/

public:

	Display_Window(Point xy, int w, int h, const string& title);
	bool check_index_range(int i);	// Corrects index range errors
	void set_search_mode(bool b);	// Changes the search_mode indicator and display

};

//Input_object class is used to create and store input objects (picture and tags)
class Input_obj{
public:
	string URLstring;
	/* examples:
	- local files only require a filename
	- "http://www.hdwallpapersimages.com/wp-content/uploads/2014/01/Winter-Tiger-Wild-Cat-Images-540x303.jpg" */
	// Parts of a database object:
	string file_name;
	vector<string> new_tags; //contains tags to be saved

	vector<string> find_tags; //find_tags keeps track of which tags to search for
	Image pic;		// picture given by user
	string db_filename = "db.agsnap";
	ofstream ofs(db_filename.c_str(),ios_base::in);		// write to db
	ifstream ifs(db_filename.c_str(), ios_base::out);	// read db

	// Functions for taking input:
	void check_ftype(string file_name); // Check type of file/if allowed
	void check_ltype(string location);   // Decide if looking for a file location or URL location
	void add_picture(string location, string filename); // Download File/URL and name it filename
	//- Allow recovery if Url can’t be downloaded/opened from disk
	//- Allow recovery if incorrect file/url format
	// Function for saving input:
	void add_tags(vector<string> tags_entered); // check how many tags are already entered, and add more if possible
	vector<string> search_tags(vector<string> tags_to_find); // searches for tags entered in the search box,returns the relevant list of files
	void save_obj(string disk_ad);  // Check if db_file exist, then save input to database text file
	void create_db(string db_name); // Creates database with file name db_name (txt file)



};
