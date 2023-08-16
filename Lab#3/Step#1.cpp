#include <GL/glut.h>
#include <iostream>
#include <random>
#include <tuple>

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

void Display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();


    glFlush();

}

void reShape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW);
}

void changeWindowColor(float r, float g, float b, float a){
    glClearColor(r, g, b, a);
}

// mouse even callback
void Mouse(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){

        std::tuple<float, float, float> randomColor = getRandomRGBColor();

        // Access individual R, G, and B components from the tuple
        float r = std::get<0>(randomColor);
        float g = std::get<1>(randomColor);
        float b = std::get<2>(randomColor);


        Display();
        changeWindowColor(r, g, b, 1.0);

    }

}

// keyboard event callback
void keyboard(unsigned char key, int x, int y) {
    if (key == 'b' or key == 'B'){

        std::tuple<float, float, float> randomColor = getRandomRGBColor();

        // Access individual R, G, and B components from the tuple
        float r = std::get<0>(randomColor);
        float g = std::get<1>(randomColor);
        float b = std::get<2>(randomColor);


        Display();
        changeWindowColor(r, g, b, 1.0);

    }else if(key == 'q' or key == 'Q'){
        exit(0);
    }
}

int main(int argc , char ** argv){

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);


    glutInitWindowPosition(750,0);
    glutInitWindowSize(1000,1000);


    glutCreateWindow("Step1: Add Reshape, Mouse and Keyboard Handler routine to Lab 01");


    glutDisplayFunc(Display);
    glutReshapeFunc(reShape);
    glutMouseFunc(Mouse);
    glutKeyboardFunc(keyboard);

    changeWindowColor(0.0314, 0.0392, 0.3216, 1.0);

    glutMainLoop();
}

