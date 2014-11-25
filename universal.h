#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

class Intro_Window : Graph_lib::Window{

    //Data Members
    Button continue_button;

    static void cb_continue(Address,Address);
        void continue_on();

    public: 
        Intro_Window(Point xy, int w, int h, const string& title);
};


//Class Display_Window creates the window and allows one to take input, manages the buttons and displays images
class Display_Window : Graph_lib::Window{
	// Data members
	// Constants
	static const int int_limit = 2147483640; // largest possible int and db size limit
	static int index;					 // An index of the current db line number
	static bool search_mode;		 // true if the program is in search mode

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
	Button add_tag_button;
	Button add_url_button;
	Button add_file_button;
    Button quit_button;//click to exit program
   /*
    In_box add_url;//allows you to enter urls
    In_box add_file;//allows user to input a new file name and tags
    Out_box mode; //indicates what images are being displayed 
	Out_box tags_displayed; //displays what tags are showing 
    */
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
	static void cb_add_tag(Address,Address);
        void add_tag();
	static void cb_add_url(Address,Address);
        void add_url();
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
	bool check_index_range(int i);	// Corrects index range errors
	void set_search_mode(bool b);	// Changes the search_mode indicator and display

};

//Error message window
struct Error_window : Graph_lib::Window{
	Error_window(Point xy, int w, int h, const string& title );
private:
	Text message;
	Button ok_button;
	
	void ok;
	static void cb_ok(Address, Address);
}; 
Error_window::Error_window(Point xy, int w, int h, const string& title)
	:Window(xy,w,h,title),
	message(Point(0,0), "Incorrect input! Try again.")
	{
		attach(message);
		attach(ok_button);
	}
void //..............add functions later. refer to drill 8 for reference
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
	//tag[0]: family, tag[1]: friends, tag[2]: aggieland, tag[3]: pets, tag[4]: vacation
	vector<string> find_tags; //find_tags keeps track of which tags to search for
	Image pic;		// picture given by user
	string db_filename = "db.agsnap";
	ofstream ofs;		// write to db
	ifstream ifs;	// read db

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
