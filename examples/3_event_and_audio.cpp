#include <cmath>
#include "GameEngine.h"

//Create Game class
class Game : public GameEngine
{
public:
	Game(const char* title);
	~Game();
	//Keyboard Event function
	void KeyboardEvent(int key_event, int key_code);
	//Mouse Event function
	void MouseEvent(int mouse_event);
private:
	//Fucntion Start is first function after run game
	void Start();
	//Function Update is realtime working
	void Update();
	//Clean all after end game
	void Clean();
	//Define Scene class
	Scene* scene;
	Text* howto_txt;
	Text* mousepos_txt;
	//Define Texture and Sprite
	Texture* logo_tex;
	Sprite* logo;
	int targetX, targetY;
	//Define Audio for background music
	AudioMusic* bgAudio;
	//Define Audio track
	AudioTrack* hit;
	AudioTrack* hit2;
};

//Create Game : GameEngine
Game::Game(const char* title) : GameEngine(title, 800, 600){}
Game::~Game(){Clean();}

//Keyboard Event function
void Game::KeyboardEvent(int key_event, int key_code)
{
	if(key_event == KEYDOWN)
	{
		if(key_code == KEY_SPACE)
		{
			hit2->Play();
			//hit->Play( **LOOP ROUND** );
		}
	}
}

//Mouse Event function
void Game::MouseEvent(int mouse_event)
{
	//Click to target image
	if(mouse_event == MOUSE_BUTTONDOWN)
	{
		targetX = Mouse::mouseX;
		targetY = Mouse::mouseY;
		hit->Play();
	}
}

void Game::Start()
{
	//Create scene and SetScene
	scene = new Scene();
	SetScene(scene);

	//Create How to Text
	howto_txt = new Text("Press SPACE to play hit audio, Mouse click to move image");
	howto_txt->SetAlign(TEXT_ALIGN_MIDDLE);
	howto_txt->SetPosition(GameEngine::ScreenWidth/2, 10);
	howto_txt->SetColor(COLOR_WHITE);
	scene->AddText(howto_txt);

	//Create Mouse position Text
	mousepos_txt = new Text("mouse X: 0, mouse Y: 0");
	mousepos_txt->SetAlign(TEXT_ALIGN_MIDDLE);
	mousepos_txt->SetPosition(GameEngine::ScreenWidth/2, 50);
	mousepos_txt->SetColor(COLOR_RED);
	scene->AddText(mousepos_txt);

	//Loader Texture and Create Sprite
	logo_tex = new Texture("images/logo.png");
	logo = new Sprite(logo_tex);
	logo->SetSize(50, 50);
	//Set pivot to center image
	logo->SetPivot(25, 25);
	logo->SetPosition(GameEngine::ScreenWidth/2, GameEngine::ScreenHeight/2);
	scene->AddChild(logo);
	//Target position image
	targetX = GameEngine::ScreenWidth/2;
	targetY = GameEngine::ScreenHeight/2;

	//Load Audio Music
	bgAudio = new AudioMusic("audios/Music.mp3");
	//Set volume 30 (0 - 128)
	AudioMusic::SetVolume(30);
	//Play music
	bgAudio->Play();
	//bgAudio->Pause();
	//bgAudio->Stop();
	
	hit = new AudioTrack("audios/Hit.wav");
	//hit->SetVolume(AUDIO_MAX_VOLUME); //MAX 128
	hit2 = new AudioTrack("audios/Hit2.wav");
}

//Function Update is realtime working
void Game::Update()
{
	//Text show mouse position
	std::string m_pos = "mouse X: " + std::to_string(Mouse::mouseX) + ", mouse Y: " + std::to_string(Mouse::mouseY);
	mousepos_txt->SetText(m_pos);

	//Image move to Target
	int newX = (abs(targetX - logo->GetX()) > 5)?(logo->GetX() > targetX)?logo->GetX()-5:(logo->GetX() < targetX)?logo->GetX()+5:logo->GetX():targetX;
	int newY = (abs(targetY - logo->GetY()) > 5)?(logo->GetY() > targetY)?logo->GetY()-5:(logo->GetY() < targetY)?logo->GetY()+5:logo->GetY():targetY;
	logo->SetPosition(newX, newY);
}

//Clean all after end game
void Game::Clean()
{
	delete bgAudio;
	delete hit;
	delete hit2;
	delete howto_txt;
	delete mousepos_txt;
	delete logo;
	delete logo_tex;
	delete scene;
}

int main(int argc, char* argv[])
{
	//Create Game
	Game* game = new Game("Event and Audio");

	//Run Game
	game->Run();

	//Delete Game class
	delete game;

	return 0;
}
