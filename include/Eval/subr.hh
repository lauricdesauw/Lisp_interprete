#pragma once

#include "library.hh"
#include "defs.hh"

bool subrp (Object obj);

Object apply_subr(Object sub, Object lvals);
