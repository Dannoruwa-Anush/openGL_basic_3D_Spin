#include <GL/glut.h>
#include <GL/glu.h>

GLfloat T = 0; //Global variable

void myInit(){
    glClearColor(0,0,0,1); //R G B Transparency (background color)
    glColor3f(1,0,0); //set to RED (drawing color)
    glEnable(GL_DEPTH_TEST);
}

void mySpin(){
  T = T + 0.05;
  if(T > 360){
    T = 0;
  }
  glutPostRedisplay();
}

void drawFace(GLfloat fp0[], GLfloat fp1[], GLfloat fp2[], GLfloat fp3[]){
    glBegin(GL_POLYGON); //group data points as a single object

        /*
        glVertex3f(fp0[0], fp0[1], fp0[2]); //data point 1 of the one square of the cube
        glVertex3f(fp1[0], fp1[1], fp1[2]); //data point 2 of the one square of the cube
        glVertex3f(fp2[0], fp2[1], fp2[2]); //data point 3 of the one square of the cube
        glVertex3f(fp3[0], fp3[1], fp3[2]); //data point 4 of the one square of the cube
        */

        glVertex3fv(fp0); //data point 1 of the one square of the cube as a vertex
        glVertex3fv(fp1); //data point 2 of the one square of the cube as a vertex
        glVertex3fv(fp2); //data point 3 of the one square of the cube as a vertex
        glVertex3fv(fp3); //data point 4 of the one square of the cube as a vertex
    glEnd();
}

void drawCube(GLfloat V0[], GLfloat V1[], GLfloat V2[], GLfloat V3[], GLfloat V4[], GLfloat V5[], GLfloat V6[], GLfloat V7[]){
    glColor3f(1, 0, 0);
    drawFace(V0, V1, V2, V3); //front

    glColor3f(0, 1, 0);
    drawFace(V4, V5, V6, V7); //back

    glColor3f(0, 0, 1);
    drawFace(V0, V3, V7, V4); //left

    glColor3f(1, 0, 1);
    drawFace(V1, V2, V6, V5); //right

    glColor3f(1, 1, 0);
    drawFace(V0, V1, V5, V4); //top

    glColor3f(0, 1, 1);
    drawFace(V3, V2, V6, V7); //bottom
}

void displayMe(void)
{
    GLfloat v[8][3] = {
                            {-0.5,  0.5,  0.5},
                            { 0.5,  0.5,  0.5},
                            { 0.5, -0.5,  0.5},
                            {-0.5, -0.5,  0.5},

                            {-0.5,  0.5, -0.5},
                            { 0.5,  0.5, -0.5},
                            { 0.5, -0.5, -0.5},
                            {-0.5, -0.5, -0.5},
                        };

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear the background and depth

    glLoadIdentity();
    glRotatef(T, 1,1,0); //use to rotate angle| axis (x,y,z)

    drawCube(v[0], v[1], v[2], v[3],v[4], v[5], v[6], v[7]);

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitWindowSize(600, 600);
    glutInitWindowPosition(250, 50);
    glutCreateWindow("Basic OpenGL - 3D");
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); //RGB | 3D |DEPTH
    myInit();

    glutDisplayFunc(displayMe);
    glutIdleFunc(mySpin); //Idle function
    glutMainLoop();
    return 0;
}
