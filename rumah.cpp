#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>

static int slices = 25;
static int stacks = 25;
float ratio;
float yCord = -2.5;
float zCord = -60.0;
float RotateX = -30.0f;
float RotationSpeedX = 0.0f;
float RotasiKipas = 0.0f;
float RotasiKipas2 = 0.0f;
float KecRot = 0.0f;
float KecRot2 = 0.0f;
float LightZ = 26.0f;
float LightX = 0.0f;
float LightY = 15.0f;

GLfloat light_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat light_position[] = { LightX, LightY, LightZ, 0.0f };
GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat high_shininess[] = { 100.0f };

static void resize(int width, int height) {
 const float ar = (float)width / (float)height;
 glViewport(0, 0, width, height);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y) {
 switch (key) {
 case 27:
  exit(0);
  break;
  glutPostRedisplay();
 }
}

void specialkeys(int key, int x, int y) {
 switch (key) {
 case GLUT_KEY_RIGHT:
  RotationSpeedX -= 0.02;
  if (RotationSpeedX <= -0.1)
   RotationSpeedX = -0.1;
  break;
 case GLUT_KEY_LEFT:
  RotationSpeedX += 0.02;
  if (RotationSpeedX >= 0.1)
   RotationSpeedX = 0.1;
  break;
 case GLUT_KEY_UP:
  zCord += 0.2;
  if (zCord >= -10.0)
   zCord = -10.0;
  break;
 case GLUT_KEY_DOWN:
  zCord -= 0.1;
  if (zCord <= -60.0)
   zCord = -60.0;
  break;
 case GLUT_KEY_PAGE_DOWN:
  yCord += 0.1f;
  if (yCord >= 15.0)
   yCord = 15.0;
  break;
 case GLUT_KEY_PAGE_UP:
  yCord -= 0.1;
  if (yCord <= -15.0)
   yCord = -15.0;
  break;
 case GLUT_KEY_F1:
  KecRot += 0.3;
  if (KecRot >= 0.0)
   KecRot = 0.0;
  break;
 case GLUT_KEY_F2:
  KecRot -= 0.2;
  if (KecRot <= -50.0)
   KecRot = -50.0;
  break;
 case GLUT_KEY_F3:
  KecRot2 += 0.3;
  if (KecRot2 >= 0.0)
   KecRot2 = 0.0;
  break;
 case GLUT_KEY_F4:
  KecRot2 -= 0.2;
  if (KecRot2 <= -50.0)
   KecRot2 = -50.0;
  break;
 default:
  break;

 }
 glutPostRedisplay();
}

