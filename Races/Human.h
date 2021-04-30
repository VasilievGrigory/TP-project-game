class Human : public Unite{
public:
        int health = 85;
        int action_points = 3;
        int initiative = 7;
        int position = 0;
        Unite* stats_ = new Unite;
	Human(){
		stats_->health = health;
		stats_->action_points = action_points;
		stats_->initiative = initiative;
		stats_->position = position;
	}
        Human (int pos){
                health = 85;
                action_points = 3;
                initiative = 7;
                position = pos;
                stats_->health = health;
		stats_->action_points = action_points;
		stats_->initiative = initiative;
		stats_->position = position;
        }
        int max_health() {
                return 85;
        }
        void common_hit(Unite* u) {
                if (this->action_points < 1 || u->is_dead()) {
                        printw("It's impossible!\n");
                        return;
                }
                u->decrease_hp(15);
                this->action_points--;
        }
};
