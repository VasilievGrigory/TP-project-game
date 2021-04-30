class Rogue :public Profession_Decorate {
public:
	int health = 0;
        int action_points = 0;
        int initiative = 0;
        int position = 0;
        Rogue (Unite* unite): Profession_Decorate(unite){
        }
        void common_hit(Unite* u) {
                if (this->unite_->current_act_points() < 1 || u->is_dead()) {
                        printw( "It's impossible!\n");
                       return;
                }
                u->decrease_hp(15);
                this->unite_->decrease_act_points(1);
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
