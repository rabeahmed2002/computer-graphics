#include <GL/glut.h>

float minX=-10, minY=-10, maxX=10, maxY=10;
int VP_Bottom=0, VP_Left=0, VP_Width=640, VP_Height=480;


void drawAxis(){
    
    glColor3f(0.9294, 0.1294, 0.5333);
    glBegin(GL_LINES);
    glVertex2f(minX,0);
    glVertex2f(maxX,0);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0,minY);
    glVertex2f(0,maxY);
    glEnd();
   
}

void myDisplay(void){

    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(VP_Bottom,VP_Left,VP_Width,VP_Height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(minX,maxX,minY,maxY);
    drawAxis();
    glFlush();
}

// changing background color
void changeWindowColor(float r, float g, float b, float a){
    glClearColor(r, g, b, a);
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(VP_Width, VP_Height);
    glutCreateWindow("Step 04: Using both ViewPort and World Window");

    glutDisplayFunc(myDisplay);

    changeWindowColor(0.0314, 0.0392, 0.3216, 1.0);

    glutMainLoop();
    return 0;
}
