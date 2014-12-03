#include "std_lib_facilities_4.h"
#include "test.h"

Tag_obj::Tag_obj(bool dfam, bool dfr, bool dag, bool dpt, bool dva)
{
	family = dfam;
	friends = dfr;
	aggieland = dag;
	pets = dpt;
	vacation = dva;
}
Pic_obj::Pic_obj(string dpname, Tag_obj dt)
{
	file_name = dpname;
	tags = dt;
}
vector<string> search(string db_fname, Tag_obj t )
{
	ifstream ist(db_fname.c_str());
	string raw_string, pic_name;
	int str_start, str_end;
	bool contains_tag; // if any of the tags found, push to the results
	string tag_aray[] = { "family", "friends", "aggieland", "pets", "vacation" };
	vector<string> s_results;
	if (!ist) error("can't open input file", db_fname);
	// Read entire line,parse each line, stop if end of file is found
	
	/*	// In dire need of debugging
		while (true)
	{
		if (ist.eof()) return; // exit if end of file
		getline(ist, raw_string);
		for (i = 0; i <= 4;i++)
		{
			std::size_t found = raw_string.find(tag_aray[i]);
			if (found >= 0) //any tag is present
			{
				contains_tag = true;
				str_start = found + 1;
				str_end = raw_string.find(',') - 1;
				pic_name = raw_string.substr(str_start, str_end);
			}
		}
		if (contains_tag)
		{
			s_results.push_back(pic_name);
			contains_tag = false;
		}
	}
	*/

	return s_results;
}
int main()
{
	cout << "Entering a file name:";
	string fname = "Test_db.txt";
	search(fname);
}
