#include "std_lib_facilities_4.h"
#include "search.h"

vector<string> search(string db_fname, Tag_obj t )
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
		for (int i = 0; i <= 4;i++)
		{
			if (btag_aray[i]){ found = raw_string.find(tag_aray[i]); }
			else { found = -1; }
			if (found >= 0) //any tag is present
			{
				cout << "found :" << found;
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
int main()
{
	cout << "Entering a file name:\n";
	string fname = "Test_db.txt";
	Tag_obj tags_to_find(1, 0, 0, 0, 0); // find friends
	vector<string> s_results = search(fname,tags_to_find);
	for (int k = 0; k <= s_results.size() - 1; k++)
	{
		cout << s_results[k];
	}
	
}
