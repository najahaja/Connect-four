#include<iostream>
#include<SFML/Graphics.hpp>
using namespace std;
//Functions prototypes
void design_Items(sf::RectangleShape, sf::Sprite , sf::Texture , sf::Text , sf::Font , sf::Font , sf::Text , sf::Text , sf::Text ); //Line 36
void recordTheInput(int); //Line 74
void draw_playBoard(sf::RectangleShape, sf::Text); //Line 98
void drawCircle(int, int); //Line 114
void change_connect4_circle_colors(); //Line 134
void checkWiner(int, int); //Line 297

//constant variables
const int scr_width = 1200;
const int scr_height = 750;
const int grid_size = 100;
const int row_size = 6;
const int col_size = 7;
const int margin = 20;

sf::RenderWindow window(sf::VideoMode(scr_width, scr_height), "Connect Four- DSA Project"); //Create the window

//Gamelogic data
string player, player1 = "Player 1", player2 = "Player 2 ", winner;
int x[6][7]; 					//Track every ceil
int point[] = { 5,5,5,5,5,5,5 }; //track input row of every colomn
int win = 0; //Track there is a winner
int start_col = 0; //track for winning circles
int start_row = 0; 
int end_col = 0;
int end_row = 0;
int color=0; //track ceil color
//

void design_Items(sf::RectangleShape *grid, sf::Sprite *title, sf::Texture *texture, sf::Text *text, sf::Font *font, sf::Font *font2, sf::Font *font3, sf::Text *status, sf::Text *winText, sf::Text *winName,sf::Text *instruction)
{
	//Grid design
	(*grid).setFillColor(sf::Color::Transparent);
	(*grid).setOutlineThickness(2.0f);
	(*grid).setOutlineColor(sf::Color::White);
	//Title design
	(*texture).loadFromFile("title.png");
	(*title).setTexture(*texture);
	(*title).setPosition(750,10);
	//Connect fonts
	(*font).loadFromFile("ElFonteAngelia-Bold.ttf");
	(*font2).loadFromFile("Milky-Coffee.ttf");
	(*font3).loadFromFile("Better-Day.ttf");
	//Numbers design
	(*text).setFont(*font);
	(*text).setString("");
	(*text).setCharacterSize(80);
	//Status design
	(*status).setFont(*font2);
	(*status).setString("");
	(*status).setCharacterSize(150);
	//win text design
	(*winText).setFont(*font2);
	(*winText).setString("WIN!");
	(*winText).setCharacterSize(150);
	(*winText).setPosition(810,385);
	//winner name design
	(*winName).setFont(*font2);
	(*winName).setString("");
	(*winName).setCharacterSize(50);
	(*winName).setPosition(810,350);
	//instruction design
	(*instruction).setFont(*font2);
	(*instruction).setString("");
	(*instruction).setCharacterSize(100);
}

void recordTheInput(int index)
{	index--;
	if(point[index]>=0)
	{		
		if (player == player1)
		{
			x[point[index]][index] = 1;
			checkWiner(point[index], index);
			if(win==1)
				winner=player1;
			player = player2;
		}
		else if (player == player2)
		{
			x[point[index]][index] = 2;
			checkWiner(point[index], index);
			if(win==1)
				winner=player2;
			player = player1;
		}
		point[index]--;
	}	
}

void draw_playBoard(sf::RectangleShape *grid, sf::Text *text)
{	string num[]={"1","2","3","4","5","6","7"};  //Numbers to display under the game board
	for (int i = 0; i < col_size; i++)
	{
		for (int j = 0; j < row_size; j++)
		{
			(*grid).setPosition(sf::Vector2f(margin + grid_size * i, margin + grid_size * j)); // (left,up)
			window.draw(*grid);
			drawCircle(j, i);
		}
		(*text).setString(num[i]);
		(*text).setPosition(sf::Vector2f(50 + grid_size * i, 620));
		window.draw(*text);
	}
}

void drawCircle(int row,int colomn)
{
	if(x[row][colomn]!=0)
	{
		sf::CircleShape circle(49);
		circle.setPosition(sf::Vector2f(margin + colomn * 100, margin + row * 100));
		if (x[row][colomn] == 1)
			circle.setFillColor(sf::Color(247, 52, 52)); //red
		if(x[row][colomn] == 2)
			circle.setFillColor(sf::Color(250, 200, 50)); //yellow
		if (x[row][colomn] == 11)
			circle.setFillColor(sf::Color(166, 10, 10)); //dark red
		if (x[row][colomn] == 22)
			circle.setFillColor(sf::Color(138, 104, 4)); //dark yellow
		window.draw(circle);
	}
	if (point[0]<0&&point[1]<0&&point[2]<0&&point[3]<0&&point[4]<0&&point[5]<0&&point[6]<0)//Check wether game drow
		win=2;
}

