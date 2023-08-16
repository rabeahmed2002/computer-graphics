#include <iostream>
#include <cmath>
#include <GL/glut.h> 

typedef struct { float x, y; } tRealPoint;

class Canvas {
private:
    tRealPoint CP;
public:
    Canvas() { CP.x = CP.y = 0.0; }
    void lineTo(float x, float y);
    void moveTo(float x, float y) { CP.x = x; CP.y = y; }
};

void Canvas::lineTo(float x, float y) {
    glBegin(GL_LINES);
    glVertex2f((GLfloat)CP.x, (GLfloat)CP.y);
    CP.x = x; CP.y = y;
    glVertex2f((GLfloat)CP.x, (GLfloat)CP.y);
    glEnd();
    glFlush();
}

int screenWidth = 700, screenHeight = 700;
Canvas cvs;
int numSides = 5;
float angle = 0.0, delAngle = 0;

void Rosette(int N, float radius) {
    const int MaxNum = 97;
    tRealPoint pt[MaxNum];
    float angle = 2 * 3.14159265 / N;

    if (N < 3 || N >= MaxNum) return;
    for (int j = 0; j < N; j++) {
        pt[j].x = radius * cos(angle * j);
        pt[j].y = radius * sin(angle * j);
    }
    for (int i = 0; i < N - 1; i++)
        for (int j = i + 1; j < N; j++) {
            cvs.moveTo(pt[i].x, pt[i].y);
            cvs.lineTo(pt[j].x, pt[j].y);
        }
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(angle, 0, 0, 1);
    Rosette(numSides, 8);
    glutSwapBuffers();
}

void myKeys(unsigned char key, int x, int y) {
	if (key == 'n' ) {
        numSides++; 
    }
    else if (key == 'N') {
		
        numSides--; 
    }
	else if (key == 'r') {
        
        delAngle += 1.0; 
    }
    else if (key == 'R') {
		
        delAngle -= 1.0; 
    }
    else if (key == 'q' or key == 'Q') {
		
        exit(0); 
    }
    glutPostRedisplay();
    }

      

void spinner(void) {
    angle += delAngle;
    glutPostRedisplay();  
}

void myInit() {
    glClearColor(0.0314, 0.0392, 0.3216, 1.0);      
    glColor3f(0.9294, 0.1294, 0.5333);
    glPointSize(10.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);
    glViewport(0, 0, screenWidth, screenHeight);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Lab Activity(9): Implement The rosette, and the Golden 5-rosette");
    glutKeyboardFunc(myKeys);
    glutDisplayFunc(display);
    glutIdleFunc(spinner);
    myInit();
    glutMainLoop();
    return 0;
}
