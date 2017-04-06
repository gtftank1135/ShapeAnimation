#ifndef NODE_H
#define NODE_H
#include <iostream>

class Node
{
    public:
        Node();
        Node(Node* prev, Node* next);
        virtual ~Node();
        int getshape();
        float getsize();
        float getcolorb();
        float getcolorr();
        float getcolorg();
        float getposx();
        float getposy();
        float getrotx();
        float getroty();
        Node* getprev();
        Node* getnext();
        void setshape(int sha);
        void setsize(float siz);
        void setcolorb(float colb);
        void setcolorr(float colr);
        void setcolorg(float colg);
        void setposx(float pox);
        void setposy(float poy);
        void setrotx(float rox);
        void setroty(float roy);
        void setprev(Node* Prev);
        void setnext(Node* next);
    private:
        int shape = 0;
        float size = 1;
        float colorb = 1.0;
        float colorr = 0.0;
        float colorg = 0.0;
        float posx = 0.0;
        float posy = 0.0;
        float rotx = 0.0;
        float roty = 0.0;
        Node* prev;
        Node* next;
};

#endif // NODE_H
