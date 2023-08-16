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


void DisplayPoint(int x, int y){
    
    // glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1000, 0, 1000);

    // Draw

    glPointSize(10.0);
    glColor3f(0.9294, 0.1294, 0.5333);

    glBegin(GL_POINTS);

    glVertex2f(x,1000-y);

    glEnd();


    glFlush();


}


// changing background color
void changeWindowColor(float r, float g, float b, float a){
    glClearColor(r, g, b, a);
}

// reshape event callback
void reShape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1000, 0, 1000);
}

// mouse event callback
void Mouse(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){

        std::tuple<float, float, float> randomColor = getRandomRGBColor();

        // Access individual R, G, and B components from the tuple
        float r = std::get<0>(randomColor);
        float g = std::get<1>(randomColor);
        float b = std::get<2>(randomColor);

        // std::cout << x << " " << y << "\n"; 

        DisplayPoint(x,y);

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
    }else if(key == 'c' or key == 'C'){

        Display();

    }
}

int main(int argc , char ** argv){

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);


    glutInitWindowPosition(750,0);
    glutInitWindowSize(1000,1000);


    glutCreateWindow("STEP 2: Placing Dots with Mouse");


    glutDisplayFunc(Display);
    glutReshapeFunc(reShape);
    glutMouseFunc(Mouse);
    glutKeyboardFunc(keyboard);

    changeWindowColor(0.0314, 0.0392, 0.3216, 1.0);

    glutMainLoop();
}

