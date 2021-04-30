class Elf : public Unite{
public:
        int health = 60;
        int action_points = 3;
        int initiative = 8;
        int position = 0;
        Unite* stats_ = new Unite;
	Elf(){
		stats_->health = health;
		stats_->action_points = action_points;
		stats_->initiative = initiative;
		stats_->position = position;
	}
        Elf (int pos){
                health = 60;
                action_points = 3;
                initiative = 8;
                position = pos;
                stats_->health = health;
		stats_->action_points = action_points;
		stats_->initiative = initiative;
		stats_->position = position;
        }
        int max_health() {
                return 60;
        }
        void common_hit(Unite* u) {
                if (this->action_points < 1 || u->is_dead()) {
                        printw( "It's impossible!\n");
                        return;
                }
                u->decrease_hp(15);
                this->action_points--;
        }
};
