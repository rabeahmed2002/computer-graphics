#include <GL/glut.h>
#include <string>

void drawText(std::string text, int x, int y) {
    glRasterPos2f(x, y);
    int Len = text.length();
    for (int i = 0; i < Len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }
}

// changing background color
void changeWindowColor(float r, float g, float b, float a){
    glClearColor(r, g, b, a);
}

void display() {
    changeWindowColor(0.0314, 0.0392, 0.3216, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    
    glColor3f(0.9294, 0.1294, 0.5333);
    drawText("Lab # 3", 250, 400);
    drawText("Computer Graphics using OpenGL :)", 250, 420);

    glFlush();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("STEP 7: Writing Text to the Screen");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    changeWindowColor(0.0314, 0.0392, 0.3216, 1.0);

    glutMainLoop();
    return 0;
}
