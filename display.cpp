
#include "universal.h"

Display_Window::Display_Window(Point xy, int w, int h, const string& title):Window(xy,w,h,title),
    quit_button(Point(x_max()-70,0),70,20,"Quit",cb_quit),
	next_button(Point(x_max()-70,30),70,20,"Next",cb_quit),
    previous_button(Point(x_max()-70,60),70,20,"Previous",cb_quit),
    home_button(Point(x_max()-70,90),70,20,"Home",cb_quit)

   //search(Point)x_max()- */
   
   {
		attach(next_button);
		attach(previous_button);
		attach(home_button);
		attach(quit_button);
		attach(search);
		attach(add_url);
		attach(add_input);
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
// Actual Functions -------------------------------
// Corrects index range errors
// I might need to use qualified names for the vars...
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
/* // postponed until we get closer to this part----------------
// Reads line of file, displays pic & tags, increments index

void Display_Window::next()
	{
		check_index_range(index);
		if (index = 0)
		{
			// get the picture from the first line of file
			// attach picture 
			// redraw
			check_index_range(index); // prevent range errors
			index += 1;
			}
		else if (index < 0)
		{
			// get picture from the next line of file
			// attach picture 
			// redraw
			// increment browser index
		}
		
	}
// Reads index-1 line of file, displays pic & tags, decrements index
void Display_Window::previous()
	{
		check_index_range(index);
		// add code
	}
*/
void Display_Window::quit()
	{
		hide();
	}













