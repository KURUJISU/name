float cx,cy,r;
float move_x=0;
float atack_counter=0;
float i=0;
float vy=0;
boolean atack=false;
boolean atack1=false;
boolean enemy=true;

void setup(){
 size(500,500);
 cx=250+move_x;
 cy=480;
 r=10;
}

void draw(){
 background(255);
 float LY=480-40+i;
 float EX=width/2-40;
 float EY=10+vy;
 fill(0,255,255);
 if(enemy){
  rect(EX,EY,100,100);
  vy += 2;
 }
 if(atack1){
 if(EX<=250+move_x-5){
   if(EX+100>=250+move_x-5){
     if(EY>=LY-100){
       enemy=false;
     }
   }
 }
 }
 if(keyPressed){
  if(key=='a'||key=='A'){
   move_x -= 3;
  }
  if(key=='d'||key=='D'){
   move_x += 3;
  }
 }
 fill(255,0,0);
 ellipse(250+move_x,480,20,20);
 
 if(keyPressed){
  if(key=='k'||key=='K'){
   atack=true;
  }
 }
 if(atack){
  atack1=true;
 }
 if(atack1){
  i -= 6;
  fill(0,255,0);
  rect(250+move_x-5,LY,10,30);
 }
}