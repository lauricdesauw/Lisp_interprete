#include "garbage_collector.hh"
#include "iostream"
#include "collectable.hh"

std::vector<Collectable*> Garbage_collector::root = std::vector<Collectable*>();
std::vector<Collectable*> Garbage_collector::all = std::vector<Collectable*>();

void Garbage_collector::clean()
{
    for(std::vector<Collectable*>::iterator it = Garbage_collector::all.begin(); it != Garbage_collector::all.end(); ++it)
    {
        if((*it) != nullptr)
        {
            (*it) -> clean_used();
        }
    }
}

void Garbage_collector::mark()
{
    for(std::vector<Collectable*>::iterator it = root.begin(); it != root.end(); ++it)
    {
        if((*it) != nullptr)
        {
            (*it) -> mark_used();
        }
    }
}

std::vector<Collectable*> Garbage_collector::used_test(std::vector<Collectable*> vect)
{
    if(vect.empty()){return vect;}
    Collectable* last = vect.back();
    if(last != nullptr)
    {
        try {
            last -> check();
            if(!(last -> used))
            {
                delete last;
                vect.pop_back();
                return used_test(vect);
            }
            vect.pop_back();
            std::vector<Collectable*> vect_return = used_test(vect);
            vect_return.push_back(last);
            return vect_return;
        }
        catch(std::exception &e){ std::cout << "Check invalide" << std::endl; vect.pop_back(); return used_test(vect);}
    }
}

void Garbage_collector::sweep()
{
    all = used_test(all);
}

void Garbage_collector::add_to_root(Collectable* c)
{
    root.push_back(c);
}

void Garbage_collector::add_to_all(Collectable* c)
{
    all.push_back(c);
}

void Garbage_collector::remove_last_from_root()
{
    root.pop_back();
}
void Garbage_collector::clean_memory()
{
    //print_root();
    //print_all();
    //std::cout << "Cleaning Memory" << std::endl;
    clean();
    //std::cout << "Marking Reachables" << std::endl;
    mark();
    //std::cout << "Sweeping Unmarked" << std::endl;
    sweep();
    //print_root();
    //print_all();
    //std::cout << "Finished !" << std::endl;
}

void Garbage_collector::print_root()
{
    std::cout << "Root :" << std::endl;
    for(std::vector<Collectable*>::iterator it = root.begin(); it != root.end(); ++it)
    {
        (*it)->print();
        std::cout << std::endl;
    }
}
void Garbage_collector::print_all()
{
    std::cout << "All :" << std::endl;
    for(std::vector<Collectable*>::iterator it = all.begin(); it != all.end(); ++it)
    {
        (*it)->print();
        std::cout << std::endl;
    }
}
