#include "GameEngine.h"

int main(int argc, char* argv[])
{
	//Create game window size 800 x 600
	GameEngine* game = new GameEngine("First game made with CoreSDL2GameEngine", 800, 600);

	//Create scene
	Scene* scene = new Scene();

	//Set background color 0 - 255 (red, green, blue) :: Default color is black (0, 0, 0)
	scene->SetBackgroundColor(Color(0, 20, 40));

	//Set game scene
	game->SetScene(scene);

	//Create first Text
	Text* title_txt = new Text("First game made with CoreSDL2GameEngine");
	title_txt->SetPosition(260, 50);
	title_txt->SetColor(COLOR_WHITE);

	//Add text to scene game
	scene->AddText(title_txt);

	//Load texture
	Texture* logo_texture = new Texture("images/logo.png");

	//Create sprite from Texture
	Sprite* logo = new Sprite(logo_texture);
	Sprite* logo2 = new Sprite(logo_texture);
	Sprite* logo3 = new Sprite(logo_texture);

	//Set Sprite size, position, pivot and rotation
	logo2->SetSize(150, -150);
	logo2->SetPosition(350, 300);
	logo3->SetPivot(50, 50);
	logo3->SetSize(80, 80);
	logo3->SetPosition(350, 400);
	logo3->SetRotation(45);

	//Add sprite to scene game
	scene->AddChild(logo);
	scene->AddChild(logo2);
	scene->AddChild(logo3);

	//Create Text
	Text* show_txt = new Text("แสดงข้อความแบบ UTF-8");
	show_txt->SetFont("fonts/courmon.ttf");
	show_txt->SetSize(50);
	show_txt->SetPosition(100, 500);
	show_txt->SetColor(Color(255, 100, 100));

	//Add text to scene game
	scene->AddText(show_txt);

	//Run game
	game->Run();

	//Delete all
	delete logo_texture;
	delete logo;
	delete logo2;
	delete logo3;
	delete title_txt;
	delete show_txt;
	delete scene;
	delete game;

	return 0;
}
