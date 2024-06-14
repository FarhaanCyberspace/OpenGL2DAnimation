#include <GL/glut.h>
#include <cmath>


struct TriangleData {
    float x; float y; float angle; float length; float r; float g; float b;
};

struct SquareData {
    float x; float y; float sideLength; float r; float g; float b;
};

TriangleData T1currPos { 200,170,-45,50,0.56,0.01,0.0 };
TriangleData T2currPos { 185,195,0,25,0.87,0.58,0.38 };
TriangleData T3currPos { 200,170,135,50,0.73,0.0,0.0 };
TriangleData T4currPos { 200,170,225,50,0.48,0.2,0.0 };
TriangleData T5currPos { 200,169,45,37,0.6,0.01,0.0 };
TriangleData T6currPos{ 210,219,180,25,0.87,0.58,0.38 };

TriangleData T1finalPos{ 178,152,-90,50,0.56,0.01,0.0 };
TriangleData T2finalPos{ 203,199,60,25,0.87,0.58,0.38 };
TriangleData T3finalPos{ 180,152,0,60,0.73,0.0,0.0 };
TriangleData T4finalPos{ 190,250,240,50,0.48,0.2,0.0 };
TriangleData T5finalPos{ 170,152,-90,37,0.67,0.01,0.0 };
TriangleData T6finalPos{ 181,82,0,20,0.87,0.58,0.38 };

int squaresize = 0;

