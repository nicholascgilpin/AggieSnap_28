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
	vector<string> s_results;
	if (!ist) error("can't open input file", db_fname);
	// while not at end of file
	//		read line
	//		if any tag is present
	//			set in_s_results to true and add to s_results
	//		return list;
}
int main()
{
	cout << "Entering a file name:";
	string fname = "Test_db.txt";
	search(fname);
}
/*
class classname
{
tag;
};
// your code
classname object;
object.tag = 1;
*/