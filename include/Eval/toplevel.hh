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

bool is_load_directive(Object obj);
void handle_load_core(std::string file_name, Toplevel* toplevel);
void handle_load(Object obj, Toplevel* toplevel);
