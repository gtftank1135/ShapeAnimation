//Gavin Franklin
//Final Project
//Shape Animation
#include <stdio.h>
//This is my node class
#include "Node.h"
//This includes the glut library for the 3d rendering
#include "GL/glut.h"
//This allows me to put a delay in the animation loop
#include <time.h>
//The next five libraries are all needed for save and load
//gets converter
#include <sstream>
//output streaming
#include <fstream>
#include <iostream>
#include <string>
//This library allows me to output floats without the program rounding up
#include <iomanip>

using namespace std;
//These create the necessary instances of Node in order to properly manipulate the shapes
Node* head = new Node(NULL, NULL);
Node* current = head;
Node* holder = head;

//My two streams are input and output
ifstream inFile;
ofstream outFile;

//Converter
stringstream ss;

//Counts the nodes made so when loading in the program knows how many nodes to create
int counter = 1;

//These three variables are used for conversion in the load function
string shold;
float fhold;
int ihold;


//This is the function ran when the q button is pressed
void exitcommand(){
   current = head;
   holder = current;
   //This is my method of attempting to delete each of these nodes
   while (current != NULL)
    {   //Goes through each of the nodes and deletes them
        holder = current->getnext();
        delete current;
        current = holder;
    }
    exit(0);//Exit command
   }

//This is the save function
void save(){
   outFile.open("output.txt");
   holder = current;
   current = head;//reset the nodes but keep the current node so you can change it
   //after the save so the user does not see a change.
   outFile << counter;//This is the first thing the output file gets so when it is loaded
   //back in the program knows how many nodes to make.
   outFile << endl;
   //The for loop runs as many nodes as there are.
   for(int i = 0; i < counter; i++){
    outFile << fixed << setprecision(1)<< current->getshape();//The first line sets
    //The percision of the outputting float values to one number past the decimal.
    outFile << ",";
    outFile << current->getsize();//The output is a value held by the node seperated by a comma.
    outFile << ",";
    outFile << current->getcolorb();
    outFile << ",";
    outFile << current->getcolorg();
    outFile << ",";
    outFile << current->getcolorr();
    outFile << ",";
    outFile << current->getposx();
    outFile << ",";
    outFile << current->getposy();
    outFile << ",";
    outFile << current->getrotx();
    outFile << ",";
    outFile << current->getroty();
    outFile << endl;
    current = current->getnext();//changes node to the next node to be saved
   }
   //Closes file and resets the node.
   outFile.close();
   current = holder;
}

