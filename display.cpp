#include "univeral.h"

Display_Window::Display_Window(Point xy, int w, const string& title):Window(xy,w,h,title),
    next_button(Point(x_max()-70,100),70,20,"Next",cb_next),
    previous_button(Point(x_max()-70,130),70,20,"Previous",cb_previous),
    home_button(Point(x_max()-70,140),70,20,"Home",cb_home),
    quit_button(Point(x_max()-70,0),70,20,"Quit",cb_quit),
    search(Point)x_max()- 
    