#pragma once

#include "library.hh"

using namespace std;

class Toplevel {
    private:
        Env global_env;

    public:
        Toplevel();
        void go(bool use_prompt);
};
