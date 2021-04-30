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
        void common_hit(Unite* u) {
                if (this->unite_->current_act_points() < 1 || u->is_dead()) {
                        printw( "It's impossible!\n");
                        return;
                }
                u->decrease_hp(15);
                this->unite_->decrease_act_points(1);
        }
};
