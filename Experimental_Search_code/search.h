
struct Tag_obj
{
	//contains tags
	bool family;
	bool friends;
	bool aggieland;
	bool pets;
	bool vacation;

	Tag_obj::Tag_obj(bool dfam, bool dfr, bool dag, bool dpt, bool dva)
	{
		family = dfam;
		friends = dfr;
		aggieland = dag;
		pets = dpt;
		vacation = dva;
	}

};
struct Pic_obj
{
	string URLstring;
	// Parts of a database object:
	string file_name;
	Tag_obj tags;

	Pic_obj::Pic_obj(string dpname, Tag_obj dt)
	{
		file_name = dpname;
		tags = dt;
	}

};