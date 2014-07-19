float cx,cy,r;
float SwitchA=0;
float SwitchB = 0;

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
	  SwitchA = 1;
   println("B");
  }
}

void mouseDragged(){
	if (SwitchA == 1){
 cx=mouseX;
 cy=mouseY;
 SwitchB = 1;
  }
}

void mouseReleased(){
	if (SwitchB == 1){
 cx=mouseX;
 cy=mouseY;
 SwitchA = 0;
 SwitchB = 0;
  }
}

void draw(){
 background(255);
 ellipse(cx,cy,2*r,2*r);
}


