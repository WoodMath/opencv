#include <windows.h>		
#include <gl/gl.h>		
#ifndef _OBJECTS		
#define _OBJECTS		
		
class objects		
{		
	public:	
		// class constructor
		objects();
		// class destructor
		~objects();
//		void print(std::ostream &stream);
};		
		
class triangle : public objects{		
	public:      	
      triangle();		
//      triangle(HWND hWnd, HDC *hDC, HGLRC *hRC);		
      ~triangle();		
      void draw(HWND hWnd, HDC &hDC, HGLRC &hRC, float &theta);     		
      		
};		
		
class cube : public objects{		
	public:      	
      cube();		
      ~cube();		
//      void print(std::ostream &stream);     		
      		
};		
#endif // POLY_H		
