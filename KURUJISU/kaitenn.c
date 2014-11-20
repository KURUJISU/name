void setup(){
 size(400,400,P3D); 
}

float r=0;

void draw(){
  background(100);
  translate(width/2,height/2);
  rotateX(0.5);
  //rotateY(0.5);
  r+=0.01;
  beginShape(TRIANGLE);
  for(float theta=0+r;theta<2*PI+r;theta+=PI/8){
    vertex(100*cos(theta),100*sin(theta),0);
    vertex(100*cos(theta+PI/8),100*sin(theta+PI/8),0);
    vertex(100*cos(theta+PI/8),100*sin(theta+PI/8),-200);
    vertex(100*cos(theta+PI/8),100*sin(theta+PI/8),0);
    vertex(100*cos(theta+PI/8),100*sin(theta+PI/8),-200);
    vertex(100*cos(theta+PI/8+PI/8),100*sin(theta+PI/8+PI/8),-200);
  }
  endShape();
}