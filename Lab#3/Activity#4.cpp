#include <GL/glut.h>
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

float zoomFactor = 1.0; // Initial zoom factor

const int screenWidth = 650;	   // width of screen window in pixels 
const int screenHeight = 450;	   // height of screen window in pixels

void drawPolyLineFile(string fileName)
{
	fstream inStream;

	inStream.open(fileName, ios ::in);	// open the file

	if(inStream.fail())
		{ cout << "can't open it!";return;}
	
	glClear(GL_COLOR_BUFFER_BIT);      // clear the screen

	//GLint numpolys, numPoints, x ,y;
	
	GLfloat numpolys, numPoints, x ,y;
	inStream >> numpolys;		           // read the number of polylines
	
	for(int j = 0; j < numpolys; j++)  // read each polyline
	{
		inStream >> numPoints;       //number of points in first PolyLine  
		glBegin(GL_LINE_STRIP);	     // draw the next polyline
		for (int i = 0; i < numPoints; i++)
		{
			inStream >> x >> y;        // read the next x, y pair
			glVertex2f(x, y);
		}
		glEnd();
	}
	glFlush();
	inStream.close();
}

void myDisplay(void)
{
	glClearColor(0.0314, 0.0392, 0.3216, 1.0);       // background color is white
	glColor3f(0.9294, 0.1294, 0.5333);         // drawing color is black
 	glPointSize(2.0);		          // a 'dot' is 2 by 2 pixels
	glMatrixMode(GL_PROJECTION); 	   
	glLoadIdentity();
	gluOrtho2D(0.0*zoomFactor, (GLdouble)screenWidth*zoomFactor, 0.0*zoomFactor, (GLdouble)screenHeight*zoomFactor);//dino window
	glViewport(0,0,screenWidth,screenHeight);
	
    
	
	drawPolyLineFile("dino.dat");
	
	glutSwapBuffers();
    

}

void keyboard(unsigned char key, int x, int y) {
    if (key == '+') {
        zoomFactor *= 0.9; // Zoom in by 10%
        glutPostRedisplay(); // Request a redraw to apply the zoom
		// std::cout<<zoomFactor<<"\n";
    }
    else if (key == '-') {
		
        zoomFactor *= 1.1; // Zoom out by 10%
        glutPostRedisplay(); // Request a redraw to apply the zoom
		// std::cout<<zoomFactor<<"\n";
    }
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // set display mode
	glutInitWindowSize(screenWidth, screenHeight); // set window size
	glutInitWindowPosition(10, 10); // set window position on screen
	glutCreateWindow("Lab Activity (4): Zooming in and Zooming out on a figure"); // open the screen window
	
	glutDisplayFunc(myDisplay);     // register redraw function
	glutKeyboardFunc(keyboard);

	
	glutMainLoop(); 		     // go into a perpetual loop
	return 1;
}


