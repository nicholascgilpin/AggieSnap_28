#include "universal.h"
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
	if (URLstring)//if a URL exists
	{
		system((string("wget ") + URLstring + " –O " + file_name).c_str());
		ofs.open(db_filename, ios_base::out);
		ofs << file_name << ',' << tag[0] << ',' << tag[1] << ',' << tag[2] << ',' << tag[3] << ',' << tag[4] << '\n';
		ofs.close();
	}
	// you can use to_lower so that you don't have to put different cases here
	else if (file_name.substr(file_name.find_last_of(".") + 1) == "jpg" || file_name.substr(file_name.find_last_of(".") + 1) == "jpeg" || file_name.substr(file_name.find_last_of(".") + 1) == "gif")
	{
		ofs.open(db_filename, ios_base::out);
		ofs << file_name << ',' << tag[0] << ',' << tag[1] << ',' << tag[2] << ',' << tag[3] << ',' << tag[4] << '\n';
		ofs.close();
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
