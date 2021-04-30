#include <list>

class Composite_Orcs : public Unite{
public:
        int how_many_orcs = 0;
        std::list<Unite*> orcs_;
        void add(Unite* orc){
                this->orcs_.push_back(orc);
		how_many_orcs += 1;
        }
        void remove(Unite* unite){
                orcs_.remove(unite);
		how_many_orcs -= 1;
        }
        void ORCS_POWER(Unite* unite){
                bool is_ready = true;
                for(auto it:orcs_){
                        if(it->current_act_points()<1){
                                is_ready = false;
                        }
                }
                if(is_ready && how_many_orcs == 3){
                        unite->decrease_hp(150);
                        for(auto it:orcs_){
                                it->decrease_act_points(it->current_act_points());
                        }
                }
                else if(is_ready && how_many_orcs == 2){
                        unite->decrease_hp(100);
                        for(auto it:orcs_){
                                it->decrease_act_points(it->current_act_points());
                        }
                }
        }

};
