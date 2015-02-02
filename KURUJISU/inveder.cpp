PImage enemy;
PImage enemy2;

int y_chenge = 1;
int i = 0;

int Box_x = 200;
int Box_y = 0;
int Box_w = 50;
int Box_h = 50;

int fream_count = 0;
float chenge_image = 0;

float vx = 0;
float vy = 0;

void setup(){
 size(500,500); 
}

void draw(){
 background(0);
 enemy = loadImage("enemy.png");
 enemy2 = loadImage("enemy2.png");
 
 fream_count++;
 if(fream_count >= 90){
   fream_count = 0;
   chenge_image++;
 }
 
 for(i=0;i<5;i++){
   if(chenge_image % 2 == 0){
     image(enemy,Box_x + vx + i*50,Box_y + vy,Box_w,Box_h);
   }
   if(chenge_image % 2 == 1){
     image(enemy2,Box_x + vx + i*50,Box_y + vy,Box_w,Box_h);
   }
 }
 
 vx += y_chenge;
 if(Box_x + vx + Box_w + 200 >= 500){
   y_chenge = -1;
   vy += Box_h;
 }
 if(Box_x + vx <= 0){
  y_chenge = 1;
  vy += Box_h;
 }
 if(Box_y + vy >= 500){
   vy = 0;
 }
} 