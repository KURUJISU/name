//
// ミニゲーム雛形
//

#include "appEnv.hpp"


// アプリのウインドウサイズ
enum Window {
	WIDTH = 900,
	HEIGHT = 900
};


// 
// メインプログラム

float ktn_angle = 0;
int K = 1;
int E = 0;

void dispPlayPoint(int play_point){
	float x = -Window::WIDTH / 2 + 50 + 10;
	float y = -Window::HEIGHT / 2 + 25 + 10;

	int ten_points = play_point / 10;
	while (ten_points > 0){
		drawFillCircle(x, y, 15, 15,
			20,
			Color(1, 0, 0));

		x += 15 * 2 + 5;
		ten_points -= 1;
	}

	int one_points = play_point % 10;
	while (one_points > 0){
		drawFillCircle(x, y, 10, 10,
			20,
			Color(1, 1, 0));

		x += 10 * 2 + 5;
		one_points -= 1;
	}
}

void on_emyA(int& G1, float& x, float& y, Vec2f& mouse_pos, float& A, bool& on_emy1, int& play_point){

	if (G1 == 1){
		if (mouse_pos.x() + 64 > x){
			if (mouse_pos.x() - 64 < (x + 64)){
				if (mouse_pos.y() + 64 > y){
					if (mouse_pos.y() - 64 < (y + 64)){
						if (A < 1){
							on_emy1 = false;
							play_point += 1;
							G1 = 0;
						}
					}
				}
			}
		}
	}

	if (G1 == 1){
		if (mouse_pos.x() - 64 > x){
			if (mouse_pos.x() + 64 < (x + 64)){
				if (mouse_pos.y() - 64 > y){
					if (mouse_pos.y() + 64 < (y + 64)){
						if (A < 1){
							on_emy1 = false;
							play_point += 1;
							G1 = 0;
						}
					}
				}
			}
		}

	}
}

void on_emy(int& r1, int& r, bool& on_emy1, float& x, float& y, int& vx, Texture& suriken_image){
	if (r1 == 1) r = 1;
	if (r == 1){
		if (on_emy1){
			drawTextureBox(x, y,
				64, 64,
				0, 0, 64, 64,
				suriken_image,
				Color(1, 1, 1));
			vx += 2;
			if (vx == 900){ vx = 0; }
		}
	}
}

void on_emyR(int& r1, int& r, bool& on_emy1, float& x, float& y, int& vx1, Texture& suriken_image){
	if (r1 == 1) r = 1;
	if (r == 1){
		if (on_emy1){
			drawTextureBox(x, y,
				64, 64,
				0, 0, 64, 64,
				suriken_image,
				Color(1, 1, 1));
			vx1 -= 2;
			if (vx1 == -900){ vx1 = 0; }
		}
	}
}

