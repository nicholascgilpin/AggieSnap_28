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
	tags_displayed(Point(x_max()-600,460),500,20,"Active Tags:")
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
		// Set all buttons to unpressed state
		family_i = 0;
		friends_i = 0;
		aggieland_i = 0;
		pets_i = 0;
		vacation_i = 0;

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

// check_index_range Corrects index range errors		//
// I might need to use qualified names for the vars...  
void Display_Window::check_index_range()
	{
		if (index < 0)
		{
			cerr << "Index ranger error.";
			index = 0;

		}
	} 
void Display_Window::next()
{
string raw_string,pic_name;
int str_start,str_end;

		if(index < 0)
		{
			check_index_range();
		}
		else
		{
			index_read.clear();                           //Stores each line of db_filename into vector index_read. Then reads index_read[index] and extracts file name and opens it.
			ifs.open(db_filename);
			while(!ifs.eof())
			{
				getline(ifs, raw_string);
				str_start = raw_string.find('(') + 1; // gets position of the start of the pic_name
				str_end = raw_string.find(',') - 1;	// gets position of the end of the pic_name
				pic_name = raw_string.substr(str_start, str_end);
				index_read.push_back(pic_name);
			}
			//index = index + 1;
			if(ifs.eof())
				{
					index = 0;
					//cout<<"end";
					//index = index + 1;
				}
			ifs.close();
		
			draw_image(index_read[index]);
			index = index + 1;
		}
	//}	
}
void Display_Window::previous()
{
	string raw_string,pic_name;
	int str_start,str_end;
	
	if(index < 0)
		{
			check_index_range();
		}
		else
		{
			index = index - 1;
			index_read.clear();                           //Stores each line of db_filename into vector index_read. Then reads index_read[index] and extracts file name and opens it.
			ifs.open(db_filename);
			while(!ifs.eof())
			{
				getline(ifs, raw_string);
				str_start = raw_string.find('(') + 1; // gets position of the start of the pic_name
				str_end = raw_string.find(',') - 1;	// gets position of the end of the pic_name
				pic_name = raw_string.substr(str_start, str_end);
				index_read.push_back(pic_name);
			}
			ifs.close();
		
			draw_image(index_read[index]);
		}
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
		search_mode = false;
	}

void Display_Window::Display_active_tags()
{
	int current_tags[] = { family_i, friends_i, aggieland_i, pets_i, vacation_i };
	string tag_aray[] = { "family", "friends", "aggieland", "pets", "vacation" };
	string ts_arr[4]; // each string
	string tags_to_show;
	for (int k = 0; k <= 4; k++)
	{
		if (current_tags[k] > 0)
		{
			ts_arr[k] = tag_aray[k] + " ";
		}
		ostringstream active_t_stream;
		tags_to_show = ts_arr[0] + ts_arr[1] + ts_arr[2] + ts_arr[3] + ts_arr[4];
		active_t_stream << tags_to_show;
		tags_displayed.put(active_t_stream.str());
	}
}
void Display_Window::tag0()
	{
		ostringstream clean_box;
		clean_box << " ";// clears the tags box
		tags_displayed.put(clean_box.str()); // clears the tags displayed
		if (family_i == 1)
		{
			family_i = 0;
		}
		if (family_i == 0)
		{
			family_i = 1;
		}
		Display_active_tags();
}

void Display_Window::tag1()
	{
		ostringstream clean_box;
		clean_box << " ";// clears the tags box
		tags_displayed.put(clean_box.str()); // clears the tags displayed
		
		if (friends_i == 1)
		{
			friends_i = 0;
		}
		if (friends_i == 0)
		{
			friends_i = 1;
		}
		Display_active_tags();
	}
void Display_Window::tag2()
	{
		ostringstream clean_box;
		clean_box << " ";// clears the tags box
		tags_displayed.put(clean_box.str()); // clears the tags displayed
		
		if (aggieland_i == 1)
		{
			aggieland_i = 0;
		}
		if (aggieland_i == 0)
		{
			aggieland_i = 1;
		}
		Display_active_tags();
	}
