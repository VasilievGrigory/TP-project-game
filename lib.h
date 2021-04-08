#include <ncurses.h>
#include <vector>
#include <string>
#include <list>
class Unite {
public:
	virtual void common_hit(Unite*) = 0;
	virtual int max_health() = 0;
	virtual bool is_dead() = 0;
	virtual int current_pos() = 0;
	virtual int current_hp() = 0;
	virtual int current_act_points() = 0;
	virtual void decrease_hp(int) = 0;
	virtual void decrease_act_points(int) = 0;
	virtual ~Unite() = 0;
};
Unite::~Unite()=default;
class Profession_Decorate:public Unite{
protected:
	Unite* unite_;
public:
	int health = 0;
	int mx_hp = 0;
        int action_points = 0;
        int initiative = 0;
        int position = 0;
        Profession_Decorate (Unite* unite): unite_(unite){
        }
	int current_pos(){
                return this->unite_->current_pos();
        }
        int max_health() {
                return this->unite_->max_health();
        }
        int  current_hp(){
                return this->unite_->current_hp();
        }
        int  current_act_points(){
                return this->unite_->current_act_points();
        }
        void decrease_hp(int damage){
                this->unite_->decrease_hp(damage);
        }
        void decrease_act_points(int damage_points){
                this->unite_->decrease_act_points(damage_points);
        }
        void common_hit(Unite* u) {
                if (this->unite_->current_act_points() < 1 || u->is_dead()) {
                        printw( "It's impossible!\n");
                        return;
                }
                u->decrease_hp(15);
                this->unite_->decrease_act_points(1);
        }
	bool is_dead() {
		if (this->unite_->current_hp() <= 0) {
                        return true;
                }
                return false;
        }
       

};
class Orc : public Unite{
public:
	int health = 100;
        int action_points = 3;
        int initiative = 4;
        int position = 0;
        Orc (int pos){
                health = 100;
                action_points = 3;
                initiative = 4;
                position = pos;
        }
        Orc() = default;
	int current_pos(){
                return this->position;
        }
        int max_health() {
                return 100;
        }
        int  current_hp(){
                return this->health;
        }
        int  current_act_points(){
                return this->action_points;
        }
        void decrease_hp(int damage){
                this->health -= damage;
        }
        void decrease_act_points(int damage_points){
                this->action_points -= damage_points;
        }
        void common_hit(Unite* u) {
                if (this->action_points < 1 || u->is_dead()) {
                        printw("I can't do this!\n");
                        return;
                }
                u->decrease_hp(10);
                this->action_points--;
        }
        bool is_dead() {
                if (this->current_hp() <= 0) {
                        return true;
                }
                return false;
        }
};
class Elf : public Unite{
public:
        int health = 60;
        int action_points = 3;
        int initiative = 8;
        int position = 0;
	Elf() = default;
        Elf (int pos){
                health = 60;
                action_points = 3;
                initiative = 8;
                position = pos;
        }
	int current_pos(){
                return this->position;
        }
        int max_health() {
                return 60;
        }
        int  current_hp(){
                return this->health;
        }
        int  current_act_points(){
                return this->action_points;
        }
        void decrease_hp(int damage){
                this->health -= damage;
        }
        void decrease_act_points(int damage_points){
                this->action_points -= damage_points;
        }
        void common_hit(Unite* u) {
                if (this->action_points < 1 || u->is_dead()) {
                        printw( "It's impossible!\n");
                        return;
                }
                u->decrease_hp(15);
                this->action_points--;
        }
	bool is_dead() {
                if (this->current_hp() <= 0) {
                        return true;
                }
                return false;
        }
};
class Human : public Unite{
public:
        int health = 85;
        int action_points = 3;
        int initiative = 7;
        int position = 0;
        Human (int pos){
                health = 85;
                action_points = 3;
                initiative = 7;
                position = pos;
        }
        int current_pos(){
                return this->position;
        }
        Human() = default;
        int max_health() {
                return 85;
        }
        int  current_hp(){
                return this->health;
        }
        int  current_act_points(){
                return this->action_points;
        }
        void decrease_hp(int damage){
                this->health -= damage;
        }
        void decrease_act_points(int damage_points){
                this->action_points -= damage_points;
        }
        void common_hit(Unite* u) {
                if (this->action_points < 1 || u->is_dead()) {
                        printw("It's impossible!\n");
                        return;
                }
                u->decrease_hp(15);
                this->action_points--;
        }
        bool is_dead() {
                if (this->current_hp() <= 0) {
                        return true;
                }
                return false;
        }
};

