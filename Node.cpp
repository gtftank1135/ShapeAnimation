#include "Node.h"

using namespace std;

Node::Node()
{

}

Node::Node(Node* pre, Node* nex)
{
    prev = pre;
    next = nex;
}

float Node::getcolorb()
{
    return colorb;
}

float Node::getcolorg()
{
    return colorg;

}

float Node::getcolorr()
{
    return colorr;
}

float Node::getposx()
{
    return posx;
}

float Node::getposy()
{
    return posy;
}

float Node::getrotx()
{
    return rotx;
}
float Node::getroty()
{
    return roty;
}

Node* Node::getnext()
{
    return next;
}

Node* Node::getprev()
{
    return prev;

}

int Node::getshape()
{
    return shape;
}

float Node::getsize()
{
    return size;

}

void Node::setsize(float siz)
{
    size = siz;
}

void Node::setshape(int sha)
{
    shape = sha;
}

void Node::setcolorb(float cob)
{
    colorb = cob;
}

void Node::setcolorg(float cog)
{
    colorg = cog;
}

void Node::setcolorr(float cor)
{
    colorr = cor;
}

void Node::setposx(float pox)
{
    posx = pox;
}

void Node::setposy(float poy)
{
    posy = poy;
}

void Node::setrotx(float rox)
{
    rotx = rox;
}

void Node::setroty(float roy)
{
    roty = roy;
}

void Node::setprev(Node* pre)
{
    prev = pre;
}

void Node::setnext(Node* nex)
{
    next = nex;
}
Node::~Node()
{
    //dtor
}
