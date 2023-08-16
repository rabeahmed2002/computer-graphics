#include <GL/glut.h>
#include <iostream>
#include <random>
#include <tuple>
#include <vector>

// Brush properties
int brushSize = 10;
float brushColor[3] = { 0.9294, 0.1294, 0.5333 };

// Store points for the brush stroke
std::vector<std::pair<int, int>> points;


// Function to generate a random RGB color as float values from 0 to 1
std::tuple<float, float, float> getRandomRGBColor() {
    // Obtain a random seed from the system
    std::random_device rd;

    // Mersenne Twister 19937 generator
    std::mt19937 gen(rd());

    // Distribution for RGB color values (0.0 to 1.0)
    std::uniform_real_distribution<float> dis(0.0f, 1.0f);

    // Generate random values for R, G, and B components
    float r = dis(gen);
    float g = dis(gen);
    float b = dis(gen);

    // Return the RGB color as a tuple
    return std::make_tuple(r, g, b);
}



// Function to draw the brush stroke
void drawBrushStroke() {
    glColor3fv(brushColor);
    glPointSize(brushSize);
    glBegin(GL_POINTS);
    for (const auto& point : points) {
        glVertex2i(point.first, point.second);
    }
    glEnd();
}

// Function to handle mouse motion
void mouseMotion(int x, int y) {
    points.push_back(std::make_pair(x, y));
    glutPostRedisplay();
}

// Function to handle window resizing
void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}

// Function to display the scene
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawBrushStroke();
    glFlush();
}

// changing background color
void changeWindowColor(float r, float g, float b, float a){
    glClearColor(r, g, b, a);
}


// keyboard event callback
void keyboard(unsigned char key, int x, int y) {
    if (key == '+'){

        brushSize+=10;

    }else if (key == '-'){
        brushSize-=10;
        if (brushSize <= 10){
            brushSize=10;
        }

    }else if (key == 'b'){
        std::tuple<float, float, float> randomColor = getRandomRGBColor();

        // Access individual R, G, and B components from the tuple
        float r = std::get<0>(randomColor);
        float g = std::get<1>(randomColor);
        float b = std::get<2>(randomColor);

        brushColor[0] = r; // Red
        brushColor[1] = g; // Green
        brushColor[2] = b; // Blue

    }else if(key == 'q' or key == 'Q'){
        exit(0);
    }else if(key == 'c' or key == 'C'){

        points.clear();
        glutPostRedisplay();

    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Step 03: Free Hand Drawing with Fat Brush");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMotionFunc(mouseMotion); // Register the mouse motion callback function
    glutKeyboardFunc(keyboard);

    changeWindowColor(0.0314, 0.0392, 0.3216, 1.0);

    glutMainLoop();
    return 0;
}
