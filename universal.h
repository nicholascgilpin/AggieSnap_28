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
	vector<Pic_obj> s_results;		// An array of picture objects
	vector<strings> tags_to_save;
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
    In_box add_url;//allows you to enter urls
    In_box add_file;//allows user to input a new file name and tags
    /*Out_box mode; //indicates what images are being displayed 
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
        void tag();
	static void cb_friends(Address,Address);
        void tag();
	static void cb_aggieland(Address,Address);
        void tag();
	static void cb_pets(Address,Address);
        void tag();
	static void cb_vacation(Address,Address);
        void tag();
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
	void draw_image(string fname); // takes an image and draws it to the screen at Point(50,20)
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

//Input_object class is used to create and store input objects (picture and tags)
class Pic_obj
{
public:
	string URLstring;
	// Parts of a database object:
	string file_name;
	vector<string> new_tags; //contains tags to be saved
	//tag[0]: family, tag[1]: friends, tag[2]: aggieland, tag[3]: pets, tag[4]: vacation
	Image pic;		// picture given by user
};
// Handles reading and writing from the database---------------//
class db_access
{
public:
	vector<string> find_tags; //find_tags keeps track of which tags to search for
	string db_filename = "Test_db.txt";
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
	void save_obj(string disk_ad);  // Check if db_file exist, then save input to database text file
	void load_obj(int line_to_read) // creates a pic_obj from a line in the db
	void create_db(string db_name); // Creates database with file name db_name (txt file)

};