void on_emyRf(bool& on_emy1, int& i1, int& G1, int& vx1){
	if (on_emy1 == false){
		i1 < 11;
		i1++;
		if (i1 == 10){
			on_emy1 = true;
			G1 = 1;
			vx1 = 0;
			i1 = 0;
		}
	}
}
int main() {
	// アプリウインドウの準備
	AppEnv app_env(Window::WIDTH, Window::HEIGHT);



	while (1){

		int hi_score = 0;
		{
			std::ifstream fstr("score.txt");
			if (fstr)
			{
				fstr >> hi_score;
			}
		}
		Texture title_image("res/title.png");//サイズ512*256
		Texture pstart_image("res/push_start.png");//サイズ512*128
		Texture njp_image("res/NJ-P.png");//サイズ128*256
		Texture suriken_image("res/surikenn.png");//サイズ64*64
		Texture player_image("res/player.png");//サイズ16*16
		Texture ktn_image("res/katana.png");//サイズ64*128
		Texture setu_image("res/Setumei2.png");//サイズ1024*1024
		Texture gst_image("res/gstart.png");//サイズ512*128
		Texture lizlt_image("res/FOR_P.png");//サイズ1024*1024
		Texture titleback_image("res/titleback.png");//サイズ512*128
		Texture yasiki_image("res/yasiki.png");//サイズ512*256
		Texture gover_image("res/p.png");//サイズ900*900
		Texture setu2_image("res/setumei3.png");//サイズ900*900

		Media bg_music("res/bgmusic.wav");
		Media gstart_music("res/gamestart.wav");
		Media gclear_music("res/gameclear.wav");
		Media gover_music("res/gameover.wav");
		Media atk_music("res/atk.wav");

		float pstart_angle = 0.0;
		float gst_angle = 0.0;

		int play_time = 60 * 20;
		int play_point = 0;

		int i1 = 0;
		int i2 = 0;
		int i3 = 0;
		int i4 = 0;
		int i5 = 0;
		int i6 = 0;
		int i7 = 0;
		int i8 = 0;
		int i9 = 0;
		int i10 = 0;
		int i11 = 0;
		int i12 = 0;

		float random1 = 0;
		float random2 = 0;
		float random3 = 0;
		float random4 = 0;
		float random5 = 0;
		float random6 = 0;
		float random7 = 0;
		float random8 = 0;
		float random9 = 0;
		float random10 = 0;
		float random11 = 0;
		float random12 = 0;

		int G1 = 1;
		int G2 = 1;
		int G3 = 1;
		int G4 = 1;
		int G5 = 1;
		int G6 = 1;
		int G7 = 1;
		int G8 = 1;
		int G9 = 1;
		int G10 = 1;
		int G11 = 1;
		int G12 = 1;

		bool on_emy1 = true;
		bool on_emy2 = true;
		bool on_emy3 = true;
		bool on_emy4 = true;
		bool on_emy5 = true;
		bool on_emy6 = true;
		bool on_emy7 = true;
		bool on_emy8 = true;
		bool on_emy9 = true;
		bool on_emy10 = true;
		bool on_emy11 = true;
		bool on_emy12 = true;

		int vx1 = 0;
		int vx2 = 0;
		int vx3 = 0;
		int vx4 = 0;
		int vx5 = 0;
		int vx6 = 0;

		int vy1 = 0;
		int vy2 = 0;
		int vy3 = 0;
		int vy4 = 0;
		int vy5 = 0;
		int vy6 = 0;

		int x1 = 0;

		int x = 0;
		int y = 0;

		app_env.bgColor(Color(0.3, 0.3, 0.3));

		// メインループ

		float ktn_angle = 0;
		bool ktn = false;
		float A = 4;
		int r = 0;
		int r1 = 0;

		gstart_music.play();
		gstart_music.looping(true);
		gstart_music.gain(0.5);

		while (1) {

			int hi_score = 0;
			{
				std::ifstream fstr("score.txt");
				if (fstr)
				{
					fstr >> hi_score;
				}
			}

			{
				// ウィンドウが閉じられたらアプリを終了
				if (!app_env.isOpen()) return 0;

				// 描画準備
				app_env.setupDraw();

				dispPlayPoint(hi_score);

				if (app_env.isPushButton(Mouse::LEFT)) break;
				if (app_env.isPushButton(Mouse::RIGHT)) break;

				drawTextureBox(0 - 512 / 2, 0,
					512, 256,
					0, 0, 512, 256,
					title_image,
					Color(1, 1, 1));

				pstart_angle += 0.1;
				float pstart_color = (std::sin(pstart_angle));
				if (pstart_color > 0){
					pstart_color = 1;
				}

				std::cout << pstart_color << std::endl;

				drawTextureBox(0 - 512 / 2, -330,
					512, 128,
					0, 0, 512, 128,
					pstart_image,
					Color(pstart_color, pstart_color, pstart_color));
				// ここにゲームの処理を書く
				// 
				K = 1;
				// 画面を更新
				app_env.update();
			}

			app_env.flushInput();
		}

		while (1){

			// ウィンドウが閉じられたらアプリを終了
			if (!app_env.isOpen()) return 0;

			// 描画準備
			app_env.setupDraw();

			drawTextureBox(-1000 / 2, -900 / 2 + 10,
				1024, 1024,
				0, 0,
				1000, 900,
				setu_image,
				Color(1, 1, 1));

			if (app_env.isPushKey(GLFW_KEY_ENTER)){
				gstart_music.looping(false);
				gstart_music.stop();
				break;
			}

			gst_angle += 0.1;
			float gst_color = (std::sin(gst_angle));
			if (gst_color > 0){
				gst_color = 1;
			}

			drawTextureBox(0 - 512 / 2, -900 / 2 - 5 + 10,
				512, 128,
				0, 0, 512, 128,
				gst_image,
				Color(gst_color, gst_color, gst_color));

			app_env.update();
		}

		app_env.flushInput();
/*		while (1){

			// ウィンドウが閉じられたらアプリを終了
			if (!app_env.isOpen()) return 0;

			// 描画準備
			app_env.setupDraw();

			drawTextureBox(-900 / 2, -900 / 2,
				1024, 1024,
				0, 0, 900, 900,
				setu2_image,
				Color(1, 1, 1));

			if (app_env.isPushKey(GLFW_KEY_ENTER)){
				gstart_music.looping(false);
				gstart_music.stop();
				break;
			}
			app_env.update();
		}
		app_env.flushInput();
*/

		bg_music.play();
		bg_music.looping(true);
		bg_music.gain(0.1);

		while (1){
			{
				if (!app_env.isOpen()) return 0;

				app_env.setupDraw();


				float angle = 0;
				angle = angle + 0.1;
				Vec2f mouse_pos = app_env.mousePosition();

				drawFillCircle(mouse_pos.x(), mouse_pos.y(),
					8, 8,
					100,
					Color(1, 0, 0));

				ktn_angle -= 0.49;

				if (app_env.isPushButton(Mouse::LEFT)){
					ktn = true;
				}
			   
				if (ktn == true){
					atk_music.play();
					atk_music.gain(0.2);

					drawTextureBox(mouse_pos.x(), mouse_pos.y(),
						64, 128,
						0, 0, 64, 128,
						ktn_image,
						Color(1, 1, 1),
						M_PI*ktn_angle,
						Vec2f(1, 1),
						Vec2f(1, 1));
					A -= 1;
					if (A < 0){
						ktn = false;
						A = 4;
					}
				}

				drawTextureBox(-900 / 2 + 30, -900 / 2,
					128, 256,
					0, 0, 128, 256,
					njp_image,
					Color(1, 1, 1));

				time_t date;
				srand(time(&date));
				r1 = rand() % 4;
				random1 = rand() % 450 * -1;
				random2 = rand() % 450;
//				random3 = rand() % 450 * -1;
				random4 = rand() % 450 * -1;
				random5 = rand() % 450;
//				random6 = rand() % 450 * -1;
				random7 = rand() % 450 * -1;
				random8 = rand() % 450;
//				random9 = rand() % 450 * -1;
				random10 = rand() % 450 * -1;
				random11 = rand() % 450;
//				random12 = rand() % 450 * -1;

				float x1 = -450 + vx1;
				float x2 = -450 + vx2;
//				float x3 = -450 + vx3;
				float x4 = 450 + vx4;
				float x5 = 450 + vx5;
//				float x6 = 450 + vx6;
				float y7 = -450 + vy1;
				float y8 = -450 + vy2;
//				float y9 = -450 + vy3;
				float y10 = 450 + vy4;
				float y11 = 450 + vy5;
//				float y12 = 450 + vy6;

				float y1 = random1;
				float y2 = random2;
//				float y3 = random3;
				float y4 = random4;
				float y5 = random5;
//				float y6 = random6;
				float x7 = random7;
				float x8 = random8;
//				float x9 = random9;
				float x10 = random10;
				float x11 = random11;
//				float x12 = random12;

				on_emyA(G1, x1, y1, mouse_pos, A, on_emy1, play_point);
				on_emy(r1, r, on_emy1, x1, random1, vx1, suriken_image);
				on_emyRf(on_emy1, i1, G1, vx1);

				on_emyA(G2, x2, y2, mouse_pos, A, on_emy2, play_point);
				on_emy(r1, r, on_emy2, x2, random2, vx2, suriken_image);
				on_emyRf(on_emy2, i2, G2, vx2);

/*				on_emyA(G3, x3, y3, mouse_pos, A, on_emy3, play_point);
				on_emy(r1, r, on_emy3, x3, random3, vx3, suriken_image);
				on_emyRf(on_emy3, i3, G3, vx3);
*/
				on_emyA(G4, x4, y4, mouse_pos, A, on_emy4, play_point);
				on_emyR(r1, r, on_emy4, x4, random4, vx4, suriken_image);
				on_emyRf(on_emy4, i4, G4, vx4);

				on_emyA(G5, x5, y5, mouse_pos, A, on_emy5, play_point);
				on_emyR(r1, r, on_emy5, x5, random5, vx5, suriken_image);
				on_emyRf(on_emy5, i5, G5, vx5);

/*				on_emyA(G6, x6, y6, mouse_pos, A, on_emy6, play_point);
				on_emyR(r1, r, on_emy6, x6, random6, vx6, suriken_image);
				on_emyRf(on_emy6, i6, G6, vx6);
*/
				on_emyA(G7, x7, y7, mouse_pos, A, on_emy7, play_point);
				on_emy(r1, r, on_emy7, random7, y7, vy1, suriken_image);
				on_emyRf(on_emy7, i7, G7, vy1);

				on_emyA(G8, x8, y8, mouse_pos, A, on_emy8, play_point);
				on_emy(r1, r, on_emy8, random8, y8, vy2, suriken_image);
				on_emyRf(on_emy8, i8, G8, vy2);

/*				on_emyA(G9, x9, y9, mouse_pos, A, on_emy9, play_point);
				on_emy(r1, r, on_emy9, random9, y9, vy3, suriken_image);
				on_emyRf(on_emy9, i9, G9, vy3);
*/
				on_emyA(G10, x10, y10, mouse_pos, A, on_emy10, play_point);
				on_emyR(r1, r, on_emy10, random10, y10, vy4, suriken_image);
				on_emyRf(on_emy10, i10, G10, vy4);

				on_emyA(G11, x11, y11, mouse_pos, A, on_emy11, play_point);
				on_emyR(r1, r, on_emy11, random11, y11, vy5, suriken_image);
				on_emyRf(on_emy11, i11, G11, vy5);

/*				on_emyA(G12, x12, y12, mouse_pos, A, on_emy12, play_point);
				on_emyR(r1, r, on_emy12, random12, y12, vy6, suriken_image);
				on_emyRf(on_emy12, i12, G12, vy6);
*/
/*      		if (K == 1){
					drawTextureBox(-512 / 2 + 80, -100,
						512, 256,
						0, 0, 512, 256,
						yasiki_image,
						Color(1, 1, 1));
				}

				if (K == 1){
					if (vx1 >= 350 || vx2 >= 350 || vx3 >= 350 || vx4 <= -390 || vx5 <= -390 || vx6 <= -390) {
						if (random1 <= 80 && random1 >= -80 || random2 <= 100 && random2 >= -100 || random3 <= 100 && random3 >= -100 || random4 <= 100 && random4 >= -100 || random5 <= 100 && random5 >= -100 || random6 <= 100 && random6 >= -100){
							K = 0;
							E = 1;
							bg_music.looping(false);
							break;
						}
					}
				}

				if (K == 1){
					if (vy1 >= 350 || vy2 >= 350 || vy3 >= 350 || vy4 <= -460 || vy5 <= -460 || vy6 <= -460) {
						if (random7 <= 256 && random7 >= -256 || random8 <= 256 && random8 >= -256 || random9 <= 256 && random9 >= -256 || random10 <= 256 && random10 >= -256 || random11 <= 256 && random11 >= -256 || random12 <= 256 && random12 >= -256){
							K = 0;
							E = 1;
							bg_music.looping(false);
							break;
						}
					}
				}
*/
				// ここにゲームの処理を書く

				{
					dispPlayPoint(play_point);

					{
						float x = -900 / 2;
						float y = -900 / 2;

						float width = 30;
						float height = (play_time * 250) / (60 * 20);

						drawFillBox(x, y,
							width, height,
							Color(1, 1, 0));
						drawBox(x, y,
							width, 250, 2,
							Color(1, 1, 1));

					}

					play_time -= 1;

					if (play_time == 0) break;

					if (play_point > hi_score){
						std::ofstream fstr("score.txt");
						if (fstr){
							fstr << play_point << std::endl;
						}

					}

				}

				app_env.update();
			}
			app_env.flushInput();

		}
		int M = 1;
		while (1){

			if (!app_env.isOpen()) return 0;

			app_env.setupDraw();
			
			if (E == 1){

					bg_music.stop();

					drawTextureBox(-450, -450,
						1024, 1024,
						0, 0, 900, 900,
						gover_image,
						Color(1, 1, 1));

					if (M == 1){
						gover_music.play();
						gover_music.gain(0.5);
						M = 0;
					}

					if (app_env.isPressKey(GLFW_KEY_ENTER)){
						gover_music.looping(false);
						gover_music.stop();
						break;
					}
				}

				if (E == 0){
					bg_music.stop();

					drawTextureBox(-900 / 2, -900 / 2-100,
						1024, 1024,
						0, 0,
						900, 900,
						lizlt_image,
						Color(1, 1, 1));

					drawTextureBox(-512 / 2, -330,
						512, 128,
						0, 0, 512, 128,
						titleback_image,
						Color(1, 1, 1));

					dispPlayPoint(play_point);

					if (M == 1){
						gclear_music.play();
						gclear_music.looping(true);
						gclear_music.gain(0.5);
						M = 0;
					}

					if (app_env.isPressKey(GLFW_KEY_ENTER)){
						gclear_music.looping(false);
						gclear_music.stop();
						break;
					}
				}

				app_env.update();
			}

			app_env.flushInput();

		}

		// アプリ終了
	}
