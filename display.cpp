//testing display 

#include "display.h"

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
   
void Display_Window:: cb_quit(Address, Address pw)
	{
		reference_to<Display_Window>(pw).quit();
	}
void Display_Window::quit()
	{
		hide();
	}
	