void Display_Window::tag3()
	{
		ostringstream clean_box;
		clean_box << " ";// clears the tags box
		tags_displayed.put(clean_box.str()); // clears the tags displayed
		
		if (pets_i == 1)
		{
			pets_i = 0;
		}
		if (pets_i == 0)
		{
			pets_i = 1;
		}
		Display_active_tags();
	}
void Display_Window::tag4()
	{
		ostringstream clean_box;
		clean_box << " ";// clears the tags box
		tags_displayed.put(clean_box.str()); // clears the tags displayed
		
		if (vacation_i == 1)
		{
			vacation_i = 0;
		}
		if (vacation_i == 0)
		{
			vacation_i = 1;
		}
		Display_active_tags();
	}
void Display_Window::search()
	{
		//Changes the browsing status to say "Search Results"
		ostringstream ss;
		ss << "Search Results";
		mode.put(ss.str());
		Tag_obj current_tags = Tag_obj(family_i, friends_i, aggieland_i, pets_i, vacation_i);
		vector<string> results = f_search(db_filename, current_tags);
		ostringstream no_match;	// Prints message if no matches are found

		if ((results[0] == "") && (results.size() == 1))
		{
			no_match << "No matches";
			tags_displayed.put(no_match.str());
		}
		search_mode = true;
	}

void Display_Window::draw_image(string fname)
{
	detach(*p);
	p = new Image(Point(50, 50), fname);
	attach(*p);
	//virtual FL_Image *copy(int W, int H);
	redraw();
}

void Display_Window::add_file()
	{
		ofstream ofs;
		ostringstream xx;
		string URLstring = input_url.get_string();
		string file_name = input_file.get_string();
		if(family_i==1)
		{
			family_s = "family";
		}
		else
		{
			family_s = " ";
		}
		if(friends_i==1)
		{
			friends_s = "friends";
		}
		else
		{
			friends_s = " ";
		}
		if(aggieland_i==1)
		{
			aggieland_s = "aggieland";
		}
		else
		{
			aggieland_s = " ";
		}
		if(pets_i==1)
		{
			pets_s = "pets";
		}
		else
		{
			pets_s = " ";
		}
		if(vacation_i==1)
		{
			vacation_s = "vacation";
		}
		else
		{
			vacation_s = " ";
		}
		if ((int)URLstring.find("http")>-1)//if a URL exists
		{
			xx<<" ";// clears the tags box
			tags_displayed.put(xx.str()); // clears the tags displayed
			system((string("wget -O " + file_name + " " + URLstring).c_str()));
			family_i = 0;
			friends_i = 0;
			aggieland_i = 0;
			pets_i = 0;
			vacation_i = 0;
		}
		// you can use to_lower so that you don't have to put different cases here
	    if (file_name.substr(file_name.find_last_of(".") + 1) == "jpg" || file_name.substr(file_name.find_last_of(".") + 1) == "jpeg" || file_name.substr(file_name.find_last_of(".") + 1) == "gif" || file_name.substr(file_name.find_last_of(".") + 1) == "JPG" || file_name.substr(file_name.find_last_of(".") + 1) == "JPEG" || file_name.substr(file_name.find_last_of(".") + 1) == "GIF" )
		{
			xx<<" ";// clears the tags box
			ofs.open(db_filename, fstream::app);
			ofs << index << file_name << ',' << family_s << ',' << friends_s << ',' << aggieland_s << ',' << pets_s << ',' << vacation_s << "\n";
 			ofs.close();
			family_i = 0;
			friends_i = 0;
			aggieland_i = 0;
			pets_i = 0;
			vacation_i = 0;
			draw_image(file_name);

			index = index + 1;
		}		// you can use to_lower so that you don't have to put different cases here
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






