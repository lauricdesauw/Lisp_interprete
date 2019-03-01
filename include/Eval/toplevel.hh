#pragma once

#include "library.hh"

using namespace std;

class Toplevel {
    private:
        Env global_env;
        static bool is_load_directive(Object obj);
        void handle_load_core(std::string file_name);
        void handle_load(Object obj);
        bool DEBUG_MODE;
        bool STAT_MODE;

    public:
        Toplevel();
        void go();
        void handle_load_from_string(std::string path);
};
