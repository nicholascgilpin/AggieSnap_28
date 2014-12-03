/*#include "universal.h"
Pic_obj::Pic_obj(string URL, string f_name, vector<string> tags, Image p)
{
	URLstring = URL;
	file_name = f_name;
	new_tags = tags;
	pic = p;
}

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
		family = 0;
		friends = 0;
		aggieland = 0;
		pets = 0;
		vacation = 0;
	}
	// you can use to_lower so that you don't have to put different cases here
	else if (file_name.substr(file_name.find_last_of(".") + 1) == "jpg" || file_name.substr(file_name.find_last_of(".") + 1) == "jpeg" || file_name.substr(file_name.find_last_of(".") + 1) == "gif" || file_name.substr(file_name.find_last_of(".") + 1) == "JPG" || file_name.substr(file_name.find_last_of(".") + 1) == "JPEG" || file_name.substr(file_name.find_last_of(".") + 1) == "GIF")
	{
		ofs.open(db_filename, fstream::app);
		ofs << file_name << ',' << family_s << ',' << friends_s << ',' << aggieland_s << ',' << pets_s << ',' << vacation_s << "\n";
		ofs.close();
		family = 0;
		friends = 0;
		aggieland = 0;
		pets = 0;
		vacation = 0;
	}
	else //wrong file type
	{
		Error_window(Point(0,0), 500, 200, "Error!");
	}
}

Pic_obj load_obj(int line_to_read) // create picture object from db line
{
	ifstream ist(db_filename.c_str());
	string raw_line;
	if (!ist) {	cerr << "Error: Database does not exist!"}
	// skip to a line
	for (int i = 0; i < line_to_read; i++)
	{
		getline(ist, raw_line);
	}
	// parse the rawline
	ist << '(' << file_name << ',' << tag[0] << ',' << tag[1] << ',' << tag[2] << ',' << tag[3] << ',' << tag[4] << ')' << '\n';
	// Pic_Obj constructor
	return Pic_obj(string file_name, vector<string> tags, Image file_name);
}
*/