#include <vector>
#include <string>
#include <ncurses.h>
#include "Unite.h"
#include "Professions/Profession_Decorate.h"
#include "Professions/Mage.h"
#include "Professions/Warrior.h"
#include "Professions/Archer.h"
#include "Professions/Rogue.h"
#include "Professions/Paladin.h"
#include "Enemies.h"
#include "Composite/Composite_Elfs.h"
#include "Composite/Composite_Humans.h"
#include "Composite/Composite_Orcs.h"
#include "Races/Human.h"
#include "Races/Orc.h"
#include "Races/Elf.h"

class Game{
	private:
		const char professions[5][8]={
                                        "Mage",
                                        "Warrior",
                                         "Archer",
                                         "Rogue",
                                         "Paladin"};
		const char races[3][6]={
                                        "Elf",
                                        "Orc",
                                         "Human"};
		std::vector<std::string> army_string;
                std::vector<Unite*> army_unite;
	public:
		bool is_ready = false;
		bool currect_state(){
			return this->is_ready;
		}
		void New_Game(){
			this->is_ready = true;
			printw("Welcome to the unites constructor!\n"
					"(Press any key to continue...)");
			getch();
			for (int i=1;i<=3;i++){
				int pick_rc = pick_unite(4-i);
				int pick_pr = pick_profession();
				std::string race = races[pick_rc];
				std::string prof = professions[pick_pr];
				std::string full_name = race + "-" + prof; 
				army_string.push_back(full_name);
				Unite* hero = create_profession(pick_pr, create_race(pick_rc));
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
		int pick_unite(int i){
		        bool exit = false;
                	int choice = 0;
                	curs_set(0);
                        keypad(stdscr,true);
                        while(!exit){
				clear();
                                printw("Here and always: dm = damage, gap = give action points,"
						"ca = cost of action, h = heal, # = ALL, I = initiative\n");
				printw("Pick ");
                                printw("%d ",i);
                                printw("more:\n");
                                printw("Check out all the races:\n\n"
						"(REMEMBER! If you pick more than 1 hero of a given race, you can combine "
						"them into a squad during the game and get a powerful blow!)\n");
                                printw("Elf:\nHP = 60\nAP = 3\nI = 8\nC`ommon_hit = 15dm1ca\n\n");
                                printw("Orc:\nHP = 100\nAP = 3\nI = 4\nCommon_hit = 10dm1ca\n\n");
                                printw("Human:\nHP = 60\nAP = 3\nI = 7\nCommon_hit = 15dm1ca\n\n");
				printw("Now, choose race for your future unite!\n");
                                for(int i=0;i<3;i++){
                                        if(i==choice){
                                                addch('>');
                                        }
                                        else addch(' ');
                                        printw("%s",races[i]);
                                }
				printw("\n(To iterate use: KEY_LEFT and KEY_RIGHT)");
				printw("\n(To pick click KEY_UP)");
                                switch(getch()){
                                        case KEY_LEFT:
                                                if(choice) choice--;
                                                break;
                                        case KEY_RIGHT:
                                                if(choice!=2) choice++;
                                                break;
                                        case KEY_UP:
						exit = true;
                                                break;

				}
			}
			return choice;
		}
		int pick_profession(){
			bool exit = false;
                	int choice = 0;
                	curs_set(0);
                        keypad(stdscr,true);
                        while(!exit){
				clear();
				printw("You pick your unite's race! Now pick his profession:\n");
				printw("Mage:\nAbilities:\n1) fireball = 35dm2ca\n2) heal = 10h2ca\n\n");
                        	printw("Warrior:\nAbilities:\n1) hit_with_stan = 30dm#apdm3ca\n2) strong_hit = 30dm2ca\n\n");
                        	printw("Archer:\nAbilities:\n1) drag_arrow = 30dm2ca\n2) deadly_arrow = (10 + 20*)dm2ca"
				       	"(*if less 20 hp after first hit)\n\n");
                        	printw("Rogue:\nAbilities:\n1) blade_of_shadow = 10*dm2ca (if enemy died after hit," 
					"rogue gets 1ap and 10hp)\n2) irrepressibility  = 2ap (target unite gets 3ap)\n\n");
                	        printw("Paladin:\nAbilities:\n1) hit_with_blind = 20dm3ap2ca\n2) blessing = 10h2gap2ca\n\n");
				printw("Now, choose profession for your future unite!\n");
				for(int i=0;i<5;i++){
                                        if(i==choice){
                                                addch('>');
                                        }
                                        else addch(' ');
                                        printw("%s",professions[i]);
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
	Unite* create_race(int picked_race){
			if(picked_race ==  0){
				Unite* e = new Elf;
				return e;
			}
			else if(picked_race == 1){
				Unite* o = new Orc;
				return o;
			}
			else{
				Unite* h = new Human;
				return h;
			}
		
	}
	Unite* create_profession(int picked_prof, Unite* race){
			if(picked_prof == 0){
				Unite* u = new Mage(race);
			       return u;
			}
			else if(picked_prof == 1){
                                Unite* u = new Warrior(race);
                               return u;
		       }
			else if(picked_prof == 2){
                                Unite* u = new Archer(race);
                               return u;
			}
			else if(picked_prof == 3){
                                Unite* u = new Rogue(race);
                               return u;
			}
			else{
                                Unite* u = new Paladin(race);
                               return u;
			}	       
		}
};
