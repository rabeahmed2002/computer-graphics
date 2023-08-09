#include <iostream>
#include <string>
#include <fstream>
#include <GL/glut.h>
#include <cmath>

using namespace std;

void drawRectangle(float x, float y, float width, float height, float r, float g, float b) {
    glColor3f(r / 255.0f, g / 255.0f, b / 255.0f);
    glBegin(GL_QUADS);
    glVertex2f(x, 900 - y);                // Convert Y-axis to OpenGL coordinate system
    glVertex2f(x + width, 900 - y);        // Convert Y-axis to OpenGL coordinate system
    glVertex2f(x + width, 900 - (y + height)); // Convert Y-axis to OpenGL coordinate system
    glVertex2f(x, 900 - (y + height));     // Convert Y-axis to OpenGL coordinate system
    glEnd();
}

void drawBorderRectangle(float x, float y, float width, float height, float r, float g, float b) {
    glColor3f(r / 255.0f, g / 255.0f, b / 255.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x, 900 - y);                // Convert Y-axis to OpenGL coordinate system
    glVertex2f(x + width, 900 - y);        // Convert Y-axis to OpenGL coordinate system
    glVertex2f(x + width, 900 - (y + height)); // Convert Y-axis to OpenGL coordinate system
    glVertex2f(x, 900 - (y + height));     // Convert Y-axis to OpenGL coordinate system
    glEnd();
}

void drawEllipse(float x, float y, float width, float height, float r, float g, float b) {
    glColor3f(r / 255.0f, g / 255.0f, b / 255.0f);
    const int numSegments = 3000;
    const float M_PI = 3.14159265358979323846;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x + width / 2.0f, 900 - (y + height / 2.0f)); // Center of the ellipse
    glColor3f(0.0f, 0.0f, 0.0f);
    for (int i = 0; i <= numSegments; i++) {
        float angle = i * 2.0f * M_PI / numSegments;
        float px = x + width / 2.0f + width / 2.0f * cos(angle);
        float py = y + height / 2.0f + height / 2.0f * sin(angle);
        glVertex2f(px, 900 - py); // Convert Y-axis to OpenGL coordinate system
    }

    glEnd();
}

void drawCircle(float x, float y, float radius, float r, float g, float b) {
    glColor3f(r / 255.0f, g / 255.0f, b / 255.0f);
    const int numSegments = 1000;
    const float M_PI = 3.14159265358979323846;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, 900 - y); // Center of the circle
    glColor3f(0.0f, 0.0f, 0.0f);
    for (int i = 0; i <= numSegments; i++) {
        float angle = i * 2.0f * M_PI / numSegments;
        float px = x + radius * cos(angle);
        float py = y + radius * sin(angle);
        glVertex2f(px, 900 - py); // Convert Y-axis to OpenGL coordinate system
    }
    glEnd();
}

void drawLine(float x, float y, float width, float length, float angle, float r, float g, float b) {
    glColor3f(r / 255.0f, g / 255.0f, b / 255.0f);
    glLineWidth(width);
    glBegin(GL_LINES);
    glVertex2f(x, 900 - y); // Convert Y-axis to OpenGL coordinate system
    float x2 = x + length * cos(angle);
    float y2 = y + length * sin(angle);
    glVertex2f(x2, 900 - y2); // Convert Y-axis to OpenGL coordinate system
    glEnd();
}

void drawMonitorStand(float x, float y, float width, float height, float r, float g, float b) {
    glColor3f(r / 255.0f, g / 255.0f, b / 255.0f);
    glBegin(GL_QUADS);
    glVertex2f(x, 900 - y);                  // Convert Y-axis to OpenGL coordinate system
    glVertex2f(x + width, 900 - y);          // Convert Y-axis to OpenGL coordinate system
    glVertex2f(x + width, 900 - (y + height));// Convert Y-axis to OpenGL coordinate system
    glVertex2f(x, 900 - (y + height));       // Convert Y-axis to OpenGL coordinate system
    glEnd();
}


