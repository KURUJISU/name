//
// �~�j�Q�[�����`
//

#include "appEnv.hpp"
#include <math.h>

// �A�v���̃E�C���h�E�T�C�Y
enum Window {
	WIDTH = 1000,
	HEIGHT = 900
};


// 
// ���C���v���O����
// 
int main() {
	// �A�v���E�C���h�E�̏���
	AppEnv app_env(Window::WIDTH, Window::HEIGHT);

	{
		Texture title_image("res/title.png");//�T�C�Y512*256
		Texture pstart_image("res/push_start.png");//�T�C�Y512*128
		Texture njp_image("res/NJ-P.png");//�T�C�Y128*256
		Texture suriken_image("res/surikenn.png");//�T�C�Y64*64
		Texture player_image("res/player.png");//�T�C�Y16*16
		Texture ktn_image("res/katana.png");//�T�C�Y64*128
		Texture setu_image("res/Setumei2.png");//�T�C�Y1024*1024
		Texture gst_image("res/gstart.png");//�T�C�Y512*128

		float pstart_angle = 0.0;
		float gst_angle = 0.0;

		int play_time = 60 * 20;
		int play_point = 0;

		int random1 = 0;
		int random2 = 0;

		app_env.bgColor(Color(0.3, 0.3, 0.3));


		// ���C�����[�v
		bool on_emy = true;
		while (1) {
			// �E�B���h�E������ꂽ��A�v�����I��
			if (!app_env.isOpen()) return 0;

			// �`�揀��
			app_env.setupDraw();

			//

			float angle = 0;
			angle = angle + 0.1;
			Vec2f mouse_pos = app_env.mousePosition();

			drawFillCircle(mouse_pos.x(), mouse_pos.y(),
				8, 8,
				100,
				Color(1, 0, 0));

			float ktn_angle = 0;
			float i = 0;
			for (i = 0; i <= 150; i++){
				if (app_env.isPushButton(Mouse::LEFT)){
					ktn_angle += 0.1;
					drawTextureBox(mouse_pos.x(), mouse_pos.y(),
						64, 128,
						0, 0, 64, 128,
						ktn_image,
						Color(1, 1, 1),
						ktn_angle,
						Vec2f(1, 1),
						Vec2f(1, 1));
				}
			}

			drawTextureBox(-1000 / 2 + 30, -900 / 2,
				128, 256,
				0, 0, 128, 256,
				njp_image,
				Color(1, 1, 1));

			{
				float x = -1000 / 2;
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

			float x = -64/2;
			float y = -64/2;


			if (mouse_pos.x() > x){
				if (mouse_pos.x()  < (x + 32)){
					if (mouse_pos.y()  > y){
						if (mouse_pos.y()  < (y + 32)){
							if (ktn_angle > 0.1){
								on_emy = false;
							}
						}
					}
				}
			}
			if (on_emy){
				drawTextureBox(-64 / 2, -64 / 2,
					64, 64,
					0, 0, 64, 64,
					suriken_image,
					Color(1, 1, 1));
			}
			// �����ɃQ�[���̏���������


			// 
			if (on_emy){}
			// ��ʂ��X�V
			app_env.update();
		}

		// �A�v���I��
	}
}