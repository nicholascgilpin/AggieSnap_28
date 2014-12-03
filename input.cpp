#include "universal.h"

vector<string> Display_Window::f_search(string db_fname, Tag_obj t)
{
	ifstream ist(db_fname.c_str());
	string raw_string, pic_name;
	int str_start, str_end, found;
	bool contains_tag; // if any of the tags found, push to the results
	char trash_newlines;
	bool btag_aray[] = { t.family, t.friends, t.aggieland, t.pets, t.vacation };
	string tag_aray[] = { "family", "friends", "aggieland", "pets", "vacation" };
	vector<string> s_results;
	if (!ist) error("can't open input file", db_fname);
	// Read entire line,parse each line, stop if end of file is found

	while (true)
	{
		if (ist.eof()) break; // exit if end of file
		getline(ist, raw_string);
		for (int i = 0; i <= 4; i++)
		{
			if (btag_aray[i]){ found = raw_string.find(tag_aray[i]); }
			else { found = -1; }
			if (found >= 0) //any tag is present
			{
				contains_tag = true;
				str_start = raw_string.find('(') + 1;
				str_end = raw_string.find(',') - 1;
				pic_name = raw_string.substr(str_start, str_end);
			}
		}
		if (contains_tag)
		{
			s_results.push_back(pic_name);
			contains_tag = false;
			found = -1;
		}
	}
	if ((s_results[0] == "") && (s_results.size() == 1)){ cout << "No matches.\n"; }
	return s_results;
}
/*

//User will input file and tags
add_file()
{
	if(family==0)
	{
		family_s = "family";
	}
	else
	{
		family_s = ' ';
	}
	if(friends==0)
	{
		friends_s = "friends";
	}
	else
	{
		friends_s = ' ';
	}
	if(aggieland==0)
	{
		aggieland_s = "aggieland";
	}
	else
	{
		aggieland_s = ' ';
	}
	if(pets==0)
	{
		pets_s = "pets";
	}
	else
	{
		pets_s = ' ';
	}
	if(vacation==0)
	{
		vacation_s = "vacation";
	}
	else
	{
		vacation_s = ' ';
	}
	if (URLstring[0] == 'h' && URLstring[1] == 't' && URLstring[2] == 't' && URLstring[3] == 'p')//if a URL exists
	{
		system((string("wget ") + URLstring + " –O " + file_name).c_str());
		ofs.open(db_filename, fstream::app);
		ofs << file_name << ',' << family_s << ',' << friends_s << ',' << aggieland_s << ',' << pets_s << ',' << vacation_s << "\n";
		ofs.close();
		family_i = 0;
		friends_i = 0;
		aggieland_i = 0;
		pets_i = 0;
		vacation_i = 0;
	}
	// you can use to_lower so that you don't have to put different cases here
	else if (file_name.substr(file_name.find_last_of(".") + 1) == "jpg" || file_name.substr(file_name.find_last_of(".") + 1) == "jpeg" || file_name.substr(file_name.find_last_of(".") + 1) == "gif" || file_name.substr(file_name.find_last_of(".") + 1) == "JPG" || file_name.substr(file_name.find_last_of(".") + 1) == "JPEG" || file_name.substr(file_name.find_last_of(".") + 1) == "GIF")
	{
		ofs.open(db_filename, fstream::app);
		ofs << file_name << ',' << family_s << ',' << friends_s << ',' << aggieland_s << ',' << pets_s << ',' << vacation_s << "\n";
		ofs.close();
		family_i = 0;
		friends_i = 0;
		aggieland_i = 0;
		pets_i = 0;
		vacation_i = 0;
	}
	else //wrong file type
	{
		Error_window(Point(0,0), 500, 200, "Error!");
	}
}

*/