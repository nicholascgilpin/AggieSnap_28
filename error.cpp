Error_window::Error_window(Point xy, int w, int h, const string& title)
	:Window(xy,w,h,title),
	message(Point(0,100), "Incorrect input! Try again."),
	ok_button(Point(x_max()-100,0),100,25, "OK", cb_ok)
	{
		attach(message);
		attach(ok_button);
	}
void Error_window::cb_ok(Address, Address pw)
{  
       reference_to<Error_window>(pw).ok();
} 
void Error_window::ok()
{
	hide();
}