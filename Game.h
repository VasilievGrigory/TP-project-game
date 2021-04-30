#pragma once
#include <vector>
#include <string>
#include <ncurses.h>
#include "Unite.h"
#include "Mage.h"
#include "Warrior.h"
#include "Archer.h"
#include "Rogue.h"
#include "Paladin.h"
#include "Enemies.h"
class Game{
protected:
	
	bool is_ready = false;
	Game(){
		is_ready = true;
	}
	static Game* game_;
public:
	Game(Game& g) = delete;
	void operator= (const Game& g) = delete;
	static Game* GetInstance();
	bool currect_state(){
		return this->is_ready;
	}
	void New_Game(){
	const char profs[5][8]={
                	        "Mage",
                        	"Warrior",
                       		 "Archer",
                       		 "Rogue",
                       		 "Paladin"};
	std::vector<std::string> army_string;
        std::vector<Unite*> army_unite;
		for (int i=1;i<=3;i++){
			int pick_pr = pick_profession(4 - i);
			std::string name = profs[pick_pr];
			army_string.push_back(name);
			Unite* hero = create_prof(pick_pr);
			army_unite.push_back(hero);
		}
		clear();
		printw("You have made your choice!\n");
		printw("Your army is:\n");
		printw("%s\n",army_string[0].c_str());
		printw("%s\n",army_string[1].c_str());
		printw("%s\n",army_string[2].c_str());
		printw("It's all for now!\nPress any key to leave...");
		getch();
	}
	int pick_profession(int i){
		const char items[5][8]={
                	        "Mage",
                        	"Warrior",
                       		 "Archer",
                       		 "Rogue",
                       		 "Paladin"};
		bool exit = false;
        	int choice = 0;
        	curs_set(0);
                keypad(stdscr,true);
                while(!exit){
             		clear();
			printw("Welcome to the unites constructor!\n");
                        printw("Here and always: dm = damage, gap = give action points, ca = cost of action, h = heal, # = ALL, I = initiative\n");
                        printw("Check out all the unites:\n\n");
                        printw("Mage:\nHP = 60\nAP = 3\nI = 8\nCommon_hit = 15dm1ca\n      Abilities:\n1) fireball = 35dm2ca\n2) heal = 10h2ca\n\n");
                        printw("Warrior:\nHP = 100\nAP = 3\nI = 4\nCommon_hit = 10dm1ca\n      Abilities:\n1) hit_with_stan = 30dm#apdm3ca\n2) strong_hit = 30dm2ca\n\n");
                        printw("Archer:\nHP = 70\nAP = 4\nI = 6\nCommon_hit = 10dm1ca\n      Abilities:\n1) drag_arrow = 30dm2ca\n2) deadly_arrow = (10 + 20*)dm2ca (*if less 20 hp after first hit)\n\n");
                        printw("Rogue:\nHP = 60\nAP = 4\nI = 7\nCommon_hit = 15dm1ca\n      Abilities:\n1) blade_of_shadow = 10*dm2ca (if enemy died after hit, rogue gets 1ap and 10hp)\n2) irrepressibility  = 2ap (target unite gets 3ap)\n\n");
                        printw("Paladin:\nHP = 60\nAP = 3\nI = 7\nCommon_hit = 15dm1ca\n      Abilities:\n1) hit_with_blind = 20dm3ap2ca\n2) blessing = 10h2gap2ca\n\n");
			printw("Now, choose your unites!\n");
			printw("Pick ");
			printw("%d ",i);
			printw("more:\n");
                        for(int i=0;i<5;i++){
                                if(i==choice){
                                        addch('>');
                                }
                                else addch(' ');
                                printw("%s",items[i]);
                        }
			printw("\n(To iterate use: KEY_LEFT and KEY_RIGHT)");
			printw("\n(To pick click KEY_UP)");
                        switch(getch()){
                                case KEY_LEFT:
                                        if(choice) choice--;
                                        break;
                                case KEY_RIGHT:
                                        if(choice!=4) choice++;
                                        break;
                                case KEY_UP:
					exit = true;
                                        break;

			}
		}
		return choice;
	}
	Unite* create_prof(int picked_prof){
		if(picked_prof ==  0){
			Unite* e = new Mage;
			return e;
		}
		else if(picked_prof == 1){
			Unite* o = new Warrior;
			return o;
		}
		else if(picked_prof = 2){
			Unite* h = new Archer;
			return h;
		}
		else if(picked_prof = 3){
			Unite* h = new Rogue;
			return h;
		}
		else{
			Unite* h = new Paladin;
			return h;
		}
	}
};
Game* Game::game_ = nullptr;
Game* Game::GetInstance(){
	if(game_ = nullptr){
		game_ = new Game();
	}
	return game_;
}
