class Paladin :public Profession_Decorate {
public:
	int health = 0;
        int action_points = 0;
        int initiative = 0;
        int position = 0;
        Paladin (Unite* unite): Profession_Decorate(unite){
        }
        void common_hit(Unite* u) {
                if (this->unite_->current_act_points() < 1 || u->is_dead()) {
                        printw( "It's impossible!\n");
                       return;
                }
                u->decrease_hp(15);
                this->unite_->decrease_act_points(1);
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
