#include <ncurses.h>
#include <vector>
#include <string>
class Unite {
public:
	virtual void common_hit(Unite&) = 0;
	virtual int max_health() = 0;
	virtual bool is_dead() = 0;
	virtual int current_pos() = 0;
	virtual int current_hp() = 0;
	virtual int current_act_points() = 0;
	virtual void decrease_hp(int) = 0;
	virtual void decrease_act_points(int) = 0;
	virtual ~Unite() = 0;
};
Unite::~Unite()=default;
