#ifndef MI_Strategy
#define MI_Strategy

namespace bungie {
//Abstract class, because pure virtual function(s)
class MIStrategy {
public:
	virtual ~MIStrategy() = default;
	MIStrategy() = default;
	virtual int ExecuteStrategy() = 0;
};
}

#endif