//Load function
void load(){
    inFile.open("output.txt");
    if(!inFile){//This if else statement is ran the the boolean value !inFile which
            //Runs when the file that was opened does not exist. So in this case I
            //told the program to do nothing.

    }else{
        //deletes the nodes before new nodes are loaded in.
        while (current != NULL)
        {  //Goes through each of the nodes and deletes them
           holder = current->getnext();
           delete current;
           current = holder;
        }
        //Recreates a head node because the program is not closing
        head = new Node(NULL, NULL);
        current = head;
        holder = head;

        //The first thing this does is gets the first thing in the file and puts it in
        //the counter value so the program knows how many nodes to create.
        getline(inFile, shold);
        ss << shold;//Converts
        ss >> counter;
        ss.clear();//Clears the string stream so the next values are correct
        ss.str("");

        //This loop runs counter number of times which makes counter number of nodes.
        for(int b=0; b < counter; b++){
            getline(inFile, shold, ',');
            ss << shold;
            ss >> ihold;
            ss.clear();
            ss.str("");
            current->setshape(ihold);

            getline(inFile, shold, ',');
            ss << shold;
            ss >> fhold;
            ss.clear();
            ss.str("");
            current->setsize(fhold);

            getline(inFile, shold, ',');
            ss << shold;
            ss >> fhold;
            ss.clear();
            ss.str("");
            current->setcolorb(fhold);

            getline(inFile, shold, ',');
            ss << shold;
            ss >> fhold;
            ss.clear();
            ss.str("");
            current->setcolorg(fhold);

            getline(inFile, shold, ',');
            ss << shold;
            ss >> fhold;
            ss.clear();
            ss.str("");
            current->setcolorr(fhold);

            getline(inFile, shold, ',');
            ss << shold;
            ss >> fhold;
            ss.clear();
            ss.str("");
            current->setposx(fhold);

            getline(inFile, shold, ',');
            ss << shold;
            ss >> fhold;
            ss.clear();
            ss.str("");
            current->setposy(fhold);

            getline(inFile, shold, ',');
            ss << shold;
            ss >> fhold;
            ss.clear();
            ss.str("");
            current->setrotx(fhold);

            getline(inFile, shold);
            ss << shold;
            ss >> fhold;
            ss.clear();
            ss.str("");
            current->setroty(fhold);

            holder = current;
            current = new Node(holder, NULL);
            holder->setnext(current);
        }

        //Sets current to head so the program start there and closes the file.
        current = head;
        inFile.close();

    }

}
//This display function runs on the main loop constantly
void display(){
    //Makes the display use both the color and buffer
   glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);



   //These if statements check to see which of of the shapes is contained within the node
   if(current->getshape() == 1){
      //Code for putting the Sphere on the screen
      glPushMatrix();
        //The information of the shape comes directly from the node except for a few points
        glColor3f(current->getcolorr(), current->getcolorg(),current->getcolorb());
        glTranslated(current->getposx(),current->getposy(),-5.0);
        //All Shapes will start at the -5 z coordinate because of the way the projection is set up
        //Since it's between 1 and 10 z the camera is actually facing -z so I place all shapes in
        //The middle of the z axis.
        glRotated(current->getrotx(),1,0,0);//These are vectors in which the shape is rotated by
        //A certain degree specified by the first parameter so this dependent on the node.
        glRotated(current->getroty(),0,1,0);
        glutSolidSphere(current->getsize(),16,16);
      glPopMatrix();
   }
   //This makes a Cube
   else if(current->getshape() == 2){
      //Code that puts the cube on screen
      glPushMatrix();
        glColor3f(current->getcolorr(), current->getcolorg(),current->getcolorb());
        glTranslated(current->getposx(),current->getposy(),-5.0);
        glRotated(current->getrotx(),1,0,0);
        glRotated(current->getroty(),0,1,0);
        glutSolidCube(current->getsize());
      glPopMatrix();
   }
   //This makes the cone
   else if(current->getshape() == 3){
      glPushMatrix();
        glColor3f(current->getcolorr(), current->getcolorg(),current->getcolorb());
        glTranslated(current->getposx(),current->getposy(),-5.0);
        glRotated(current->getrotx(),1,0,0);
        glRotated(current->getroty(),0,1,0);
        glutSolidCone(current->getsize(),current->getsize(),16,16);
      glPopMatrix();
   }
   //The reason we swap buffers is because in my main enable double buffers
   //This is important because it allows us to make changes in a buffer
   //that is not being displayed currently
   //Then it swaps buffers every time the loop runs so there's always a buffer
   //You can work with
   glutSwapBuffers();
}

