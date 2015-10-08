#pragma once

#define GET_PROPERTY(TYPE, NAME, FNAME) \
	TYPE _Get##NAME() const { return FNAME; } \
	__declspec(property(get = _Get##NAME)) TYPE NAME;