class Mage :public Profession_Decorate {
public:
	int health = 0;
	int action_points = 0;
	int initiative = 0;
	int position = 0;
	Mage (Unite* unite): Profession_Decorate(unite){
	}
	int current_pos(){
                return this->unite_->current_pos();
        }
        int max_health() {
                return this->unite_->max_health();
        }
        int  current_hp(){
                return this->unite_->current_hp();
        }
        int  current_act_points(){
                return this->unite_->current_act_points();
        }
        void decrease_hp(int damage){
                this->unite_->decrease_hp(damage);
        }
        void decrease_act_points(int damage_points){
                this->unite_->decrease_act_points(damage_points);
        }
        void common_hit(Unite* u) {
                if (this->unite_->current_act_points() < 1 || u->is_dead()) {
                        printw( "It's impossible!\n");
                       return;
                }
                u->decrease_hp(15);
                this->unite_->decrease_act_points(1);
        }
        bool is_dead() {
                if (this->unite_->current_hp() <= 0) {
                        return true;
                }
                return false;
        }
	void fireball(Unite* u){
		if(this->unite_->current_act_points() < 2 || u->is_dead()){
			printw( "It's impossible!\n");
			return;
		}
		u->decrease_hp(35);
		this->unite_->decrease_act_points(2);
	}
	void heal(Unite* u) {
		if (this->unite_->current_act_points() < 2 || u->max_health()==u->current_hp()) {
			printw( "It's impossible!\n");
			return;
		}
		u->decrease_hp(-10);
		this->unite_->decrease_act_points(2);
	}
	~Mage() = default;
};

class Warrior :public Profession_Decorate {
public:
	int health = 0;
        int action_points = 0;
        int initiative = 0;
        int position = 0;
        Warrior (Unite* unite): Profession_Decorate(unite){
        }
        int current_pos(){
                return this->unite_->current_pos();
        }
        int max_health() {
                return this->unite_->max_health();
        }
        int  current_hp(){
                return this->unite_->current_hp();
        }
        int  current_act_points(){
                return this->unite_->current_act_points();
        }
        void decrease_hp(int damage){
                this->unite_->decrease_hp(damage);
        }
        void decrease_act_points(int damage_points){
                this->unite_->decrease_act_points(damage_points);
        }
        void common_hit(Unite* u) {
                if (this->unite_->current_act_points() < 1 || u->is_dead()) {
                        printw( "It's impossible!\n");
                       return;
                }
                u->decrease_hp(15);
                this->unite_->decrease_act_points(1);
        }
        bool is_dead() {
                if (this->unite_->current_hp() <= 0) {
                        return true;
                }
                return false;
        }
	void hit_with_stun(Unite* u) {
		if (this->unite_->current_act_points() < 2 || u->is_dead()) {
			printw("I can't do this!\n");
			return;
		}
		u->decrease_hp(30);
		u->decrease_act_points(u->current_act_points());
		this->unite_->decrease_act_points(3);
	}
	void strong_hit(Unite* u) {
		if (this->unite_->current_act_points() < 2 || u->is_dead()) {
			printw("I can't do this!\n");
			return;
		}
		u->decrease_hp(30);
		this->unite_->decrease_act_points(2);
	}
	~Warrior() = default;
};

class Archer :public Profession_Decorate {
public:
	int health = 0;
        int action_points = 0;
        int initiative = 0;
        int position = 0;
        Archer (Unite* unite): Profession_Decorate(unite){
        }
        int current_pos(){
                return this->unite_->current_pos();
        }
        int max_health() {
                return this->unite_->max_health();
        }
        int  current_hp(){
                return this->unite_->current_hp();
        }
        int  current_act_points(){
                return this->unite_->current_act_points();
        }
        void decrease_hp(int damage){
                this->unite_->decrease_hp(damage);
        }
        void decrease_act_points(int damage_points){
                this->unite_->decrease_act_points(damage_points);
        }
        void common_hit(Unite* u) {
                if (this->unite_->current_act_points() < 1 || u->is_dead()) {
                        printw( "It's impossible!\n");
                       return;
                }
                u->decrease_hp(15);
                this->unite_->decrease_act_points(1);
        }
        bool is_dead() {
                if (this->unite_->current_hp() <= 0) {
                        return true;
                }
                return false;
        }
	void deadly_arrow(Unite* u){
		if (this->unite_->current_act_points() < 3 || u->is_dead()) {
			printw("It can't be done!\n");
			return;
		}
		u->decrease_hp(10);
		if (u->current_hp() <= 20) {
			u->decrease_hp(u->current_hp());
		}
		this->unite_->decrease_act_points(3);
	}
	void drag_arrow(Unite* u) {
		if (this->unite_->current_act_points() < 2 || u->is_dead()) {
			printw("It can't be done!\n");
			return;
		}
		u->decrease_hp(30);
		this->unite_->decrease_act_points(2);
	}
	~Archer() = default;
};