void change_connect4_circle_colors()
{
	color=11;
	if (start_col == end_col)
	{				
		if (x[start_row][start_col] == 2) //if first circle of connect 4 is yellow 
			color = 22; //color set as dark 
		while (start_row <= end_row)
		{
			x[start_row][start_col] = color;
			start_row++;
		}
	}
	else if (start_row == end_row)
	{
		if (x[start_row][start_col] == 2)
			color = 22;
		while (end_col <= start_col)
		{
			x[start_row][end_col] = color;
			end_col++;
		}
	}
	else if (start_row < end_row && start_col > end_col)
	{
		if (x[start_row][start_col] == 2)
			color = 22;
		while (end_col <= start_col)
		{
			x[start_row][start_col] = color;
			start_row++;start_col--;
		}
	}
	else if (start_row < end_row && start_col < end_col)
	{
		if (x[start_row][start_col] == 2)
			color = 22;
		while (start_col <= end_col)
		{
			x[start_row][start_col] = color;
			start_row++;start_col++;
		}
	}
}

int main()
{
	player = player1; 			//By defolt first player is player1 
	for (int i = 0; i < 6; i++) //Assign '0' to every x
	{
		for (int t = 0; t < 7; t++)
		{
			x[i][t] = 0;
		}
	}
	
	//Create every stuff which need to display
	sf::RectangleShape grid(sf::Vector2f(grid_size, grid_size));//Create Grid 
	sf::Sprite title;//create Title
	sf::Texture texture;
	sf::Text text; //Numbers Create Text variable type for Numbers(1,2,3,4,5,6,7)
	sf::Font font; //Create pront type
	sf::Font font2;//Arialn
	sf::Font font3;
	sf::Text instruction;
	sf::Text status; //Create text for status
	sf::Text winText; //Create text for display "WIN" text
	sf::Text winName; //Create text for display winner
	design_Items(&grid,&title, &texture, &text, &font, &font2, &font3, &status, &winText, &winName, &instruction);//Design all created stuff
	//
	
	window.setFramerateLimit(15);     //set maximum frame rate to 15fps
	while (window.isOpen()) 			//If the WINDOW OPEN this loop execute
	{		
		window.clear(); 				//first, Clear the window
		sf::Event event; 				//Create Event variable called "event"
		while (window.pollEvent(event)) //If some Event(PRESS a key, PRESS mouse key, etc) happend
		{			
			switch (event.type)//check the event / check entered key
			{
			case sf::Event::Closed: //if PRESS CLOSE button
				window.close(); //window close
				break;
			case sf::Event::KeyPressed: //if press a KEYBOAD KEY
				if (win==0  &&event.key.code > 26 && event.key.code < 34)//GET INPUT //check whether ented 1-7 number //Num1=27
				{
					recordTheInput(event.key.code-26);//call "recordTheInput" function
					break;
				}
				if (event.key.code == sf::Keyboard::Space)//SPACE code is 57, RESET the program
				{
					win = 0; //set as no winner yet
					player = player1; //set current player is player1
					for (int i = 0; i < 7; i++) //Assign '5' to every point
					{
						point[i] = 5;
					}
					for (int i = 0; i < 6; i++) //Assign '0' to every x
					{
						for (int t = 0; t < 7; t++)
						{
							x[i][t] = 0;
						}
					}
				}
				break;
			}			
		}
		
		//Draw stuffs here		
		draw_playBoard(&grid, &text); //Draw the play board
		if(win!=0) //If there is WINNER or game DRAW
		{
			if(win==1)
			{
				if(player == player2)
					winName.setFillColor(sf::Color(247, 52, 52));
				if(player == player1)
					winName.setFillColor(sf::Color(250, 200, 50));
				winName.setString(winner);
				window.draw(winName);
				window.draw(winText);
				status.setString("Press SPACE to start new game");
				//change color of connect 4 circles
				change_connect4_circle_colors();
				//
			}
			else
				status.setString("GAME DRAW,\n Press SPACE to start new game");
			status.setCharacterSize(30);
			status.setPosition(750,180);
			status.setFillColor(sf::Color(255,255,255));
			
		}
		else //If there is NO WINNER
		{
			if(player == player1)
			{
				status.setString("\t  RED\nPlayer Turn ");
				status.setFillColor(sf::Color(247, 52, 52));
			}	
			else
			{
				status.setString("  YELLOW\nPlayer Turn ");
				status.setFillColor(sf::Color(250, 200, 50));
			}				
			status.setCharacterSize(40);
			status.setPosition(850,250);
			instruction.setCharacterSize(26);
			instruction.setPosition(750,150);
			instruction.setFillColor(sf::Color(255,255,255));
			instruction.setString("Enter the Column Number\n You wish to insert the disk");
			window.draw(instruction);
		}
		window.draw(title); //Draw the title
		window.draw(status); //Draw the status (RED Player Turn / YELLOW\nPlayer Turn)
		//end_Draw stuffs here
		window.display();
	}
	
	return 0;
}

