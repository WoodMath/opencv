//#include <windows.h>	
//#include <gl/gl.h>	
#include "objects.h"	
	
objects::objects()	
{	
	// insert your code here
}	
	
// class destructor	
objects::~objects()	
{	
	// insert your code here
}	
	
/*	
void poly::print(std::ostream &stream)	
{	
           stream << " got here " << std::endl;	
           stream << " address is " << &stream << std::endl;	
                    	
}	
*/	
cube::cube()	
{	
                        	
}	
cube::~cube()	
{	
                         	
}	
	
	
triangle::triangle()	
{	
                        	
}	
	
void triangle::draw(HWND hWnd, HDC &hDC, HGLRC &hRC, float &theta)	
{	
            /* OpenGL animation code goes here */	
///*	
            glClearColor (0.0f, 0.0f, 0.0f, 0.0f);	
            glClear (GL_COLOR_BUFFER_BIT);	
	
            glPushMatrix ();	
            glRotatef (theta, 0.0f, 0.0f, 1.0f);	
            glBegin (GL_TRIANGLES);	
            glColor3f (1.0f, 0.0f, 0.0f);   glVertex2f (0.0f, 1.0f);	
            glColor3f (0.0f, 1.0f, 0.0f);   glVertex2f (0.87f, -0.5f);	
            glColor3f (0.0f, 0.0f, 1.0f);   glVertex2f (-0.87f, -0.5f);	
            glEnd ();	
            glPopMatrix ();	
	
            SwapBuffers (hDC);	
	
            theta += 1.0f;	
            Sleep (1);	
//*/                   	
}	
	
triangle::~triangle()	
{	
                         	
}	