//This is a function that allows me to create a bunch of key bindings to blocks of code
void key(unsigned char key, int alpha, int beta)
{
    switch(key)
    {
       //key parameter holds the actual key pressed and it is assigned to the
       //Proper case statement
       case '1':
          if(current->getshape() == 0){//The next three lines assign a shape
            //By assigning a numerical value that is then later checked by the
            //display function. It will only work if there is no shape currently in the pane
             current->setshape(1);
          }
             break;//These break statements are REQUIRED to separate each of the case statements

       case '2':
          if(current->getshape() == 0){
             current->setshape(2);
          }
             break;

       case '3':
          if(current->getshape() == 0){
          current->setshape(3);
          }
          break;
       //case empties the shape and its properties
       case '0':
          current->setshape(0);
          current->setcolorb(1.0);
          current->setcolorg(0.0);
          current->setcolorr(0.0);
          current->setposx(0.0);
          current->setposy(0.0);
          current->setrotx(0.0);
          current->setroty(0.0);
          current->setsize(1.0);
       //The next four case statements deal with rotation and can be changed
       //by larger values than .1 since it deals with 360 degrees
       case 'a':
          current->setroty(current->getroty() + -5);
          break;
       case 'd':
          current->setroty(current->getroty() + 5);
          break;
       case 'w':
          current->setrotx(current->getrotx() - 5);
          break;
       case 's':
          current->setrotx(current->getrotx() + 5);
          break;
       //The next three change the color of the shape by basically turning off and on the
       //Three primary colors
       case 'g':
          if(current->getcolorg() == 1.0){
            current->setcolorg(0.0);
          }else if(current->getcolorg() == 0){
             current->setcolorg(1.0);
          }
          break;
       case 'r':
          if(current->getcolorr() == 1.0){
            current->setcolorr(0.0);
          }else if(current->getcolorr() == 0.0){
             current->setcolorr(1.0);
          }
          break;
       case 'b':
          if(current->getcolorb() == 1.0){
            current->setcolorb(0.0);
          }else if(current->getcolorb() == 0.0){
             current->setcolorb(1.0);
          }
          break;
       //The next four case statements change the position of the shape
       //The if statements prevent the shape from going out of the view of the
       //perspective
       case 'i':
          if(current->getposy() < 2.0){
            current->setposy(current->getposy() + 0.1);
          }
          break;
       case 'k':
          if(current->getposy() > -2.0){
            current->setposy(current->getposy() - 0.1);
          }
          break;
       case 'j':
          if(current->getposx() > -2.0){
            current->setposx(current->getposx() - 0.1);
          }
          break;
       case 'l':
          if(current->getposx() < 2.0){
            current->setposx(current->getposx() + 0.1);
          }
          break;
       //The next two case statements change the size of the shape in the window
       //I'm not too concerned with the entire shape going out of pane so I don't
       //Put too many restrictions on the size.
       case '-':
          if(current->getsize() > 0.1){
            current->setsize(current->getsize() - 0.1);
          }
          break;
       case '+':
          if(current->getsize() < 2.0){
            current->setsize(current->getsize() + 0.1);
          }
          break;
       //The next two case statements flip between nodes so this is where I create new nodes
       case 'n':
          if(current->getnext() == NULL){//Checks to see if it's at the tail
            holder = current;
            current = new Node(holder, NULL);
            holder->setnext(current);
            counter = counter + 1;

          }else{
             current = current->getnext();
          }
          break;
       case 'p':
          if(current->getprev()!= NULL){//Makes sure it's not at the head
            current = current->getprev();
          }
          break;
       //This case creates an animate function
       case 'm':
          current = head;
          //This function only loops through once because there's a lot of
          //problems that occur with having two potentially endless loops
          //running at the same time.
          while(current->getnext() != NULL){
            display();
            //I have imported the time library in order to put a delay
            //in the while loop that will allow the animation to be more smooth.
            Sleep(500);
            current = current->getnext();
            //Recalls the display function so the new shape is put in the window.
            display();
          }
          Sleep(500);
          current = head;
          break;
       //Save case
       case 'z':
          save();
          break;
       //Load case
       case 'x':
          load();
          display();
          break;

       //This case centers the position and resets the rotation of the shape
       case ' ':
          current->setrotx(0.0);
          current->setroty(0.0);
          current->setposx(0.0);
          current->setposy(0.0);
          break;

       //This is one of the most important key statements! this is the overridden exit
       //If q is called the exitcommand function is ran which removes the nodes from
       //The heap so the user should never exit without clicking q
       case 'q':
           exitcommand();
           break;

    }
    //This line basically runs the display function again to make sure each key input
          //Is registered immediately
    glutPostRedisplay();
}
//This entire function has two purposes
void reshape(int w, int h)
{
   //The glViewPort is what allows you to reshape the window and the shapes will
   //adjust accordingly!
   const float ar = (float)w / (float)h;
   glViewport(0,0,w,h);
   //This is the most abstract concept of the program
   //This sets up the projection view which is one of the big reasons the shapes
   //appear 3d. These lines put a view point that describes how the user sees
   //the window.
   glMatrixMode( GL_PROJECTION);
   glLoadIdentity();
   //This line has all the information to determine what your looking at
   //The perspective is 60 degrees which is about the same as a human
   //The demensions of the first plane is ar
   //the 1 and 10 deal with depth only things contained in -10 and -1 along
   //the z axis can be seen from the perspective
   gluPerspective(60, ar, 1.0, 10.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}
//This is the initialization of open Gl it comes with the background colors as well as
//What will be needed for this program. since it's 3d we use depth.
void initOpenGL()
{
   //Sets the background color but does not draw it
   glClearColor(0.0, 0.0, 0.0, 1.0);

   //Enagles the program to compare depth of objects
   glEnable(GL_DEPTH_TEST);
   glDepthFunc(GL_LEQUAL);//This describes what occurs when a test is called
   //(gl_lequal) demonstrates reality depth test. if it's closer it comes before.
}

//All of this is setting up a light. I'm not saying I copied these but they are
//basically the same as pretty much every program that is ran using 3d rendering.
//Each of these is not a light but a set of values or Matrices that set up
//a predeclared set of floats that will be used to describe a characteristic of a light
//Later in the program.
const GLfloat light_ambient[]  = { 0.0, 0.0, 0.0, 1.0 };
const GLfloat light_diffuse[]  = { 1.0, 1.0, 1.0, 1.0 };
const GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
const GLfloat light_position[] = { 2.0, 5.0, 5.0, 0.0 };

//This does the same thing as the lighting characteristics but it's for the actual material
const GLfloat mat_ambient[]    = { 0.7, 0.7, 0.7, 1.0 };
const GLfloat mat_diffuse[]    = { 0.8, 0.8, 0.8, 1.0 };
const GLfloat mat_specular[]   = { 1.0, 1.0, 1.0, 1.0 };
const GLfloat high_shininess[] = { 100.0 };

//Main function takes in variables that are passed to it from the OS
int main(int Argc, char **Argv )
{
   //Those variables are needed to be passed to the glutInit function.
   glutInit(&Argc, Argv);
   //Display depth rgba off the color system and double buffer
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
   //sets widow size and position.
   glutInitWindowSize(500,500);
   glutInitWindowPosition(100,100);
   //Names window
   glutCreateWindow("Shape Animation");

   initOpenGL();
   //Functions that are ran to start the window each of these are from the
   //glut library and construct the behavior of the window when certain actions happen
   glutDisplayFunc(display);
   glutKeyboardFunc(key);
   glutIdleFunc(display);
   glutReshapeFunc( reshape );


   //These lines operate the lights
   glEnable(GL_LIGHT0);
   //This line is confusing but it basically makes the calculations for the lights
   //Easier whenever the window is reshaped
   glEnable(GL_NORMALIZE);

   //These two lines enable the ability to manipulate the lighting on the shapes
   //and the lighting in general
   glEnable(GL_COLOR_MATERIAL);
   glEnable(GL_LIGHTING);

   //The front view of the lights basically combines all the other lights
   //I'm not a light expert so I'm not sure how these lights combined with each other
   //Actually works but these lights help make the actual 3d of each object pop
   glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
   glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
   glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
   //This sets the lights position
   glLightfv(GL_LIGHT0, GL_POSITION, light_position);

   //These are the same as the lighting except this actually talks about
   //The shape instead of a light.
   glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
   glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
   glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
   glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

   //This loop make the window run until the user exits. and constant calls on the idle
   //function which I just mapped to my display function so it just runs the display function
   glutMainLoop();

   return 0;//Returns 0 so the main is satisfied
}
