float cx,cy,r;
float A=0;
float B=0;

void setup(){
 size(400,400);
 cx=width/2;
 cy=height/2;
 r=100;
}

void mousePressed(){
  float px=mouseX;
  float py=mouseY;
  float dx=cx-px;
  float dy=cy-py;
  if(dx*dx + dy*dy < r*r){
   A=1;
   println("B");
  }
}

void mouseDragged(){
  if(A==1){
 cx=mouseX;
 cy=mouseY;
 B=1;
  }
}

void mouseReleased(){
  if(B==1){
 cx=mouseX;
 cy=mouseY;
 A=0;
 B=0;
  }
}

void draw(){
 background(255);
 ellipse(cx,cy,2*r,2*r);
}


