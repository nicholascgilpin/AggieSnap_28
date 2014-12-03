#include "universal.h"
Intro_Window::Intro_Window(Point xy, int w, int h, const string& title):Window(xy,w,h,title),
	continue_button(Point(x_max()-440,480),70,20,"Continue",cb_continue),
	welcome(Point(x_max()-650,50),"Welcome to AggieSnap!"),
	instructions(Point(x_max()-700,400),"Upload pictures by using the following format: 'filename.jpg, tag1, tag2, etc.' ")
	{
		welcome.set_font_size(50);
		attach(continue_button);
		attach(welcome);
		attach(instructions);
	}
Display_Window::Display_Window(Point xy, int w, int h, const string& title):Window(xy,w,h,title),
 	quit_button(Point(x_max()-70,0),70,20,"Quit",cb_quit),
	next_button(Point(x_max()-70,30),70,20,"Next",cb_next),
    previous_button(Point(x_max()-70,60),70,20,"Previous",cb_previous),
    home_button(Point(x_max()-70,90),70,20,"Home",cb_home),
	family(Point(x_max()-600,480),70,20,"Family",cb_family),
	friends(Point(x_max()-520,480),70,20,"Friends",cb_friends),
	aggieland(Point(x_max()-440,480),70,20,"Aggieland",cb_aggieland),
	pets(Point(x_max()-360,480),70,20,"Pets",cb_pets),
	vacation(Point(x_max()-280,480),70,20,"Vacation",cb_vacation),
	search_button(Point(x_max()-200,480),70,20,"Search",cb_search),
	add_file_button(Point(x_max()-95,510),70,20,"Add",cb_add_file),
	input_file(Point(x_max()-600,510),500,20,"Add File:"),
	input_url(Point(x_max()-600,530),500,20,"Add URL"),
	mode(Point(x_max()-400,20),120,30,"Displaying: "),
	tags_displayed(Point(x_max()-600,460),120,20,"Active Tags:")
   {
		attach(next_button);
		attach(previous_button);
		attach(home_button);
		attach(family);
		attach(friends);
		attach(aggieland);
		attach(pets);
		attach(vacation);
		attach(search_button);
		attach(add_file_button);
		attach(quit_button);
		attach(input_file);
		attach(input_url);
		attach(mode);
		attach(tags_displayed);

   }
// Holla back Functions!-----------------------------
   
void Display_Window:: cb_quit(Address, Address pw)
	{
		reference_to<Display_Window>(pw).quit();
	}
void Display_Window:: cb_next(Address,Address pw)
	{
		reference_to<Display_Window>(pw).next();
	}
void Display_Window:: cb_previous(Address,Address pw)
	{
		reference_to<Display_Window>(pw).previous();
	}
void Display_Window:: cb_home(Address,Address pw)
	{
		reference_to<Display_Window>(pw).home();
	}
void Display_Window:: cb_family(Address,Address pw)
	{
		reference_to<Display_Window>(pw).tag0();
	}
void Display_Window:: cb_friends(Address,Address pw)
	{
		reference_to<Display_Window>(pw).tag1();
	}
void Display_Window:: cb_aggieland(Address,Address pw)
	{
		reference_to<Display_Window>(pw).tag2();
	}
void Display_Window:: cb_pets(Address,Address pw)
	{
		reference_to<Display_Window>(pw).tag3();
	}
void Display_Window:: cb_vacation(Address,Address pw)
	{
		reference_to<Display_Window>(pw).tag4();
	}
void Display_Window:: cb_search(Address,Address pw)
	{
		reference_to<Display_Window>(pw).search();
	}
void Display_Window:: cb_add_file(Address,Address pw)
	{
		reference_to<Display_Window>(pw).add_file();
	}
void Intro_Window:: cb_continue(Address,Address pw)
	{
		reference_to<Intro_Window>(pw).continue_on();
	}
// Actual Functions ------------------------------------//
void Intro_Window::continue_on() //closes the intro window
{
	hide();
}
 void Display_Window::set_search_mode(bool b)
{

	//search_mode = b;
	//index = 0; // Always reset index when switching modes
} 

void Display_Window::draw_image(string fname)
{
	/*Image *p = new Image(Point(50, 20), fname);
	attach(*p);
	redraw();*/
}
// check_index_range Corrects index range errors		//
// I might need to use qualified names for the vars...  
void Display_Window::check_index_range(int i)
	{
		/*if (index < 0)
		{
			cerr << "Index ranger error.";
			index = 0;

		}*/
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
		
	}
// Reads index-1 line of file, displays pic & tags, decrements index
void Display_Window::previous()
	{
		check_index_range(index);
		// add code
	}
*/
/* Nick's Todo list:
Browse all pictures.
When a picture is displayed, so are its tags.  
Provide buttons to see the Next or Previous picture.
Let buttons also work for search results
Find pictures with any combination of tags. 
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
	}
void Display_Window::add_file()
	{
		ofstream ofs;
		string URLstring = input_url.get_string();
		string file_name = input_file.get_string();
		/*
		if(family_i==0)
		{
			family_s = "family";
		}
		else
		{
			family_s = " " ;
		}
		if(friends_i==0)
		{
			friends_s = "friends";
		}
		else
		{
			friends_s = " " ;
		}
		if(aggieland_i==0)
		{
			aggieland_s = "aggieland";
		}
		else
		{
			aggieland_s = " ";
		}
		if(pets_i==0)
		{
			pets_s = "pets";
		}
		else
		{
			pets_s = " " ;
		}
		if(vacation_i==0)
		{
			vacation_s = "vacation";
		}
		else
		{
			vacation_s = " ";
		}
		*/
		if (URLstring.find("http")> -1)//if a URL exists
		{
			system((string("wget ") + URLstring + " –O " + file_name).c_str());
			ofs.open("db.txt", fstream::app);
			ofs << file_name << ',' << family_s << ',' << friends_s << ',' << aggieland_s << ',' << pets_s << ',' << vacation_s << "\n";
			ofs.close();
			/*
						family_i = 0;
			friends_i = 0;
			aggieland_i = 0;
			pets_i = 0;
			vacation_i = 0;
			*/
		}
		// you can use to_lower so that you don't have to put different cases here
		else if (file_name.substr(file_name.find_last_of(".") + 1) == "jpg" || file_name.substr(file_name.find_last_of(".") + 1) == "jpeg" || file_name.substr(file_name.find_last_of(".") + 1) == "gif" || file_name.substr(file_name.find_last_of(".") + 1) == "JPG" || file_name.substr(file_name.find_last_of(".") + 1) == "JPEG" || file_name.substr(file_name.find_last_of(".") + 1) == "GIF")
		{
			ofs.open("db.txt", fstream::app);
			ofs << file_name << ',' << family_s << ',' << friends_s << ',' << aggieland_s << ',' << pets_s << ',' << vacation_s << "\n";
			ofs.close();
			/*
			family_i = 0;
			friends_i = 0;
			aggieland_i = 0;
			pets_i = 0;
			vacation_i = 0;
			*/
		}
		else //wrong file type
		{
			//Error_window(Point(0,0), 500, 200, "Error!");
		}
	}
int main()
{
	try
	{
		if (H112 != 201401L)error("Error: incorrect std_lib_facilities_4.h version ", H112);
		Display_Window w(Point(100,100),800,600,"Aggie Snap!");
		Intro_Window i(Point(100,100),800,600,"Instructions");
		return gui_main();
	}
	catch (exception& e)
	{
		cerr << "exception: " << e.what() << '\n';
		return 1;
	}
	catch (...)
	{
		cerr << "Some exception\n";
		return 2;
		//testing

	}
}