void sumbu(void) {
 glColor3f(1.0, 0.0, 0.0);
 glBegin(GL_LINES);
 glVertex3f(-30.0, 0.0, 0.0);
 glVertex3f(30.0, 0.0, 0.0);
 glEnd();

 glColor3f(0.0, 1.0, 0.0);
 glBegin(GL_LINES);
 glVertex3f(0.0, 10, 0.0);
 glVertex3f(0.0, -10.0, 0.0);
 glEnd();

 glColor3f(0.0, 0.0, 1.0);
 glBegin(GL_LINES);
 glVertex3f(0.0, 0.0, -30.0);
 glVertex3f(0.0, 0.0, 30.0);
 glEnd();
}
static void display(void) {
 gluLookAt(1.0, 10.0, 15.0, 0.0, 0.0, 5.0, 0.0, 10.0, 0.0);
 const double t = glutGet(GLUT_ELAPSED_TIME) / 10000.0;
 const double t2 = glutGet(GLUT_ELAPSED_TIME) / 20.0;
 const double a = t * 90.0, b = t / 2, c = t / 10, d = t2 * 90;
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 glLoadIdentity();
 glTranslatef(0.0, yCord, zCord);
 glTranslatef(0.0, yCord, 0.0);
 glRotatef(RotateX, 0, 1.0, 0);
 RotasiKipas += KecRot;
 RotasiKipas2 += KecRot2;
 RotateX += RotationSpeedX;
 glPushMatrix();
 sumbu();
 glPopMatrix();

//Pondasi lantai
 glPushMatrix();
 glTranslated(0.0, 0.0, 0.0);
 glScaled(60.0, 0.5, 30.0);
 glColor3d(0.0, 0.0, 0.0);
 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
 glutSolidCube(1);
 glPopMatrix();
 
 //lantai
 glPushMatrix();
 glTranslated(0.0, 0.4, 0.0);
 glScaled(60.0, 0.1, 30.0);
 glColor3d(1.0, 1.0, 1.0);
 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
 glutSolidCube(1);
 glPopMatrix();

 //tembok 1 sumbu z
 glPushMatrix();
 glTranslated(-29.5, 7.5, 4.5);
 glScaled(1.0, 14.0, 21.0);
 glColor3d(1.0, 1.0, 0.0);
 glutSolidCube(1);
 glPopMatrix();

 //tembok 2 sumbu x
 glPushMatrix();
 glTranslated(-27.0, 7.5, -5.5);
 glScaled(5.0, 14.0, 1.0);
 glColor3d(1.0, 1.0, 0.0);
 glutSolidCube(1);
 glPopMatrix(); 
 
 //tembok 3 sumbu z
 glPushMatrix();
 glTranslated(-25.0, 7.5, -6.5);
 glScaled(1.0, 14.0, 2.0);
 glColor3d(1.0, 1.0, 0.0);
 glutSolidCube(1);
 glPopMatrix(); 
 
 //tembok 4 sumbu z atas
 glPushMatrix();
 glTranslated(-25.0, 13.0, -10.5);
 glScaled(1.0, 3.0, 6.0);
 glColor3d(1.0, 1.0, 0.0);
 glutSolidCube(1);
 glPopMatrix(); 
 
 //tembok 5 sumbu z
 glPushMatrix();
 glTranslated(-25.0, 7.5, -14.0);
 glScaled(1.0, 14.0, 2.0);
 glColor3d(1.0, 1.0, 0.0);
 glutSolidCube(1);
 glPopMatrix();
 
 //tembok 6 sumbu x
 glPushMatrix();
 glTranslated(2.5, 7.5, -14.5);
 glScaled(55.0, 14.0, 1.0);
 glColor3d(1.0, 1.0, 0.0);
 glutSolidCube(1);
 glPopMatrix();
 
 //tembok 7 sumbu z
 glPushMatrix();
 glTranslated(29.5, 7.5, 0.0);
 glScaled(1.0, 14.0, 30.0);
 glColor3d(1.0, 1.0, 0.0);
 glutSolidCube(1);
 glPopMatrix();
 
 //tembok 8 sumbu z
 glPushMatrix();
 glTranslated(10.0, 7.5, -12.0);
 glScaled(1.0, 14.0, 6.0);
 glColor3d(1.0, 1.0, 0.0);
 glutSolidCube(1);
 glPopMatrix();
 
 //tembok 9 sumbu x
 glPushMatrix();
 glTranslated(19.5, 3.5, -3.5);
 glScaled(20.0, 6.0, 1.0);
 glColor3d(1.0, 1.0, 0.0);
 glutSolidCube(1);
 glPopMatrix(); 
 
 //tembok 10 sumbu z
 glPushMatrix();
 glTranslated(10.0, 3.5, 3.5);
 glScaled(1.0, 6.0, 13.0);
 glColor3d(1.0, 1.0, 0.0);
 glutSolidCube(1);
 glPopMatrix();
 
 //Keset
 glPushMatrix();
 glTranslated(-22.0, 0.6, -10.0);
 glScaled(3.5, 0.2, 5.0);
 glColor3d(0.0, 0.0, 0.0);
 glutSolidCube(1);
 glPopMatrix();

//Mesin Cuci
 glPushMatrix();
 glTranslated(-27.0, 3.5, 13.0);
 glScaled(4.0, 6.0, 4.0);
 glColor3d(0.686, 0.933, 0.93);
 glutSolidCube(1);
 glPopMatrix();

//bulat mesin cuci
 glPushMatrix();
 glTranslated(-25.5, 3.5, 13.0);
 glScaled(1.0, 2.0, 2.0);
 glColor3d(1, 1, 1);
 glutSolidSphere(1,slices,stacks);  
 glPopMatrix();


 //bingkai pintu utama 1
 glPushMatrix();
 glTranslated(-25.0, 6.0, -7.6);
 glScaled(1.0, 11.0, 0.2);
 glColor3d(1.0, 0.4, 0.0);
 glutSolidCube(1);
 glPopMatrix(); 
 
 //bingkai pintu utama 2
 glPushMatrix();
 glTranslated(-25.0, 11.4, -10.4);
 glScaled(1.0, 0.2, 5.4);
 glColor3d(1.0, 0.4, 0.0);
 glutSolidCube(1);
 glPopMatrix();
  
 glutSwapBuffers();
 glutPostRedisplay();

}
int main(int argc, char* argv[]) {
 glutInit(&argc, argv);
 glutInitWindowSize(800, 600);
 glutInitWindowPosition(200, 100);
 glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

 glutCreateWindow("Kelompok H-1");
 glutReshapeFunc(resize);
 glutDisplayFunc(display);
 glutKeyboardFunc(keyboard);
 glutSpecialFunc(specialkeys);

 glClearColor(1, 1, 1, 1);
 glEnable(GL_CULL_FACE);
 glCullFace(GL_BACK);

 glEnable(GL_DEPTH_TEST);
 glDepthFunc(GL_LESS);

 glEnable(GL_LIGHT0);
 glEnable(GL_NORMALIZE);
 glEnable(GL_COLOR_MATERIAL);
 glEnable(GL_LIGHTING);

 glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
 glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
 glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
 glLightfv(GL_LIGHT0, GL_POSITION, light_position);

 glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
 glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
 glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
 glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

 glutMainLoop();
 return EXIT_SUCCESS;
}



