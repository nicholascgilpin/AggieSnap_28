#include "universal.h"

/* istream& operator>>(istream& is, Data_obj& a) //when user adds a new file
{
	char ch1, ch2, ch3, ch4, ch5; //commas
	is >> file_name >> ch1 >> tag[0] >> ch2 >> tag[1] >> ch3 >> tag[2] >> ch4 >> tag[3] >> ch5 >> tag[4]; //will work on tag vector later 
	if (!is) return is;
	if (ch1 != ',' || ch2 != ',' || ch3 != ',' || ch4 != ',' || ch5 != ',') //format error
	{
		is.clear(ios_base::failbit);
		return is;
	}

	add = Data_obj(file_name, tag[0], tag[1], tag[2], tag[3], tag[4]); //update entry

	return is;
} */ //buttons might make this unnecessary
//-----------------------------------------------------------------------------------------------
//User will input file and tags
if (URLstring)//if a URL exists
{
	system((string("wget ") + URLstring + " –O " + file_name).c_str());
	ofs.open("file_names.txt", ios_base::out);
	ofs << file_name << ',' << tag[0] << ',' << tag[1] << ',' << tag[2] << ',' << tag[3] << ',' << tag[4] << '\n';
	ofs.close();
}
// you can use to_lower so that you don't have to put different cases here
else if (file_name.substr(file_name.find_last_of(".") + 1) == "jpg" || file_name.substr(file_name.find_last_of(".") + 1) == "jpeg" || file_name.substr(file_name.find_last_of(".") + 1) == "gif")
{
	ofs.open("file_names.txt", ios_base::out);
	ofs << file_name << ',' << tag[0] << ',' << tag[1] << ',' << tag[2] << ',' << tag[3] << ',' << tag[4] << '\n';
	ofs.close();
}
else //wrong file type
{
	Error()
}
