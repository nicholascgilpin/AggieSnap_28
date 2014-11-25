
#include "universal.h"
// You should clarify these magic numbers. See page 530 of textbook for demo.
Display_Window::Display_Window(Point xy, int w, int h, const string& title):Window(xy,w,h,title),
    quit_button(Point(x_max()-70,0),70,20,"Quit",cb_quit),
	next_button(Point(x_max()-70,30),70,20,"Next",cb_quit),
    previous_button(Point(x_max()-70,60),70,20,"Previous",cb_quit),
    home_button(Point(x_max()-70,90),70,20,"Home",cb_quit),
	family(Point(x_max()-600,480),70,20,"Family",cb_quit),
	friends(Point(x_max()-520,480),70,20,"Friends",cb_quit),
	aggieland(Point(x_max()-440,480),70,20,"Aggieland",cb_quit),
	pets(Point(x_max()-360,480),70,20,"Pets",cb_quit),
	vacation(Point(x_max()-280,480),70,20,"Vacation",cb_quit),
	search_button(Point(x_max()-70,0),70,20,"Search",cb_quit),
	add_tag_button(Point(x_max()-70,0),70,20,"Add",cb_quit),
	add_url_button(Point(x_max()-70,0),70,20,"Add URL",cb_quit),
	add_file_button(Point(x_max()-70,0),70,20,"Add File",cb_quit)

   //search(Point)x_max()- */
   
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
		attach(add_tag_button);
		attach(add_url_button);
		attach(add_file_button);
		attach(quit_button);
		//
		//attach(add_url);
		//attach(add_file);
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
void Display_Window:: cb_add_tag(Address,Address pw)
	{
		reference_to<Display_Window>(pw).add_tag();
	}
void Display_Window:: cb_add_url(Address,Address pw)
	{
		reference_to<Display_Window>(pw).add_url();
	}
void Display_Window:: cb_add_file(Address,Address pw)
	{
		reference_to<Display_Window>(pw).add_file();
	}
// Actual Functions ------------------------------------//
set_search_mode(bool b)
{
	Display_Window::search_mode = b;
	Display_Window::index = 0; // Always reset index when switching modes
}
/* check_index_range Corrects index range errors		//
// I might need to use qualified names for the vars...  */
bool check_index_range(int i)
	{
		if ((index < 0) || (index > int_limit))
		{
			cerr << "Index ranger error.";
			index = 0; 
			return true; // index will always be in range here
		}
		else if ((index >= 0) && (index < int_limit))
		{
			return true; 
		}
	}
// Reads line of file, displays pic & tags, increments index
void Display_Window::next()
	{
		check_index_range(index);
		if (search_mode) // Searching
		{
			if (index == 0)
			{
				// if index = 0 then we're on the default picture
				// get the picture from the first spot in vector
				// attach picture 
				// redraw
			}
			if (index < 0)
			{
				// get picture from s_vector[i+1];
				// attach picture 
				// redraw
				// increment browser index
			}
		}
		if (!search_mode) // Browsing
		{
			if ()
			{
				// if index = 0 then we're on the default picture
				// get the picture from the first line of file/
				// attach picture 
				// redraw
			}
			if (index < 0)
			{
				// get picture from the next line of file
				// attach picture 
				// redraw
				// increment browser index
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

/* Nick's Todo list:
Browse all pictures.
When a picture is displayed, so are its tags.  
Provide buttons to see the Next or Previous picture.
Let buttons also work for search results
Find pictures with any combination of tags. 
*/
void Display_Window::quit()
	{
		hide();
	}













