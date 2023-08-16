#include <GL/glut.h>
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;


float VP_X = 0.0;
float VP_Y = 0.0;
float VP_WIDTH = 650.0;
float VP_HEIGHT = 450.0;



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

void window(int xs, int xe, int ys, int ye){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(xs, xe, ys, ye);//dino window

}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	
	window(0,screenWidth,0,screenHeight);
	glViewport(VP_X,VP_Y,VP_WIDTH,VP_HEIGHT);
	drawPolyLineFile("dino.dat");

	glutSwapBuffers();
}


void keyboard(unsigned char key, int x, int y) {
	if (key == '1' ) {
        VP_WIDTH += 10.0; 
        glutPostRedisplay(); 
    }
    else if (key == '2') {
		
        VP_WIDTH -= 10.0;
        glutPostRedisplay(); 
    }
	else if (key == '3') {
        VP_HEIGHT += 10.0; 
        glutPostRedisplay(); 
    }
    else if (key == '4') {
		
        VP_HEIGHT -= 10.0;
        glutPostRedisplay(); 
    }
}

void specialKeys(int key, int x, int y) {

	if (key == GLUT_KEY_RIGHT) {
        VP_X += 10.0; 
        glutPostRedisplay(); 
    }
    else if (key == GLUT_KEY_LEFT) {
		
        VP_X -= 10.0; 
        glutPostRedisplay(); 
    }
	else if (key == GLUT_KEY_UP) {
        VP_Y += 10.0; 
        glutPostRedisplay(); 
    }
    else if (key == GLUT_KEY_DOWN) {
		
        VP_Y -= 10.0;
        glutPostRedisplay(); 
    }
}


int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // set display mode
	glutInitWindowSize(screenWidth, screenHeight); // set window size
	glutInitWindowPosition(10, 10); // set window position on screen
	glutCreateWindow("Lab Activity (5): Make a Viewport Dynamic.( Output is attached) i.e Roaming a.k.a Panning (To move the view in a specific direction"); // open the screen window
	
	glutDisplayFunc(myDisplay);     // register redraw function
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeys);

	glClearColor(0.0314, 0.0392, 0.3216, 1.0);      
	glColor3f(0.9294, 0.1294, 0.5333);         
 	glPointSize(2.0);
	
	glutMainLoop(); 		     // go into a perpetual loop
	return 1;
}


