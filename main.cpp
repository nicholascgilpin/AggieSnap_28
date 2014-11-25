#include "universal.h"

int main()
try {
	if (H112 != 201401L)error("Error: incorrect std_lib_facilities_4.h version ", H112);
	//Dispay_Window w(Point(100,200),800,1000,"Aggie Snap!");
	// Start our graphics code here see Ch. 15/16 for implementation help
	return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Some exception\n";
	return 2;
	//testing
	
}