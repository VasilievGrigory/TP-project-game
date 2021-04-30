class Unite {
public:
	int health = 0;
	int action_points = 0;
	int initiative = 0;
	int position = 0;
	int current_pos(){
		return this->position;
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
	bool is_dead() {
		if (this->health <= 0) {
			return true;
		}
		return false;
	}
	~Unite() = default;
};