class Rogue :public Profession_Decorate {
public:
	int health = 0;
        int action_points = 0;
        int initiative = 0;
        int position = 0;
        Rogue (Unite* unite): Profession_Decorate(unite){
        }
        int current_pos(){
                return this->unite_->current_pos();
        }
        int max_health() {
                return this->unite_->max_health();
        }
        int  current_hp(){
                return this->unite_->current_hp();
        }
        int  current_act_points(){
                return this->unite_->current_act_points();
        }
        void decrease_hp(int damage){
                this->unite_->decrease_hp(damage);
        }
        void decrease_act_points(int damage_points){
                this->unite_->decrease_act_points(damage_points);
        }
        void common_hit(Unite* u) {
                if (this->unite_->current_act_points() < 1 || u->is_dead()) {
                        printw( "It's impossible!\n");
                       return;
                }
                u->decrease_hp(15);
                this->unite_->decrease_act_points(1);
        }
        bool is_dead() {
                if (this->unite_->current_hp() <= 0) {
                        return true;
                }
                return false;
        }
	void blade_of_shadow(Unite* u) {
		if (this->unite_->current_act_points() < 2 || u->is_dead()) {
			printw("It's impossible!\n");
			return;
		}
		u->decrease_hp(10);
		if (u->current_hp()<=0){
			this->unite_->decrease_act_points(-1);
			this->unite_->decrease_hp(-10);
		}
		this->unite_->decrease_act_points(2);
	}
	void irrepressibility(Unite* u) {
		if (u->is_dead()){
			printw("This is silly...\n");
			return;
		}
		if(this->unite_->current_act_points()<3){
			printw("It's impossible!\n");
			return;
		}
		u->decrease_act_points(-3);
		this->unite_->decrease_act_points(2);
	}
	~Rogue() = default;
};

class Paladin :public Profession_Decorate {
public:
	int health = 0;
        int action_points = 0;
        int initiative = 0;
        int position = 0;
        Paladin (Unite* unite): Profession_Decorate(unite){
        }
        int current_pos(){
                return this->unite_->current_pos();
        }
        int max_health() {
                return this->unite_->max_health();
        }
        int  current_hp(){
                return this->unite_->current_hp();
        }
        int  current_act_points(){
                return this->unite_->current_act_points();
        }
        void decrease_hp(int damage){
                this->unite_->decrease_hp(damage);
        }
        void decrease_act_points(int damage_points){
                this->unite_->decrease_act_points(damage_points);
        }
        void common_hit(Unite* u) {
                if (this->unite_->current_act_points() < 1 || u->is_dead()) {
                        printw( "It's impossible!\n");
                       return;
                }
                u->decrease_hp(15);
                this->unite_->decrease_act_points(1);
        }
        bool is_dead() {
                if (this->unite_->current_hp() <= 0) {
                        return true;
                }
                return false;
        }
	void hit_with_blind(Unite* u) {
		if (this->unite_->current_act_points() < 2 || u->is_dead()) {
			printw("It's impossible!\n");
			return;
		}
		u->decrease_hp(20);
		u->decrease_act_points(3);
		this->unite_->decrease_act_points(2);
	}
	void blessing(Unite* u) {
		if (this->unite_->current_act_points() < 3) {
			printw("It's impossible!\n");
			return;
		}
		u->decrease_hp(-10);
		u->decrease_act_points(-2);
		this->unite_->decrease_act_points(3);
	}
	~Paladin() = default;
};

class Easy_enemy :public Unite {
public:
	int health = 50;
	int action_points = 3;
	int initiative = 3;
	int position = 0;
	int current_pos(){
		return this->position;
	}
	Easy_enemy() = default;
	int max_health() {
		return 50;
	}
	int  current_hp(){
                return this->health;
        }
	int  current_act_points(){
                return this->action_points;
        }
	void decrease_hp(int damage){
                this->health -= damage;
        }
        void decrease_act_points(int damage_points){
                this->action_points -= damage_points;
        }
	void common_hit(Unite& u) {
		if (this->action_points < 1 || u.is_dead()) {
			printw("NO!\n");
			return;
		}
		u.decrease_hp(10);
		this->action_points--;
	}
	bool is_dead() {
		if (this->health <= 0) {
			return true;
		}
		return false;
	}
	~Easy_enemy() = default;
};

