/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include <memory>

struct componentWrapper_t
{
	std::shared_ptr<void> component;
	uint64_t id;

	componentWrapper_t( std::shared_ptr<void> c, uint64_t _id )
		:component( c ), id( _id )
	{
	}
};