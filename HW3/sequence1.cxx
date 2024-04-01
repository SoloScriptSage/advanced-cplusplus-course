#include "sequence1.h"

// _  _ _    ____ ___  _   _ ____ _    ____ _  _    _  _ _ ____ ____ _  _ _  _ _  _ 
// |  | |    |__| |  \  \_/  [__  |    |__| |  |    |__| | |__/ |    |__| |  | |_/  
//  \/  |___ |  | |__/   |   ___] |___ |  |  \/     |  | | |  \ |___ |  | |__| | \_ 
                                                                                 
namespace main_savitch_3
{
    sequence::sequence() : used(0), current_index(0) {}    
    void sequence::start() { current_index = 0; } 
    void sequence::advance() { if (is_item()) ++current_index; }
    void sequence::insert(const value_type& entry){
        if (used >= CAPACITY) return;
        if (!is_item()) current_index = 0;

        for (size_type i = used; i > current_index; --i) data[i] = data[i - 1];
        data[current_index] = entry;
        ++used;
    }

    void sequence::attach(const value_type& entry){
        if (used >= CAPACITY) return;
        if (!is_item()){
            data[used] = entry;
            current_index = used;
        }
        else{
            for (size_type i = used; i > current_index + 1; --i) data[i] = data[i - 1];
            data[current_index + 1] = entry;
            ++current_index;
        }

        ++used;
    }

    void sequence::remove_current(){
        if (!is_item()) return;
        for (size_type i=current_index; i<used-1; ++i) data[i] = data[i+1];
        --used;

        if (used==0)
            current_index = 0;
        else if (current_index==used)
            --current_index;
    }

    sequence::size_type sequence::size() const { return used; }
    bool sequence::is_item() const { return current_index < used; }
    sequence::value_type sequence::current() const {
        if (is_item()) return data[current_index];
        else return 0;
    }
}