class Medium_enemy :public Unite {
public:
	int health = 70;
	int action_points = 3;
	int initiative = 5;
	int position = 0;
        int current_pos(){
                return this->position;
        }
	Medium_enemy() = default;
	int max_health() {
		return 70;
	}
	int  current_hp(){
                return this->health;
        }
	int  current_act_points(){
                return this->action_points;
        }
	void decrease_hp(int damage){
                this->health -= damage;
        }
        void decrease_act_points(int damage_points){
                this->action_points -= damage_points;
        }
	void common_hit(Unite& u) {
		if (this->action_points < 1 || u.is_dead()) {
			printw("NO!\n");
			return;
		}
		u.decrease_hp(15);
		this->action_points--;
	}
	bool is_dead() {
		if (this->health <= 0) {
			return true;
		}
		return false;
	}
	~Medium_enemy() = default;
};

class Hard_enemy :public Unite {
public:
	int health = 80;
	int action_points = 4;
	int initiative = 7;
	int position = 0;
        int current_pos(){
                return this->position;
        }
	Hard_enemy() = default;
	int max_health() {
		return 80;
	}
	int  current_hp(){
                return this->health;
        }
	int  current_act_points(){
                return this->action_points;
        }
       
	void decrease_hp(int damage){
                this->health -= damage;
        }
        void decrease_act_points(int damage_points){
                this->action_points -= damage_points;
        }
	void common_hit(Unite& u) {
		if (this->action_points < 1 || u.is_dead()) {
			printw("NO!\n");
			return;
		}
		u.decrease_hp(20);
		this->action_points--;
	}
	bool is_dead() {
		if (this->health <= 0) {
			return true;
		}
		return false;
	}
	~Hard_enemy() = default;
};

class Composite : public Unite{
	int health = -1;
        int mx_hp = -1;
        int action_points = -1;
        int initiative = -1;
        int position = -1;
        int current_pos(){
                return -1;
        }
        int max_health() {
                return -1;
        }
        int  current_hp(){
                return -1;
        }
        int  current_act_points(){
                return -1;
        }
        void decrease_hp(int damage){
                return ;
        }
        void decrease_act_points(int damage_points){
                return ;
        }
        void common_hit(Unite* u) {
                return ;
        }
        bool is_dead() {
                return false;
        }
};

class Composite_Humans : public Composite{
public:
	int how_many_humans = 0;
	std::list<Unite*> humans_;
	void add(Unite* human){
		this->humans_.push_back(human);
		how_many_humans += 1;
	}
	void remove(Unite* unite){
		this->humans_.remove(unite);
		how_many_humans -= 1;
	}
	void HUMANS_POWER(Unite* unite){
		bool is_ready = true;
		for(auto it: humans_){
			if(it->current_act_points()<1){
				is_ready = false;
			}
		}
		if(is_ready && how_many_humans == 3){
			unite->decrease_hp(150);
			for(auto it : humans_){
                        	it->decrease_act_points(it->current_act_points());
			}
		}
		else if(is_ready && how_many_humans == 2){
                        unite->decrease_hp(100);
                        for(auto it : humans_){
                                it->decrease_act_points(it->current_act_points());
                        }
                }
	}

};

class Composite_Elfs : public Composite{
public:
        int how_many_elfs = 0;
        std::list<Unite*> elfs_;
        void add(Unite* elf){
                this->elfs_.push_back(elf);
		how_many_elfs += 1;
        }
        void remove(Unite* unite){
                elfs_.remove(unite);
		how_many_elfs -= 1;
        }
        void ELFS_POWER(Unite* unite){
                bool is_ready = true;
                for(auto it:elfs_){
                        if(it->current_act_points()<1){
                                is_ready = false;
                        }
                }
                if(is_ready && how_many_elfs == 3){
                        unite->decrease_hp(150);
                }
                else if(is_ready && how_many_elfs == 2){
                        unite->decrease_hp(100);
                        for(auto it:elfs_){
                                it->decrease_act_points(2);
                        }
                }
        }

};

class Composite_Orcs : public Composite{
public:
        int how_many_orcs = 0;
        std::list<Unite*> orcs_;
        void add(Unite* orc){
                this->orcs_.push_back(orc);
		how_many_orcs += 1;
        }
        void remove(Unite* unite){
                orcs_.remove(unite);
		how_many_orcs -= 1;
        }
        void ORCS_POWER(Unite* unite){
                bool is_ready = true;
                for(auto it:orcs_){
                        if(it->current_act_points()<1){
                                is_ready = false;
                        }
                }
                if(is_ready && how_many_orcs == 3){
                        unite->decrease_hp(150);
                        for(auto it:orcs_){
                                it->decrease_act_points(it->current_act_points());
                        }
                }
                else if(is_ready && how_many_orcs == 2){
                        unite->decrease_hp(100);
                        for(auto it:orcs_){
                                it->decrease_act_points(it->current_act_points());
                        }
                }
        }

};

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
