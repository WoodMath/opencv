#include "callbacks.hpp"


#ifdef DEBUG
	#define DEBUG_FN(X)	{std::cout << X << std::endl;}
#else
	#define DEBUG_FN(X)
#endif


#define TRUE 	(1)
#define FALSE	(0)



extern int bTriggerEnabled;

void onMouse(int event, int x, int y, int flags, void* userdata){
	if ( event == EVENT_LBUTTONDOWN ){
		bTriggerEnabled = TRUE;

		DEBUG_FN("Mouse Button Pressed");
		DEBUG_FN(std::endl);

		return;
	}else if  ( event == EVENT_RBUTTONDOWN ) {
		bTriggerEnabled = TRUE;

		DEBUG_FN("Mouse Button Pressed");
		DEBUG_FN(std::endl);

		return;
	}else if  ( event == EVENT_MBUTTONDOWN ) {
		bTriggerEnabled = TRUE;

		DEBUG_FN("Mouse Button Pressed");
		DEBUG_FN(std::endl);

		return;
	}else if ( event == EVENT_MOUSEMOVE ){

	}
}


