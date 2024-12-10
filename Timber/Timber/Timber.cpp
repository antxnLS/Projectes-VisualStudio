// Include important C++ libraries here
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

// Make code easier to type with "using namespace"
using namespace sf;
using namespace std;

// Function declaration //CANVIAR NOMS SPRITES

// Const declaration
const int Xmax = 1920;
const int Ymax = 1080;
const int NumMaxClouds = 10;
const int NumMaxBees = 10;

// Create a structure variable called Mycloud
struct CloudStructure {
	sf::Sprite dibuix;
	bool  Active;
	float Speed;
};

struct BeeStructure {
	sf::Sprite dibuix;
	bool  Active;
	float Speed;
};

const int NUM_BRANCHES = 6;
// Where is the player/branch? 
// Left or Right
enum class side { LEFT, RIGHT, NONE };
void updateBranches(int seed, side branca[]);

// Line the axe up with the tree – Cal posar-ho fora de la funció main
const float AXE_POSITION_LEFT = 700;
const float AXE_POSITION_RIGHT = 1075;



int main()
{
	int frameCount = 0;  // Comptador de fotogrames
	float elapsedTime = 0.0f;  // Temps acumulat per actualitzar el FPS
	Text fpsText;  // Text per mostrar el FPS

	Sprite branches[NUM_BRANCHES];
	side branchPositions[NUM_BRANCHES];
	// Create a video mode object
	VideoMode vm(Xmax, Ymax);

	// Create and open a window for the game
	RenderWindow window(vm, "Timber!!!", Style::Fullscreen);
	window.setFramerateLimit(60);

	// Create a texture to hold a graphic on the GPU
	Texture textureBackground;

	// Load a graphic into the texture
	textureBackground.loadFromFile("graphics/background.png");

	// Create a sprite
	Sprite spriteBackground;

	// Attach the texture to the sprite
	spriteBackground.setTexture(textureBackground);

	// Set the spriteBackground to cover the screen
	spriteBackground.setPosition(0, 0);

	// Make a tree sprite
	Texture textureTree;
	textureTree.loadFromFile("graphics/tree.png");
	Sprite spriteTree;
	spriteTree.setTexture(textureTree);
	spriteTree.setPosition(810, 0);

	//Multiple trees
	Texture texturebgTree;
	texturebgTree.loadFromFile("graphics/treealt.png");
	Sprite spritebgTree, spritebgTree3;

	Texture texturebgTree1;
	texturebgTree1.loadFromFile("graphics/treealt2.png");
	Sprite spritebgTree1;

	Texture texturebgTree2;
	texturebgTree2.loadFromFile("graphics/treestump.png");
	Sprite spritebgTree2;
	//0,1620
	
	spritebgTree.setTexture(texturebgTree);
	spritebgTree.setPosition(350, -100);
	spritebgTree.setScale(0.7, 0.7);

	spritebgTree1.setTexture(texturebgTree1);
	spritebgTree1.setPosition(100, 200);
	spritebgTree1.setScale(1, 1);

	spritebgTree2.setTexture(texturebgTree2);
	spritebgTree2.setPosition(1220, 500);
	spritebgTree2.setScale(0.3, 0.3);

	spritebgTree3.setTexture(texturebgTree);
	spritebgTree3.setPosition(1520, -350);
	spritebgTree3.setScale(0.5, 1);

	// Prepare the bee

	// Is the bee currently moving?
	bool beeActive = false;

	// How fast can the bee fly
	float beeSpeed = 0.0f;

	// make 3 cloud sprites from 1 texture
	Texture textureCloud;
	Texture textureBee;

	// Load 1 new texture
	textureCloud.loadFromFile("graphics/cloud.png");
	textureBee.loadFromFile("graphics/abeja.png");

	// 3 New sprites withe the same texture
	CloudStructure spriteCloud[NumMaxClouds];
	for (int i = 0; i < NumMaxClouds; i++)
	{
		spriteCloud[i].dibuix.setTexture(textureCloud);
		spriteCloud[i].dibuix.setPosition(0, i * 250);
		spriteCloud[i].Active = false;
		spriteCloud[i].Speed = 0.0f;

	}
	
	BeeStructure spriteBee[NumMaxBees];
	for (int i = 0; i < NumMaxBees; i++)
	{
		spriteBee[i].dibuix.setTexture(textureBee);
		spriteBee[i].dibuix.setPosition(0, i * 800);
		spriteBee[i].Active = false;
		spriteBee[i].Speed = 0.0f;

	}
	// Variables to control time itself
	Clock clock;

	// Time bar
	RectangleShape timeBar;
	float timeBarStartWidth = 400;
	float timeBarHeight = 80;
	timeBar.setSize(Vector2f(timeBarStartWidth, timeBarHeight));
	timeBar.setFillColor(Color::Red);
	timeBar.setPosition((1920 / 2) - timeBarStartWidth / 2, 980);
	Time gameTimeTotal;
	float timeRemaining = 6.0f;
	float timeBarWidthPerSecond = timeBarStartWidth / timeRemaining;

	// Track whether the game is running
	bool paused = true;

	// Draw some text
	int score = 0;
	Text messageText;
	Text scoreText;

	// We need to choose a font
	Font font;
	font.loadFromFile("fonts/KOMIKAP_.ttf");

	// Set the font to our message
	messageText.setFont(font);
	scoreText.setFont(font);

	fpsText.setFont(font);
	fpsText.setCharacterSize(50);
	fpsText.setFillColor(Color::White);
	fpsText.setPosition(1600, 20);  // Posar-lo a la cantonada superior dreta

	// Assign the actual message
	messageText.setString("Press Enter to start!");
	scoreText.setString("Score = 0");

	// Make it really big
	messageText.setCharacterSize(75);
	scoreText.setCharacterSize(100);

	// Choose a color
	messageText.setFillColor(Color::White);
	scoreText.setFillColor(Color::White);
	scoreText.setOutlineColor(Color::Black);
	scoreText.setOutlineThickness(10);

	// Position the text
	FloatRect textRect = messageText.getLocalBounds();
	messageText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	messageText.setPosition(Xmax / 2.0f, Ymax / 2.0f);
	scoreText.setPosition(20, 20);

	// Prepare 5 branches
	Texture textureBranch;
	textureBranch.loadFromFile("graphics/branch.png");

	// Set the texture for each branch sprite
	for (int i = 0; i < NUM_BRANCHES; i++) {
		branches[i].setTexture(textureBranch);
		branches[i].setPosition(-2000, -2000);
		// Set the sprite's origin to dead centre
		// We can then spin it round without changing its position
		branches[i].setOrigin(220, 20);
	}

	// Prepare the player
	Texture texturePlayer;
	texturePlayer.loadFromFile("graphics/player.png");
	Sprite spritePlayer;
	spritePlayer.setTexture(texturePlayer);
	spritePlayer.setPosition(580, 720);

	// The player starts on the left
	side playerSide = side::LEFT;
	branchPositions[3] = side::NONE;

	// Prepare the gravestone
	Texture textureRIP;
	textureRIP.loadFromFile("graphics/gravestone.png");
	Sprite spriteRIP;
	spriteRIP.setTexture(textureRIP);
	spriteRIP.setPosition(680, 820);
	spriteRIP.setScale(0.7, 0.7);

	// Prepare the axe
	Texture textureAxe;
	textureAxe.loadFromFile("graphics/axe.png");
	Sprite spriteAxe;
	spriteAxe.setTexture(textureAxe);
	spriteAxe.setPosition(680, 820);
	// Prepare the flying log
	Texture textureLog;
	textureLog.loadFromFile("graphics/log.png");
	Sprite spriteLog;
	spriteLog.setTexture(textureLog);
	spriteLog.setPosition(900, 1220);
	// Some other useful log related variables
	bool logActive = false;
	float logSpeedX = 1000;
	float logSpeedY = -1500;
	// Control the player input
	bool acceptInput = false;
	// Prepare the sound
	SoundBuffer chopBuffer;
	chopBuffer.loadFromFile("sound/chop.wav");
	Sound chop;
	chop.setBuffer(chopBuffer);

	// Out of time sound
	SoundBuffer outoftimeBuffer;
	outoftimeBuffer.loadFromFile("sound/out_of_time.wav");
	Sound outoftime;
	outoftime.setBuffer(outoftimeBuffer);
	// Death sound
	SoundBuffer deathBuffer;
	deathBuffer.loadFromFile("sound/death.wav");
	Sound death;
	death.setBuffer(deathBuffer);

	// random seed
	srand((int)time(0) * 10);
	//game loop
	while (window.isOpen())
	{
		/*
		****************************************
		Handle the players input
		****************************************
		*/
		Time dt = clock.restart();

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::KeyReleased && !paused)
			{
				// Listen for key presses again
				acceptInput = true;
				// hide the axe
				spriteAxe.setPosition(2000, spriteAxe.getPosition().y);
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		// Start the game
		if (Keyboard::isKeyPressed(Keyboard::Return))
		{
			paused = false;
			// Reset the time and the score
			score = 0;
			timeRemaining = 6;
			updateBranches(1, branchPositions);
			updateBranches(2, branchPositions);
			updateBranches(3, branchPositions);
			updateBranches(4, branchPositions);
			updateBranches(5, branchPositions);
			// Make all the branches disappear
			for (int i = 1; i < NUM_BRANCHES; i++)
			{
				branchPositions[i] = side::NONE;
			}
			// Make sure the gravestone is hidden
			spriteRIP.setPosition(675, 2000);
			// Move the player into position
			spritePlayer.setPosition(580, 720);
			acceptInput = true;
		}

		// Wrap the player controls to
		// Make sure we are accepting input
		if (acceptInput)
		{
			// More code here next...
			// First handle pressing the right cursor key
			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				// Make sure the player is on the right
				playerSide = side::RIGHT;
				score++;
				// Add to the amount of time remaining
				timeRemaining += (2 / score) + .15;
				spriteAxe.setPosition(AXE_POSITION_RIGHT,
					spriteAxe.getPosition().y);
				spritePlayer.setPosition(1200, 720);
				// update the branches
				updateBranches(score, branchPositions);
				// Set the log flying to the right
				spriteLog.setPosition(810, 720);
				logSpeedX = -5000;
				logActive = true;
				acceptInput = false;
				chop.play();
			}

			// Play a chop sound
			

		// Handle the left cursor key
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				// Make sure the player is on the left
				playerSide = side::LEFT;
				score++;
				// Add to the amount of time remaining
				timeRemaining += (2 / score) + .15;
				spriteAxe.setPosition(AXE_POSITION_LEFT,
					spriteAxe.getPosition().y);
				spritePlayer.setPosition(600, 720);
				// update the branches
				updateBranches(score, branchPositions);
				// Set the log flying to the left
				spriteLog.setPosition(810, 720);
				logSpeedX = 5000;
				logActive = true;
				acceptInput = false;

				chop.play();
			}

		}

		/*
		****************************************
		Update the scene
		****************************************
		*/
		if(!paused)
		{
		// Measure time
		//Time dt = clock.restart();

		// Subtract from the amount of time remaining
		
		timeRemaining -= dt.asSeconds();
		// size up the time bar
		timeBar.setSize(Vector2f(timeBarWidthPerSecond *
			timeRemaining, timeBarHeight));

		// size up the time bar

		if (timeRemaining <= 0.0f) {
			// Pause the game
			paused = true;
			// Change the message shown to the player
			messageText.setString("Out of time!!");
			//Reposition the text based on its new size
			FloatRect textRect = messageText.getLocalBounds();
			messageText.setOrigin(textRect.left + textRect.width / 2.0f,
				textRect.top + textRect.height / 2.0f);
			messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);
			outoftime.play();
		}
			// Play the out of time sound
		
		for (int i = 0; i < NumMaxBees; i++)
		{
			/*
			// Setup the bee
			if (!beeActive)
			{

				// How fast is the bee
				beeSpeed = (rand() % 200) + 200;

				// How high is the bee
				float height = (rand() % 500) + 500;
				spriteBee[i].dibuix.setPosition(2000, height);
				beeActive = true;

			}
			else
				// Move the bee
			{

				spriteBee[i].dibuix.setPosition(spriteBee[i].dibuix.getPosition().x - (beeSpeed * dt.asSeconds()), spriteBee[i].dibuix.getPosition().y);

				// Has the bee reached the right hand edge of the screen?
				if (spriteBee[i].dibuix.getPosition().x < -100)
				{
					// Set it up ready to be a whole new cloud next frame
					beeActive = false;
				}
			}
			*/
			
			if (!spriteBee[i].Active)
			{
				float randomSize = (rand() % 3);
				spriteBee[i].Speed = (rand() % -999 + -1000);
				float height = (rand() % 505 + 500);
				spriteBee[i].dibuix.setPosition((rand() % 500 + 2100), height);
				spriteBee[i].dibuix.setScale(randomSize, randomSize);
				spriteBee[i].Active = true;
			}
			else
			{
				spriteBee[i].dibuix.setPosition(spriteBee[i].dibuix.getPosition().x + (spriteBee[i].Speed * dt.asSeconds()),
					spriteBee[i].dibuix.getPosition().y);
				if (spriteBee[i].dibuix.getPosition().x < 0)
				{
					spriteBee[i].Active = false;
				}
			}
		}
		

		// Manage the clouds
		for (int i = 0; i < NumMaxClouds; i++)
		{
			if (!spriteCloud[i].Active)
			{
				float randomSize = (rand() % 3);
				spriteCloud[i].Speed = (rand() % 200);
				spriteCloud[i].dibuix.setPosition(-200, (rand() % -520 + -510));
				spriteCloud[i].dibuix.setScale(rand() % 1 + 2, rand() % 1 + 2);
				spriteCloud[i].Active = true;
			}
			else
			{
				spriteCloud[i].dibuix.setPosition(spriteCloud[i].dibuix.getPosition().x + (spriteCloud[i].Speed * dt.asSeconds()),
					spriteCloud[i].dibuix.getPosition().y);
				if (spriteCloud[i].dibuix.getPosition().x > Xmax)
				{
					spriteCloud[i].Active = false;
				}
			}
		}


		// Update the score text
		stringstream ss;
		ss << "Score = " << score;
		scoreText.setString(ss.str());

		// update the branch sprites
		for (int i = 0; i < NUM_BRANCHES; i++)
		{
			float height = i * 150;
			if (branchPositions[i] == side::LEFT)
			{
				// Move the sprite to the left side
				branches[i].setPosition(610, height);
				// Flip the sprite round the other way
				branches[i].setRotation(180);
			}
			else if (branchPositions[i] == side::RIGHT)
			{
				// Move the sprite to the right side
				branches[i].setPosition(1330, height);
				// Set the sprite rotation to normal
				branches[i].setRotation(0);
			}
			else
			{
				// Hide the branch
				branches[i].setPosition(3000, height);
			}
		}

		// Handle a flying log				
		if (logActive)
		{
			spriteLog.setPosition(
				spriteLog.getPosition().x + (logSpeedX * dt.asSeconds()),
				spriteLog.getPosition().y + (logSpeedY * dt.asSeconds())
			);
			// Has the insect reached the right hand edge of the screen?
			if (spriteLog.getPosition().x < -100 || spriteLog.getPosition().x > 2000)
			{
				// Set it up ready to be a whole new cloud next frame
				logActive = false;
				spriteLog.setPosition(810, 720);
			}
		}

		// has the player been squished by a branch?
		if (branchPositions[5] == playerSide)
		{
			// death
			paused = true;
			acceptInput = false;
			// Draw the gravestone
			if (playerSide == side::LEFT)
			{
				spriteRIP.setPosition(510, 720);
			}
			else if (playerSide == side::RIGHT)
			{
				spriteRIP.setPosition(1175, 720);
			}
			// hide the player
			spritePlayer.setPosition(2000, 660);
			// Change the text of the message
			messageText.setString("SQUISHED!!");
			// Center it on the screen
			FloatRect textRect = messageText.getLocalBounds();
			messageText.setOrigin(textRect.left + textRect.width / 2.0f,
				textRect.top + textRect.height / 2.0f);
			messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);
			// Play the death sound
			death.play();
		}
		}
		
		frameCount++;  // Incrementa el comptador de fotogrames
		elapsedTime += dt.asSeconds();

		if (elapsedTime >= 1.0f) {
			// Actualitzar el FPS
			float fps = frameCount / elapsedTime;  // Càlcul del FPS
			stringstream ss;
			ss << "FPS: " << int(fps);  // Convertim el FPS a un enter per mostrar
			fpsText.setString(ss.str());

			// Restablir comptadors
			frameCount = 0;
			elapsedTime = 0.0f;
		}

	 /*
	 ****************************************
	 Draw the scene
	 ****************************************
	 */

	 // Clear everything from the last frame
		window.clear();

		// Draw our game scene here
		window.draw(spriteBackground);

		// Draw the clouds
		for (int i = 0; i < NumMaxClouds; i++)
		{
			window.draw(spriteCloud[i].dibuix);
		}

		window.draw(spritebgTree);
		window.draw(spritebgTree1);
		window.draw(spritebgTree2);
		window.draw(spritebgTree3);
		
		// Draw the branches
		for (int i = 0; i < NUM_BRANCHES; i++) {
			window.draw(branches[i]);
		}
		// Draw the tree
		window.draw(spriteTree);
		// Draw the player
		window.draw(spritePlayer);

		// Draw the axe
		window.draw(spriteAxe);
		// Draraw the flying log
		window.draw(spriteLog);
		// Draw the gravestone
		window.draw(spriteRIP);

		for (int i = 0; i < NumMaxBees; i++)
		{
			window.draw(spriteBee[i].dibuix);
		}

		// Draw the score
		window.draw(scoreText);
		if (paused)
		{
			// Draw our message
			window.draw(messageText);
		}

		// Draw the timebar
		window.draw(timeBar);

		window.draw(fpsText);
			// Draw our message

		// Show everything we just drew
		window.display();
	}
	return 0;
}

void updateBranches(int seed, side branca[])
{
	// Move all the branches down one place
	for (int j = NUM_BRANCHES - 1; j > 0; j--) {
		branca[j] = branca[j - 1];
	}
	// Spawn a new branch at position 0
		// LEFT, RIGHT or NONE
	srand((int)time(0) + seed);
	int r = (rand() % 5);
	switch (r) {
	case 0:
		branca[0] = side::LEFT;
		break;
	case 1:
		branca[0] = side::RIGHT;
		break;
	default:
		branca[0] = side::NONE;
		break;
	}
}