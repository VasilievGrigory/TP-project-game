class Orc : public Unite{
public:
	int health = 100;
        int action_points = 3;
        int initiative = 4;
        int position = 0;
        Unite* stats_ = new Unite;
	Orc(){
		stats_->health = health;
		stats_->action_points = action_points;
		stats_->initiative = initiative;
		stats_->position = position;
	}
        Orc (int pos){
                health = 100;
                action_points = 3;
                initiative = 4;
                position = pos;
                stats_->health = health;
		stats_->action_points = action_points;
		stats_->initiative = initiative;
		stats_->position = position;
        }
        int max_health() {
                return 100;
        }
        void common_hit(Unite* u) {
                if (this->action_points < 1 || u->is_dead()) {
                        printw("I can't do this!\n");
                        return;
                }
                u->decrease_hp(10);
                this->action_points--;
        }
};
