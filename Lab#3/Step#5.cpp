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


// Function to handle window resizing
void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10,10,-10,10);
}

// Function to display the scene
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glFlush();
}

// changing background color
void changeWindowColor(float r, float g, float b, float a){
    glClearColor(r, g, b, a);
}

void drawMountains(float r, float g, float b){

    changeWindowColor(0.0314, 0.0392, 0.3216, 1.0);    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10,10,-10,10);
    
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(r, g, b);

    float P1 = -10.0;
    float P2 = -5.0;
    float P3 = -7.5;

    for (int i = 0; i < 5; i++){
        

        glBegin(GL_TRIANGLES);
        glVertex2f(P1,0.0);
        glVertex2f(P2,0.0);
        glVertex2f(P3,5);
        glEnd();

        P1+=5.0;
        P2+=5.0;
        P3+=5.0;

        glFlush();
    }
    
   
}


// keyboard event callback
void keyboard(unsigned char key, int x, int y) {
    if (key == 'm' or key == 'M'){

            drawMountains(0.9294, 0.1294, 0.5333);

    }else if (key == 'b'){
        std::tuple<float, float, float> randomColor = getRandomRGBColor();

        // Access individual R, G, and B components from the tuple
        float r = std::get<0>(randomColor);
        float g = std::get<1>(randomColor);
        float b = std::get<2>(randomColor);

        drawMountains(r,g,b);


    }else if(key == 'q' or key == 'Q'){
        exit(0);
    }else if(key == 'c' or key == 'C'){
        display();

    }
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Step 5: Adding Keyboard Interaction");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    changeWindowColor(0.0314, 0.0392, 0.3216, 1.0);

    glutMainLoop();
    return 0;
}
