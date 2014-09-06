float cx,cy,r;
float move_x=0;
boolean atack_counter=false;
float i=0;
float vy=0;
float e_count=0;
float x_count=0;
boolean atack=false;
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
 float EX=x_count%3;
 float EY=0+vy;
 if(EX==1){
   EX=150;
 }
 if(EX==0){
   EX=350;
 }
 fill(0,255,255);
 if(enemy){
  rect(EX,EY,100,100);
  vy += 2;
  if(EY>=500){
    vy=0;
   }
  }
  if(atack){
   if(EX<=250+move_x-5){
    if(EX+100>=250+move_x-5){
     if(EY>=LY-100){
       i=0;
       vy=0;
       atack=false;
       enemy=false;
     }
    }
   }
  }
  if(enemy==false){
    x_count += 2;
    e_count +=1;
  }
  if(e_count>=10){
    enemy=true;
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
  fill(0,255,0);
  rect(250+move_x-5,LY,10,35);
  i -= 7;
 }
 if(LY<=0){
   println('a');
   atack=false;
   i=0;
 }
}
