#include "MainMenu.h"
#include "Path.h"
#include "Player.h"

namespace game
{

	MainMenu::MainMenu()
	{
	}

	void MainMenu::FirstMenu(const GlobalAssets& g)
	{

		Sprite *createButton = DrawManager->AddSprite(Path::From(L"menu", L"Create.png").c_str());
		createButton->SetPixelScale(Size(150, 100));
		createButton->SetPositionX(-10);
		createButton->SetPickable(true);

		Sprite *optionsButton = DrawManager->AddSprite(Path::From(L"menu", L"Options.png").c_str());
		optionsButton->SetPixelScale(Size(150, 100));
		optionsButton->SetPositionX(0);
		optionsButton->SetPickable(true);

		Sprite *exitButton = DrawManager->AddSprite(Path::From(L"menu", L"Exit.png").c_str());
		exitButton->SetPixelScale(Size(150, 100));
		exitButton->SetPositionX(10);
		exitButton->SetPickable(true);

		Sprite *background = DrawManager->AddSprite(Path::From(L"menu", L"mainMenuBackGround.png").c_str());
		background->SetPositionZ(0.001f);
		background->SetPixelPerfectScale();

		EventManager->AddEvent([=]
		{
			if (InputManager->IsKeyPressed(Keys::MouseLeft))
			{
					//printf("Got here\n");
				    //Need to look at isKeyReleased
					if (optionsButton->IsUnderCursor())
					{
						printf("Options\n");
						return 0;
					}

			
					if (exitButton->IsUnderCursor())
					{
						Core->Exit();
					}

					if (createButton->IsUnderCursor())
					{

						/*createButton->Destroy();
						optionsButton->Destroy();
						exitButton->Destroy();
						background->Destroy();*/
						CharacterCreationMenu(g);
						return 0;
					}
			}
			
			return 1;

		},L"akdasjkdlaj",0,0,0
		);
		
	}

	void MainMenu::CharacterCreationMenu(const GlobalAssets & g)
	{
		Sprite* nameTextBox = DrawManager->AddSprite(Path::From(L"menu", L"NameTextBox.png").c_str());
		nameTextBox->SetPixelPerfectScale();
		nameTextBox->SetPositionX(-11);
		nameTextBox->SetPositionY(5);

		BitmapText* textBox = DrawManager->AddBitmapText(g.font);
		textBox->SetMetrics(g.fm);
		textBox->SetColor(Color(0, 0, 1, 1));
		textBox->SetPosition(-12.6f, 4.6f, -0.001f);
		textBox->SetPixelPerfectScale();
		textBox->SetText(L"Charname");

		Event* e1 = EventManager->AddEvent([=]
		{
			static wstring typing = L"";

			int typedChar = InputManager->GetChar();
			if (typedChar != 0 && typedChar != L'\b')
				typing += typedChar;
			else if (typedChar == L'\b' && typing.length() > 0)
				typing.erase(typing.end() - 1);
			textBox->SetText(typing);
			return 1;
		}, L"typing", 0, 0, 0);

		Sprite *elfButton = DrawManager->AddSprite(Path::From(L"menu", L"elfButton.png").c_str());
		elfButton->SetPixelScale(Size(150, 100));
		elfButton->SetPositionX(-10);
		elfButton->SetPickable(true);

		Sprite *knightButton = DrawManager->AddSprite(Path::From(L"menu", L"knightButton.png").c_str());
		knightButton->SetPixelScale(Size(150, 100));
		knightButton->SetPositionX(0);
		knightButton->SetPickable(true);

		Sprite *wizardButton = DrawManager->AddSprite(Path::From(L"menu", L"wizardButton.png").c_str());
		wizardButton->SetPixelScale(Size(150, 100));
		wizardButton->SetPositionX(10);
		wizardButton->SetPickable(true);

		Sprite *createButton = DrawManager->AddSprite(Path::From(L"menu", L"createCharButton.png").c_str());
		createButton->SetPixelScale(Size(150, 100));
		createButton->SetPositionX(-7);
		createButton->SetPickable(true);
		createButton->SetPositionY(-7);

		Sprite *cancelButton = DrawManager->AddSprite(Path::From(L"menu", L"cancelButton.png").c_str());
		cancelButton->SetPixelScale(Size(150, 100));
		cancelButton->SetPositionX(7);
		cancelButton->SetPickable(true);
		cancelButton->SetPositionY(-7);
	

	}

	

	MainMenu::~MainMenu()
	{
	}
	
}