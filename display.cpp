
// #include "universal.h"
// remove this include when adding to the main function
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
	add_tag_button(Point(x_max()-120,480),70,20,"Add",cb_add_tag),
	add_url_button(Point(x_max()-95,510),70,20,"Add URL",cb_add_url),
	add_file_button(Point(x_max()-95,540),70,20,"Add File",cb_add_file),
	input_url(Point(x_max()-600,510),500,20,"Add URL:"),
	input_file(Point(x_max()-600,540),500,20,"Add File:"),
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
		attach(add_tag_button);
		attach(add_url_button);
		attach(add_file_button);
		attach(quit_button);
		attach(input_url);
		attach(input_file);
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
void Display_Window::set_search_mode(bool b)
{
	search_mode = b;
	index = 0; // Always reset index when switching modes
}
/*
void Display_Window::draw_image(string fname)
{
Image *p = new Image(Point(50, 20), fname);
attach(*p);
redraw();
}
*/
/* check_index_range Corrects index range errors		//
// I might need to use qualified names for the vars...  */
void Display_Window::check_index_range(int i)
	{
		if (index < 0)
		{
			cerr << "Index ranger error.";
			index = 0; 
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

	}
void Display_Window::tag1()
	{

	}
void Display_Window::tag2()
	{

	}
void Display_Window::tag3()
	{

	}
void Display_Window::tag4()
	{

	}
void Display_Window::search()
	{
		//Changes the browsing status to say "Search Results"
		ostringstream ss;
		ss<<"Search Results";
		mode.put(ss.str());
	}
void Display_Window::add_tag()
	{

	}
void Display_Window::add_url()
	{

	}
void Display_Window::add_file()
	{

	}