void checkWiner(int row, int column)//Game LOGIC part.
{
	int coun = 1, condition = 1, y = row, z = column, n = 0;//"coun" for track number of connected circles
	start_row = row;end_row = row;
	start_col = column;end_col = column;
	if (row < 3)//Down form last entered
	{
		while (1)
		{
			end_col = column;
			if (x[y][column] == x[y + 1][column])
				coun++;
			else
				break;
			if (coun == 4)
			{
				end_row = y + 1;				
				win = 1;
				break;
			}
			y++;
		}
	}

	y = row; coun = 1;
	while (win == 0)//Left form last entered
	{
		end_row = row; end_col=column;
		if ((z - 1) >= 0)
		{
			if (x[y][z] == x[y][z - 1])
			{
				end_col=z-1;
				coun++;
			}
			else
				break;
			if (coun == 4)
			{
				win = 1;
				break;
			}
			z--;
		}
		else
			break;
	}
	if(win==0) //special porpose
		end_col=z;
	z = column;
	while (win == 0)//Right form last entered
	{
		if ((z + 1) <= 6)
		{
			if (x[y][z] == x[y][z + 1])
			{
				coun++;
				start_col=z+1;
			}				
			else
				break;
			if (coun == 4)
			{
				win = 1;
				break;
			}
			z++;
		}
		else
			break;
	}
	
	y = row; z = column; coun = 1;
	if(win==0) //special porpose
	{
		start_row = row; end_row=row;
		start_col = column; end_col=column;
	}
	while (win == 0)//Left Down form last entered
	{
		if ( (y + 1) <= 5 && (z - 1) >= 0 )
		{
			if (x[y][z] == x[y+1][z - 1])
			{
				end_row=y+1;end_col=z-1;
				coun++;
			}
			else
				break;
			if (coun == 4)
			{
				win = 1;
				break;
			}
			z--; y++;
		}
		else
			break;
	}
	y = row; z = column;
	while (win == 0)//Right Up form last entered
	{
		if ((y - 1) >= 0 && (z + 1) <= 6)
		{
			if (x[y][z] == x[y - 1][z + 1])
			{
				start_row=y-1;start_col=z+1;
				coun++;
			}
			else
				break;
			if (coun == 4)
			{
				win = 1;
				break;
			}
			z++; y--;
		}
		else
			break;
	}
	
	if(win==0) //special porpose
	{
		start_row = row; end_row=row;
		start_col = column; end_col=column;
	}
	y = row; z = column; coun = 1;
	while (win == 0)//Left Up form last entered
	{
		if ((y - 1) <= 5 && (z - 1) >= 0)
		{
			if (x[y][z] == x[y - 1][z - 1])
			{
				start_row = y-1;
				start_col = z-1;
				coun++;
			}
			else
				break;
			if (coun == 4)
			{
				win = 1;
				break;
			}
			z--; y--;
		}
		else
			break;
	}
	y = row; z = column;
	while (win == 0)//Right Down form last entered
	{
		if ((y + 1) >= 0 && (z + 1) <= 6)
		{
			if (x[y][z] == x[y + 1][z + 1])
			{
				end_row = y+1;
				end_col = z+1;
				coun++;
			}
			else
				break;
			if (coun == 4)
			{
				win = 1;
				break;
			}
			z++; y++;
		}
		else
			break;
	}
}
