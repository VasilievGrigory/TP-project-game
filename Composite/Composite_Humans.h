#include <list>

class Composite_Humans : public Unite{
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
