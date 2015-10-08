#pragma once

#define GET_PROPERTY(TYPE, NAME) \
	TYPE _Get##NAME() const { return NAME; } \
	__declspec(property(get = _Get##NAME)) TYPE NAME;