void drawTriangle(float x, float y, float angle, float length, float r, float g, float b) {
    // Calculate the vertices of the right-angled triangle based on the rotation angle
    angle = (3.142 / 180.0) * angle;

    float x1 = x;
    float y1 = y;

    float x2 = x + length * cos(angle);
    float y2 = y + length * sin(angle);

    float x3 = x + length * cos(angle + 1.5708);  // 1.5708 radians is 90 degrees
    float y3 = y + length * sin(angle + 1.5708);

    glBegin(GL_TRIANGLES);
    glColor3f(r, g, b);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

void drawSquare(float x, float y, float sideLength, float r, float g, float b) {
    float halfSide = 0.5f * sideLength;

    glBegin(GL_QUADS);
    glColor3f(r, g, b);
    glVertex2f(x - halfSide, y - halfSide);
    glVertex2f(x + halfSide, y - halfSide);
    glVertex2f(x + halfSide, y + halfSide);
    glVertex2f(x - halfSide, y + halfSide);
    glEnd();
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Lower Stomach
    drawTriangle(T1currPos.x, T1currPos.y, T1currPos.angle, T1currPos.length, T1currPos.r, T1currPos.g, T1currPos.b);

    // draw Face
    drawTriangle(T2currPos.x, T2currPos.y, T2currPos.angle, T2currPos.length, T2currPos.r, T2currPos.g, T2currPos.b);

    // Upper Stomach
    drawTriangle(T3currPos.x, T3currPos.y, T3currPos.angle, T3currPos.length, T3currPos.r, T3currPos.g, T3currPos.b);

    // Hat
    drawTriangle(T4currPos.x, T4currPos.y, T4currPos.angle, T4currPos.length, T4currPos.r, T4currPos.g, T4currPos.b);

    // Draw Tail
    drawTriangle(T5currPos.x, T5currPos.y, T5currPos.angle, T5currPos.length, T5currPos.r, T5currPos.g, T5currPos.b);

    // Draw Foot
    drawTriangle(T6currPos.x, T6currPos.y, T6currPos.angle, T6currPos.length, T6currPos.r, T6currPos.g, T6currPos.b);

    // Draw Legs
    drawSquare(188, 112, squaresize, 0.5, 0.0, 0.01);


    glFlush();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // White background
    gluOrtho2D(0.0, 400.0, 0.0, 300.0);   // Set up an orthographic view
}

void update(int value) {
    T1currPos.x != T1finalPos.x ? (T1currPos.x < T1finalPos.x ? T1currPos.x += 1 : T1currPos.x > T1finalPos.x ? T1currPos.x -= 1 : ' ') : ' ';
    T1currPos.y != T1finalPos.y ? (T1currPos.y < T1finalPos.y ? T1currPos.y += 1 : T1currPos.y > T1finalPos.y ? T1currPos.y -= 1 : ' ') : ' ';
    T1currPos.angle != T1finalPos.angle ? (T1currPos.angle < T1finalPos.angle ? T1currPos.angle += 1 : T1currPos.angle > T1finalPos.angle ? T1currPos.angle -= 1 : ' ') : ' ';
    T1currPos.length != T1finalPos.length ? (T1currPos.length < T1finalPos.length ? T1currPos.length += 1 : T1currPos.length > T1finalPos.length ? T1currPos.length -= 1 : ' ') : ' ';

    T2currPos.x != T2finalPos.x ? (T2currPos.x < T2finalPos.x ? T2currPos.x += 1 : T2currPos.x > T2finalPos.x ? T2currPos.x -= 1 : ' ') : ' ';
    T2currPos.y != T2finalPos.y ? (T2currPos.y < T2finalPos.y ? T2currPos.y += 1 : T2currPos.y > T2finalPos.y ? T2currPos.y -= 1 : ' ') : ' ';
    T2currPos.angle != T2finalPos.angle ? (T2currPos.angle < T2finalPos.angle ? T2currPos.angle += 1 : T2currPos.angle > T2finalPos.angle ? T2currPos.angle -= 1 : ' ') : ' ';
    T2currPos.length != T2finalPos.length ? (T2currPos.length < T2finalPos.length ? T2currPos.length += 1 : T2currPos.length > T2finalPos.length ? T2currPos.length -= 1 : ' ') : ' ';

    T3currPos.x != T3finalPos.x ? (T3currPos.x < T3finalPos.x ? T3currPos.x += 1 : T3currPos.x > T3finalPos.x ? T3currPos.x -= 1 : ' ') : ' ';
    T3currPos.y != T3finalPos.y ? (T3currPos.y < T3finalPos.y ? T3currPos.y += 1 : T3currPos.y > T3finalPos.y ? T3currPos.y -= 1 : ' ') : ' ';
    T3currPos.angle != T3finalPos.angle ? (T3currPos.angle < T3finalPos.angle ? T3currPos.angle += 1 : T3currPos.angle > T3finalPos.angle ? T3currPos.angle -= 1 : ' ') : ' ';
    T3currPos.length != T3finalPos.length ? (T3currPos.length < T3finalPos.length ? T3currPos.length += 1 : T3currPos.length > T3finalPos.length ? T3currPos.length -= 1 : ' ') : ' ';

    T4currPos.x != T4finalPos.x ? (T4currPos.x < T4finalPos.x ? T4currPos.x += 1 : T4currPos.x > T4finalPos.x ? T4currPos.x -= 1 : ' ') : ' ';
    T4currPos.y != T4finalPos.y ? (T4currPos.y < T4finalPos.y ? T4currPos.y += 1 : T4currPos.y > T4finalPos.y ? T4currPos.y -= 1 : ' ') : ' ';
    T4currPos.angle != T4finalPos.angle ? (T4currPos.angle < T4finalPos.angle ? T4currPos.angle += 1 : T4currPos.angle > T4finalPos.angle ? T4currPos.angle -= 1 : ' ') : ' ';
    T4currPos.length != T4finalPos.length ? (T4currPos.length < T4finalPos.length ? T4currPos.length += 1 : T4currPos.length > T4finalPos.length ? T4currPos.length -= 1 : ' ') : ' ';

    T5currPos.x != T5finalPos.x ? (T5currPos.x < T5finalPos.x ? T5currPos.x += 1 : T5currPos.x > T5finalPos.x ? T5currPos.x -= 1 : ' ') : ' ';
    T5currPos.y != T5finalPos.y ? (T5currPos.y < T5finalPos.y ? T5currPos.y += 1 : T5currPos.y > T5finalPos.y ? T5currPos.y -= 1 : ' ') : ' ';
    T5currPos.angle != T5finalPos.angle ? (T5currPos.angle < T5finalPos.angle ? T5currPos.angle += 1 : T5currPos.angle > T5finalPos.angle ? T5currPos.angle -= 1 : ' ') : ' ';
    T5currPos.length != T5finalPos.length ? (T5currPos.length < T5finalPos.length ? T5currPos.length += 1 : T5currPos.length > T5finalPos.length ? T5currPos.length -= 1 : ' ') : ' ';

    T6currPos.x != T6finalPos.x ? (T6currPos.x < T6finalPos.x ? T6currPos.x += 1 : T6currPos.x > T6finalPos.x ? T6currPos.x -= 1 : ' ') : ' ';
    T6currPos.y != T6finalPos.y ? (T6currPos.y < T6finalPos.y ? T6currPos.y += 1 : T6currPos.y > T6finalPos.y ? T6currPos.y -= 1 : ' ') : ' ';
    T6currPos.angle != T6finalPos.angle ? (T6currPos.angle < T6finalPos.angle ? T6currPos.angle += 1 : T6currPos.angle > T6finalPos.angle ? T6currPos.angle -= 1 : ' ') : ' ';
    T6currPos.length != T6finalPos.length ? (T6currPos.length < T6finalPos.length ? T6currPos.length += 1 : T6currPos.length > T6finalPos.length ? T6currPos.length -= 1 : ' ') : ' ';

    if (squaresize < 20) {
        squaresize++;
    }

    // Redraw the scene
    glutPostRedisplay();
    glutTimerFunc(32, update, 0); // 60 frames per second
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Samurai Animation");

    init();

    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0); // Start the timer
    glutMainLoop();

    return 0;
}