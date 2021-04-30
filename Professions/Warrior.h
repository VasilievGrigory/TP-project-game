class Warrior :public Profession_Decorate {
public:
	int health = 0;
        int action_points = 0;
        int initiative = 0;
        int position = 0;
        Warrior (Unite* unite): Profession_Decorate(unite){
        }
        void common_hit(Unite* u) {
                if (this->unite_->current_act_points() < 1 || u->is_dead()) {
                        printw( "It's impossible!\n");
                       return;
                }
                u->decrease_hp(15);
                this->unite_->decrease_act_points(1);
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

