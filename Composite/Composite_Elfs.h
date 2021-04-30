#include <list>

class Composite_Elfs : public Unite{
public:
        int how_many_elfs = 0;
        std::list<Unite*> elfs_;
        void add(Unite* elf){
                this->elfs_.push_back(elf);
		how_many_elfs += 1;
        }
        void remove(Unite* unite){
                elfs_.remove(unite);
		how_many_elfs -= 1;
        }
        void ELFS_POWER(Unite* unite){
                bool is_ready = true;
                for(auto it:elfs_){
                        if(it->current_act_points()<1){
                                is_ready = false;
                        }
                }
                if(is_ready && how_many_elfs == 3){
                        unite->decrease_hp(150);
                }
                else if(is_ready && how_many_elfs == 2){
                        unite->decrease_hp(100);
                        for(auto it:elfs_){
                                it->decrease_act_points(2);
                        }
                }
        }

};
