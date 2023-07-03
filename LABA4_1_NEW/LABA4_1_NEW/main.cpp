#include "SCREEN.hpp"
#include "CPU.hpp"
#include "SSD.hpp"
#include "HDD.hpp"
#include "DYNAMIC_ARRAY.hpp"


int main()
{
    SCREEN screen("202", 14,"800x960", 240);
    cout << screen;
    screen.set_date("2002");
    screen.set_permission("1440x1200");
    cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << screen;
    cout << endl << "----------------------------------"  << endl;
    
    CPU cpu("2023", "INTEGRAL", "INTEL", 9, 1200);
    cout << cpu;
    cpu.set_model("DMI");
    cpu.set_num_cores(8900);
    cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << cpu;
    cout << endl << "----------------------------------"  << endl;
    
    SSD ssd("2054", 8900, "INTEGRAL", 6788993, 4);
    cout << ssd;
    ssd.set_TBW(89289238);
    ssd.set_num_bytes(2);
    cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << ssd;
    cout << endl << "----------------------------------"  << endl;
    
    HDD hdd("2030", 780099, "INTEGRAL");
    cout << hdd;
    hdd.set_capacity(3);
    hdd.set_fabricator("RAF");
    cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << hdd;
    cout << endl << "----------------------------------"  << endl;
    cout << endl << "----------------------------------"  << endl;
    cout << endl << "----------------------------------"  << endl;
    cout << endl << "----------------------------------"  << endl;
    
    //DYNAMIC_ARRAY
    cout << endl << "~~~~~~~~~~~~~ARRAY~~~~~~~~~~~~~~~~" << endl;
    DYNAMIC_ARRAY reaccounting;
    reaccounting.add_object(&screen);
    cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    reaccounting.add_object(&cpu);
    cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    reaccounting.add_object(&ssd);
    reaccounting.print_obj();
    cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    reaccounting.remove_object(1);
    cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    reaccounting.print_obj();
    reaccounting.clear_array();
    reaccounting.print_obj();
    return 0;
}
