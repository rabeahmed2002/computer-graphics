#include <GL/glut.h>
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;


const int screenWidth = 820;	   // width of screen window in pixels 
const int screenHeight = 550;	   // height of screen window in pixels

void drawPolyLineFile(string fileName)
{
	fstream inStream;

	inStream.open(fileName, ios ::in);	// open the file

	if(inStream.fail())
		{ cout << "can't open it!";return;}
	
	
	
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
	
	for (int i = 0; i < 13; i++){
		for (int j = 0; j < 13; j++){

			glViewport(i*64,j*44,64,44);
			drawPolyLineFile("dino.dat");
	
	}

	}
	glutSwapBuffers();
}


int main(int argc, char** argv)
{
	glutInit(&argc,argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); 
	glutInitWindowSize(screenWidth, screenHeight); 
	glutInitWindowPosition(10, 10); 
	
	glutCreateWindow("Lab Activity (2): Modify myDisplay() and type and run the given Code1 to get the following output 1( Tiling)"); // open the screen window
	
	
	glutDisplayFunc(myDisplay);     
	

	glClearColor(0.0314, 0.0392, 0.3216, 1.0);      
	glColor3f(0.9294, 0.1294, 0.5333);         
 	glPointSize(2.0);		                             
	
	glutMainLoop(); 		     
	
	return 1;
}