void drawTable(float x, float y, float width, float height, float r, float g, float b) {
    glColor3f(r / 255.0f, g / 255.0f, b / 255.0f);
    glBegin(GL_QUADS);
    glVertex2f(x, 900 - y);                // Convert Y-axis to OpenGL coordinate system
    glVertex2f(x + width, 900 - y);        // Convert Y-axis to OpenGL coordinate system
    glVertex2f(x + width, 900 - (y + height)); // Convert Y-axis to OpenGL coordinate system
    glVertex2f(x, 900 - (y + height));     // Convert Y-axis to OpenGL coordinate system
    glEnd();
}


void display() {
    glClearColor(37.0f / 255.0f, 37.0f / 255.0f, 37.0f / 255.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw Computer
    drawRectangle(462.0f, 232.0f, 305.0f, 168.0f, 217.0f, 217.0f, 217.0f);
    drawRectangle(475.0f, 241.0f, 281.0f, 149.0f, 95.0f, 95.0f, 95.0f);
    drawRectangle(602.0f, 400.0f, 21.0f, 30.0f, 217.0f, 217.0f, 217.0f);

    drawEllipse(505.0f, 430.0f, 213.0f, 30.0f, 217.0f, 217.0f, 217.0f);

    // Draw CPU
    drawRectangle(908.0f, 240.0f, 112.0f, 205.0f, 217.0f, 217.0f, 217.0f);
    drawRectangle(915.0f, 249.0f, 97.0f, 67.0f, 95.0f, 95.0f, 95.0f);

    drawRectangle(957.0f, 343.0f, 13.0f, 11.0f, 95.0f, 95.0f, 95.0f);

    drawBorderRectangle(951.0f, 364.0f, 25.0f, 8.0f, 0.0f, 0.0f, 0.0f);
    drawBorderRectangle(951.0f, 381.0f, 25.0f, 8.0f, 0.0f, 0.0f, 0.0f);


    // Draw Speaker
    drawRectangle(271.0f, 354.0f, 73.0f, 93.0f, 217.0f, 217.0f, 217.0f);
    drawRectangle(279.0f, 364.0f, 55.0f, 62.0f, 95.0f, 95.0f, 95.0f);

    drawCircle(305.0f, 437.0f, 8.0f, 95.0f, 95.0f, 95.0f);

    // Draw Keyboard
    drawRectangle(429.0f, 503.0f, 387.0f, 110.0f, 217.0f, 217.0f, 217.0f);
    drawRectangle(542.0f, 596.0f, 157.0f, 10.0f, 95.0f, 95.0f, 95.0f);
    // keys

    // row 1
    drawRectangle(446.0f, 518.0f, 16.0f, 14.0f, 95.0f, 95.0f, 95.0f);
    drawRectangle(487.0f, 518.0f, 16.0f, 14.0f, 95.0f, 95.0f, 95.0f);
    drawRectangle(512.0f, 518.0f, 16.0f, 14.0f, 95.0f, 95.0f, 95.0f);

    drawRectangle(537.0f, 518.0f, 16.0f, 14.0f, 95.0f, 95.0f, 95.0f);
    drawRectangle(562.0f, 518.0f, 16.0f, 14.0f, 95.0f, 95.0f, 95.0f);
    drawRectangle(587.0f, 518.0f, 16.0f, 14.0f, 95.0f, 95.0f, 95.0f);

    drawRectangle(612.0f, 518.0f, 16.0f, 14.0f, 95.0f, 95.0f, 95.0f);
    drawRectangle(637.0f, 518.0f, 16.0f, 14.0f, 95.0f, 95.0f, 95.0f);
    drawRectangle(662.0f, 518.0f, 16.0f, 14.0f, 95.0f, 95.0f, 95.0f);
    drawRectangle(687.0f, 518.0f, 16.0f, 14.0f, 95.0f, 95.0f, 95.0f);

    drawRectangle(737.0f, 518.0f, 16.0f, 14.0f, 95.0f, 95.0f, 95.0f);
    drawRectangle(762.0f, 518.0f, 16.0f, 14.0f, 95.0f, 95.0f, 95.0f);
    drawRectangle(787.0f, 518.0f, 16.0f, 14.0f, 95.0f, 95.0f, 95.0f);


    // row 2

    drawRectangle(446.0f, 544.0f, 16.0f, 14.0f, 95.0f, 95.0f, 95.0f);
    drawRectangle(487.0f, 544.0f, 16.0f, 14.0f, 95.0f, 95.0f, 95.0f);
    drawRectangle(512.0f, 544.0f, 16.0f, 14.0f, 95.0f, 95.0f, 95.0f);

    drawRectangle(537.0f, 544.0f, 16.0f, 14.0f, 95.0f, 95.0f, 95.0f);
    drawRectangle(562.0f, 544.0f, 16.0f, 14.0f, 95.0f, 95.0f, 95.0f);
    drawRectangle(587.0f, 544.0f, 16.0f, 14.0f, 95.0f, 95.0f, 95.0f);

    drawRectangle(612.0f, 544.0f, 16.0f, 14.0f, 95.0f, 95.0f, 95.0f);
    drawRectangle(637.0f, 544.0f, 16.0f, 14.0f, 95.0f, 95.0f, 95.0f);
    drawRectangle(662.0f, 544.0f, 16.0f, 14.0f, 95.0f, 95.0f, 95.0f);
    drawRectangle(687.0f, 544.0f, 16.0f, 14.0f, 95.0f, 95.0f, 95.0f);

    drawRectangle(737.0f, 544.0f, 16.0f, 14.0f, 95.0f, 95.0f, 95.0f);
    drawRectangle(762.0f, 544.0f, 16.0f, 14.0f, 95.0f, 95.0f, 95.0f);
    drawRectangle(787.0f, 544.0f, 16.0f, 14.0f, 95.0f, 95.0f, 95.0f);


    //row 3

    drawRectangle(446.0f, 570.0f, 16.0f, 14.0f, 95.0f, 95.0f, 95.0f);
    drawRectangle(487.0f, 570.0f, 16.0f, 14.0f, 95.0f, 95.0f, 95.0f);
    drawRectangle(512.0f, 570.0f, 16.0f, 14.0f, 95.0f, 95.0f, 95.0f);

    drawRectangle(537.0f, 570.0f, 16.0f, 14.0f, 95.0f, 95.0f, 95.0f);
    drawRectangle(562.0f, 570.0f, 16.0f, 14.0f, 95.0f, 95.0f, 95.0f);
    drawRectangle(587.0f, 570.0f, 16.0f, 14.0f, 95.0f, 95.0f, 95.0f);

    drawRectangle(612.0f, 570.0f, 16.0f, 14.0f, 95.0f, 95.0f, 95.0f);
    drawRectangle(637.0f, 570.0f, 16.0f, 14.0f, 95.0f, 95.0f, 95.0f);
    drawRectangle(662.0f, 570.0f, 16.0f, 14.0f, 95.0f, 95.0f, 95.0f);
    drawRectangle(687.0f, 570.0f, 16.0f, 14.0f, 95.0f, 95.0f, 95.0f);

    drawRectangle(737.0f, 570.0f, 16.0f, 14.0f, 95.0f, 95.0f, 95.0f);
    drawRectangle(762.0f, 570.0f, 16.0f, 14.0f, 95.0f, 95.0f, 95.0f);
    drawRectangle(787.0f, 570.0f, 16.0f, 14.0f, 95.0f, 95.0f, 95.0f);



    // Draw Mouse
    /*(float x, float y, float width, float length, float angle, float r, float g, float b)*/

    drawEllipse(945.0f, 525.0f, 49.0f, 65.0f, 217.0f, 217.0f, 217.0f);
    drawLine(967.0f, 555.0f, 3.0f, 30.0f, 86.4f, 0.0f, 0.0f, 0.0f);
    drawLine(945.0f, 554.0f, 3.0f, 52.0f, 0.0f, 0.0f, 0.0f, 0.0f);

    // Draw Monitor Stand
    drawMonitorStand(550.0f, 100.0f, 200.0f, 30.0f, 217.0f, 217.0f, 217.0f);
    drawMonitorStand(550.0f, 100.0f, 200.0f, 30.0f, 217.0f, 217.0f, 217.0f);

    drawTable(350.0f, 80.0f, 600.0f, 30.0f, 217.0f, 217.0f, 217.0f);

    glFlush();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1280, 900);
    glutCreateWindow("2D Computer Setup");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
