#pragma once

//Abstract class, because pure virtual function(s)
class MIStrategy {
public:
	virtual int ExecuteStrategy() = 0;
};