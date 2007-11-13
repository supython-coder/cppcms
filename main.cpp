#include <boost/scoped_array.hpp>
#include <pthread.h>
#include <sstream>
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"
#include "fcgio.h"

#include "main_thread.h"
#include "thread_pool.h"


using namespace std;
using namespace boost;

int  global_exit_flag = 0;

All_Configuration config = { "localhost","root","root","cppcms" };


int main(int argc,char **argv)
{
	char *socket="/tmp/php-fastcgi.socket";

	try{

		FastCGI_ST<Main_Thread> app(socket);
		
		app.execute();

		cout<<"Finished\n";
		
	}
	catch(HTTP_Error &s) {
		cerr<<s.get()<<endl;
	}
		
	return 0;
}