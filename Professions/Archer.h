class Archer :public Profession_Decorate {
public:
	int health = 0;
        int action_points = 0;
        int initiative = 0;
        int position = 0;
        Archer (Unite* unite): Profession_Decorate(unite){
        }
        void common_hit(Unite* u) {
                if (this->unite_->current_act_points() < 1 || u->is_dead()) {
                        printw( "It's impossible!\n");
                       return;
                }
                u->decrease_hp(15);
                this->unite_->decrease_act_points(1);
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
